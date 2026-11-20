"""
Main Game Application Entry Point - Phase 16 Complete Lifecycle Edition.
The Battle Cats Rebuilt - Desktop Executable Game.
Complete Game Loop: Title -> Cat Base -> Upgrade / Formation / Stage Select -> Battle -> Settlement -> Cat Base.
Supports both Interactive Windowed Mode and Headless Automated Mode.
"""

import os
import sys
import argparse
import pygame

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.environ["TEMP"] = r"E:\rea\temp"
os.environ["TMP"] = r"E:\rea\temp"

from game_project.core.constants import (
    SCREEN_WIDTH, SCREEN_HEIGHT, SIMULATION_FPS, TEAM_CAT, TEAM_ENEMY
)
from game_project.core.save_manager import SaveManager
from game_project.core.official_data_parser import OfficialDataParser
from game_project.core.custom_unit_loader import CustomUnitLoader
from game_project.simulation.battle_sim import BattleSimulation
from game_project.render.camera import Camera2D
from game_project.render.renderer import BattleRenderer
from game_project.ui.main_menu import MainMenuUI
from game_project.ui.cat_base import CatBaseUI
from game_project.ui.power_up_menu import PowerUpMenuUI
from game_project.ui.formation_menu import FormationMenuUI
from game_project.ui.stage_select import StageSelectUI
from game_project.ui.deploy_bar import DeployBarUI
from game_project.ui.hud import BattleHUD
from game_project.ui.settlement_dialog import SettlementDialog
from game_project.ui.online_lobby import OnlineLobbyOverlay
from game_project.network.pvp_net import PvPNetworkSession
from game_project.audio.sound_manager import SoundManager

STATE_TITLE = "title"
STATE_MENU = "menu" # Alias for title
STATE_CAT_BASE = "cat_base"
STATE_POWER_UP = "power_up"
STATE_FORMATION = "formation"
STATE_STAGE_SELECT = "stage_select"
STATE_BATTLE = "battle"

def run_game(
    headless: bool = False,
    auto_play: bool = False,
    max_frames: int = 0,
    capture_screenshot: str = "",
    start_state: str = STATE_TITLE,
    debug: bool = False,
    pvp_mode: bool = False,
    host_port: int = 0,
    connect_addr: str = "",
):
    if headless:
        os.environ["SDL_VIDEODRIVER"] = "dummy"

    pygame.init()
    pygame.font.init()
    try:
        pygame.scrap.init()
    except Exception:
        pass

    if headless:
        screen = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT))
    else:
        screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
        pygame.display.set_caption("貓咪大戰爭 (The Battle Cats) - 重構完整版 v15.6.1")

    clock = pygame.time.Clock()
    save_mgr = SaveManager()
    sound_mgr = SoundManager.get_instance()
    parser = OfficialDataParser.get_instance()

    # Load all user-created custom characters from custom_units/
    custom_unit_keys = CustomUnitLoader.load_all()
    if custom_unit_keys:
        print(f"[*] Loaded {len(custom_unit_keys)} custom units: {custom_unit_keys}")

    # UI Screens
    main_menu = MainMenuUI(save_mgr)
    cat_base = CatBaseUI(save_mgr)
    power_up = PowerUpMenuUI(save_mgr)
    formation = FormationMenuUI(save_mgr)
    stage_select = StageSelectUI(save_mgr)
    online_lobby = OnlineLobbyOverlay()

    # Initialize Battle components
    default_stage = parser.get_stage(1).to_dict()
    current_stage_id = 1
    p1_deck = list(save_mgr.get_deck())
    p2_deck = list(save_mgr.get_deck())
    # Include loaded custom units in the second page of P1/P2 decks if space allows
    for ck in custom_unit_keys:
        if ck not in p1_deck and len(p1_deck) < 10:
            p1_deck.append(ck)
        if ck not in p2_deck and len(p2_deck) < 10:
            p2_deck.append(ck)

    sim = BattleSimulation(
        stage_config=default_stage,
        deck=p1_deck,
        cat_levels=save_mgr.data.get("cat_levels", {}),
        base_levels=save_mgr.data.get("base_levels", {}),
        pvp_mode=pvp_mode,
        p2_deck=p2_deck,
        p2_levels=save_mgr.data.get("cat_levels", {}),
        p2_base_levels=save_mgr.data.get("base_levels", {}),
        treasures=save_mgr.get_treasure_config(),
        cannon_type=save_mgr.get_cannon_type(),
    )
    camera = Camera2D(world_width=sim.battlefield_length)
    renderer = BattleRenderer(screen, camera)
    if debug:
        renderer.debug_mode = True
    deploy_bar = DeployBarUI()
    hud = BattleHUD()
    settlement_dialog = SettlementDialog()

    # Online Networked PvP Session state
    net_session = None
    net_battle_initialized = False
    local_team = TEAM_CAT

    def start_online_session(role: str, ip: str = "0.0.0.0", port: int = 7777):
        nonlocal net_session, net_battle_initialized, local_team
        if net_session is not None:
            net_session.close()
        cur_deck = list(save_mgr.get_deck())
        for ck in CustomUnitLoader.LOADED_RAW_SPECS.keys():
            if ck not in cur_deck and len(cur_deck) < 10:
                cur_deck.append(ck)
        net_session = PvPNetworkSession(
            role=role,
            host_ip=ip,
            port=port,
            stage_config=default_stage,
            local_deck=cur_deck,
            local_cat_levels=save_mgr.data.get("cat_levels", {}),
            local_base_levels=save_mgr.data.get("base_levels", {}),
        )
        net_battle_initialized = False
        local_team = net_session.local_team
        net_session.start()
        print(f"[*] Started Online PvP ({role.upper()}) on {ip}:{port}")

    if host_port > 0:
        online_lobby.visible = True
        start_online_session("host", "0.0.0.0", host_port)
    elif connect_addr:
        online_lobby.visible = True
        online_lobby.ip_input = connect_addr
        act = online_lobby._parse_join_action()
        start_online_session("client", act["host"], act["port"])

    if start_state in (STATE_MENU, STATE_TITLE):
        current_state = STATE_BATTLE if (auto_play or pvp_mode) else STATE_TITLE
    else:
        current_state = start_state

    # Start appropriate BGM for initial state
    if not headless:
        if current_state == STATE_BATTLE:
            sound_mgr.play_bgm("battle")
        else:
            sound_mgr.play_bgm("menu")

    running = True
    frames_run = 0
    stage_reward_awarded = False
    current_stage_xp = 0

    print(f"[*] Game initialized! Mode: {'Headless' if headless else 'Windowed'}, State: {current_state}, AutoPlay: {auto_play}")

    while running:
        frames_run += 1

        # Automatically transition to synchronized Online PvP battle as soon as handshake completes
        if net_session is not None and net_session.state == "READY" and not net_battle_initialized:
            sim = net_session.create_synchronized_simulation()
            local_team = net_session.local_team
            camera = Camera2D(world_width=sim.battlefield_length)
            if local_team == TEAM_ENEMY:
                camera.set_target_x(700)
                camera.offset_x = 0.0
            renderer = BattleRenderer(screen, camera)
            if debug:
                renderer.debug_mode = True
            online_lobby.visible = False
            current_state = STATE_BATTLE
            net_battle_initialized = True
            stage_reward_awarded = False
            if not headless:
                sound_mgr.play_bgm("battle")
            print(f"[+] Online PvP Synchronized Battle Started! Role={net_session.role.upper()}, Team={local_team}, Seed={net_session.rng_seed}")

        is_online_pvp = (net_session is not None and net_session.state == "READY")
        action_cb = net_session.queue_local_action if is_online_pvp else None

        # ==========================================
        # 1. EVENT HANDLING PER STATE
        # ==========================================
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if online_lobby.visible:
                    lobby_act = online_lobby.handle_keydown(event)
                    if lobby_act:
                        if lobby_act.get("action") == "host":
                            start_online_session("host", "0.0.0.0", lobby_act.get("port", 7777))
                        elif lobby_act.get("action") == "connect":
                            start_online_session("client", lobby_act["host"], lobby_act["port"])
                    continue

                if event.key == pygame.K_n:
                    online_lobby.toggle()
                    continue

                if event.key == pygame.K_ESCAPE:
                    if current_state == STATE_BATTLE:
                        if net_session is not None:
                            net_session.close()
                            net_session = None
                            net_battle_initialized = False
                            local_team = TEAM_CAT
                        current_state = STATE_STAGE_SELECT
                        sound_mgr.play_bgm("menu")
                    elif current_state == STATE_STAGE_SELECT:
                        current_state = STATE_CAT_BASE
                    elif current_state in (STATE_POWER_UP, STATE_FORMATION):
                        current_state = STATE_CAT_BASE
                    elif current_state == STATE_CAT_BASE:
                        current_state = STATE_TITLE
                    else:
                        running = False

                elif current_state == STATE_BATTLE:
                    if event.key in (pygame.K_F1, pygame.K_d):
                        renderer.toggle_debug_mode()
                    elif event.key == pygame.K_p and not is_online_pvp:
                        pvp_mode = not sim.pvp_mode
                        print(f"[*] 2-Player PvP Mode toggled: {pvp_mode}")
                        sim = BattleSimulation(
                            stage_config=sim.stage_config,
                            deck=p1_deck,
                            cat_levels=save_mgr.data.get("cat_levels", {}),
                            base_levels=save_mgr.data.get("base_levels", {}),
                            pvp_mode=pvp_mode,
                            p2_deck=p2_deck,
                            p2_levels=save_mgr.data.get("cat_levels", {}),
                            p2_base_levels=save_mgr.data.get("base_levels", {}),
                            treasures=save_mgr.get_treasure_config(),
                            cannon_type=save_mgr.get_cannon_type(),
                        )
                        stage_reward_awarded = False
                    elif event.key == pygame.K_r and not is_online_pvp:
                        print("[*] Battle restarted!")
                        sim = BattleSimulation(
                            stage_config=sim.stage_config,
                            deck=p1_deck,
                            cat_levels=save_mgr.data.get("cat_levels", {}),
                            base_levels=save_mgr.data.get("base_levels", {}),
                            pvp_mode=sim.pvp_mode,
                            p2_deck=p2_deck,
                            p2_levels=save_mgr.data.get("cat_levels", {}),
                            p2_base_levels=save_mgr.data.get("base_levels", {}),
                            treasures=save_mgr.get_treasure_config(),
                            cannon_type=save_mgr.get_cannon_type(),
                        )
                        stage_reward_awarded = False
                    elif event.key == pygame.K_u:
                        if is_online_pvp:
                            net_session.queue_local_action("UPGRADE_WORKER", None)
                        else:
                            sim.wallets[local_team].upgrade_worker()
                    elif event.key == pygame.K_SPACE:
                        if is_online_pvp:
                            net_session.queue_local_action("FIRE_CANNON", None)
                        else:
                            sim.fire_cannon(local_team)
                    elif event.key == pygame.K_TAB:
                        deploy_bar.current_page = 1 - deploy_bar.current_page
                    elif event.key in (pygame.K_1, pygame.K_KP1):
                        slot_i = deploy_bar.current_page * 5 + 0
                        if is_online_pvp:
                            net_session.queue_local_action("SPAWN_UNIT", slot_i)
                        else:
                            sim.deploy_unit(local_team, slot_i)
                    elif event.key in (pygame.K_2, pygame.K_KP2):
                        slot_i = deploy_bar.current_page * 5 + 1
                        if is_online_pvp:
                            net_session.queue_local_action("SPAWN_UNIT", slot_i)
                        else:
                            sim.deploy_unit(local_team, slot_i)
                    elif event.key in (pygame.K_3, pygame.K_KP3):
                        slot_i = deploy_bar.current_page * 5 + 2
                        if is_online_pvp:
                            net_session.queue_local_action("SPAWN_UNIT", slot_i)
                        else:
                            sim.deploy_unit(local_team, slot_i)
                    elif event.key in (pygame.K_4, pygame.K_KP4):
                        slot_i = deploy_bar.current_page * 5 + 3
                        if is_online_pvp:
                            net_session.queue_local_action("SPAWN_UNIT", slot_i)
                        else:
                            sim.deploy_unit(local_team, slot_i)
                    elif event.key in (pygame.K_5, pygame.K_KP5):
                        slot_i = deploy_bar.current_page * 5 + 4
                        if is_online_pvp:
                            net_session.queue_local_action("SPAWN_UNIT", slot_i)
                        else:
                            sim.deploy_unit(local_team, slot_i)
                    # Local 2-Player Hotseat Controls (only when not in Online PvP)
                    elif event.key == pygame.K_y and sim.pvp_mode and not is_online_pvp:
                        sim.upgrade_p2_worker()
                    elif event.key == pygame.K_RETURN and sim.pvp_mode and not is_online_pvp:
                        sim.fire_p2_cannon()
                    elif event.key in (pygame.K_q, pygame.K_6, pygame.K_KP6) and sim.pvp_mode and not is_online_pvp:
                        sim.spawn_p2_unit(0)
                    elif event.key in (pygame.K_w, pygame.K_7, pygame.K_KP7) and sim.pvp_mode and not is_online_pvp:
                        sim.spawn_p2_unit(1)
                    elif event.key in (pygame.K_e, pygame.K_8, pygame.K_KP8) and sim.pvp_mode and not is_online_pvp:
                        sim.spawn_p2_unit(2)
                    elif event.key in (pygame.K_9, pygame.K_KP9) and sim.pvp_mode and not is_online_pvp:
                        sim.spawn_p2_unit(3)
                    elif event.key in (pygame.K_t, pygame.K_0, pygame.K_KP0) and sim.pvp_mode and not is_online_pvp:
                        sim.spawn_p2_unit(4)
                    # Quick Custom Character Spawning on Local Team (F2) or Opponent Team (F3)
                    elif event.key == pygame.K_F2 and custom_unit_keys:
                        ck = custom_unit_keys[frames_run % len(custom_unit_keys)]
                        if is_online_pvp:
                            net_session.queue_local_action("SPAWN_CUSTOM", ck)
                        else:
                            sim.spawn_custom_unit(ck, team=local_team)
                    elif event.key == pygame.K_F3 and custom_unit_keys and not is_online_pvp:
                        sim.spawn_custom_unit(custom_unit_keys[frames_run % len(custom_unit_keys)], team=TEAM_ENEMY)

            elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                mouse_pos = event.pos
                if online_lobby.visible:
                    lobby_act = online_lobby.handle_click(mouse_pos)
                    if lobby_act:
                        if lobby_act.get("action") == "host":
                            start_online_session("host", "0.0.0.0", lobby_act.get("port", 7777))
                        elif lobby_act.get("action") == "connect":
                            start_online_session("client", lobby_act["host"], lobby_act["port"])
                    continue

                if current_state in (STATE_TITLE, STATE_MENU):
                    act = main_menu.handle_click(mouse_pos)
                    if act == "start":
                        current_state = STATE_CAT_BASE
                    elif act == "exit":
                        running = False

                elif current_state == STATE_CAT_BASE:
                    act = cat_base.handle_click(mouse_pos)
                    if act == "battle_prep":
                        current_state = STATE_STAGE_SELECT
                    elif act == "upgrade":
                        current_state = STATE_POWER_UP
                    elif act == "formation":
                        current_state = STATE_FORMATION
                    elif act == "online_pvp":
                        online_lobby.toggle()
                    elif act == "title":
                        current_state = STATE_TITLE

                elif current_state == STATE_POWER_UP:
                    act = power_up.handle_click(mouse_pos)
                    if act == "back":
                        current_state = STATE_CAT_BASE

                elif current_state == STATE_FORMATION:
                    act = formation.handle_click(mouse_pos)
                    if act == "back":
                        current_state = STATE_CAT_BASE

                elif current_state == STATE_STAGE_SELECT:
                    res = stage_select.handle_click(mouse_pos)
                    if res:
                        if res.get("action") == "back":
                            current_state = STATE_CAT_BASE
                        elif res.get("action") == "play":
                            stg_cfg = res["stage_config"]
                            current_stage_id = stg_cfg.get("stage_id", res.get("stage_id", 1))
                            local_team = TEAM_CAT
                            sim = BattleSimulation(
                                stage_config=stg_cfg,
                                deck=save_mgr.get_deck(),
                                cat_levels=save_mgr.data.get("cat_levels", {}),
                                base_levels=save_mgr.data.get("base_levels", {}),
                                treasures=save_mgr.get_treasure_config(),
                                cannon_type=save_mgr.get_cannon_type(),
                            )
                            camera = Camera2D(world_width=sim.battlefield_length)
                            renderer = BattleRenderer(screen, camera)
                            stage_reward_awarded = False
                            current_stage_xp = 500 + current_stage_id * 50
                            current_state = STATE_BATTLE
                            sound_mgr.play_bgm("battle")

                elif current_state == STATE_BATTLE:
                    if sim.game_over:
                        action = settlement_dialog.handle_click(mouse_pos)
                        if action == "restart":
                            sim = BattleSimulation(
                                stage_config=sim.stage_config,
                                deck=save_mgr.get_deck(),
                                cat_levels=save_mgr.data.get("cat_levels", {}),
                                base_levels=save_mgr.data.get("base_levels", {}),
                                treasures=save_mgr.get_treasure_config(),
                                cannon_type=save_mgr.get_cannon_type(),
                            )
                            stage_reward_awarded = False
                            sound_mgr.play_bgm("battle")
                        elif action == "next_stage":
                            next_id = min(48, current_stage_id + 1)
                            stg = parser.get_stage(next_id)
                            if stg:
                                current_stage_id = next_id
                                sim = BattleSimulation(
                                    stage_config=stg.to_dict(),
                                    deck=save_mgr.get_deck(),
                                    cat_levels=save_mgr.data.get("cat_levels", {}),
                                    base_levels=save_mgr.data.get("base_levels", {}),
                                    treasures=save_mgr.get_treasure_config(),
                                    cannon_type=save_mgr.get_cannon_type(),
                                )
                                camera = Camera2D(world_width=sim.battlefield_length)
                                renderer = BattleRenderer(screen, camera)
                                stage_reward_awarded = False
                                current_stage_xp = 500 + current_stage_id * 50
                                sound_mgr.play_bgm("battle")
                        elif action in ("cat_base", "stage_select"):
                            if net_session is not None:
                                net_session.close()
                                net_session = None
                                net_battle_initialized = False
                                local_team = TEAM_CAT
                            current_state = STATE_CAT_BASE
                            sound_mgr.play_bgm("menu")
                    else:
                        handled = deploy_bar.handle_click(mouse_pos, sim, team=local_team, action_callback=action_cb)
                        if not handled:
                            camera.handle_mouse_down(mouse_pos[0])

            elif event.type == pygame.MOUSEMOTION and current_state == STATE_BATTLE and not online_lobby.visible:
                camera.handle_mouse_move(event.pos[0])
            elif event.type == pygame.MOUSEBUTTONUP and event.button == 1 and current_state == STATE_BATTLE:
                camera.handle_mouse_up()

        # Keyboard camera panning & auto-follow during battle
        if current_state == STATE_BATTLE and not online_lobby.visible:
            keys = pygame.key.get_pressed()
            manual_pan = False
            if keys[pygame.K_LEFT] or keys[pygame.K_a]:
                camera.pan(-15)
                manual_pan = True
            if keys[pygame.K_RIGHT] or keys[pygame.K_d]:
                camera.pan(15)
                manual_pan = True

            # Smoothly focus on frontline combat when player is not actively dragging/panning
            if not manual_pan and not camera.is_dragging and not sim.game_over:
                active_my = [u for u in sim.units[local_team] if u and u.is_alive and u.slot != 0]
                if active_my:
                    if local_team == TEAM_CAT:
                        lead_x = min(u.pos_x for u in active_my)
                        camera.set_target_x(lead_x - 80)
                    else:
                        lead_x = max(u.pos_x for u in active_my)
                        camera.set_target_x(lead_x + 80)

        # ==========================================
        # 2. STATE LOGIC UPDATE & RENDERING
        # ==========================================
        if current_state in (STATE_TITLE, STATE_MENU):
            main_menu.render(screen, frames_run)

        elif current_state == STATE_CAT_BASE:
            cat_base.render(screen, frames_run)

        elif current_state == STATE_POWER_UP:
            power_up.render(screen)

        elif current_state == STATE_FORMATION:
            formation.render(screen)

        elif current_state == STATE_STAGE_SELECT:
            stage_select.render(screen)

        elif current_state == STATE_BATTLE:
            # AutoPlay AI Bot for testing
            if auto_play and not sim.game_over and not is_online_pvp:
                if sim.wallet.level < 4 and sim.wallet.money > (sim.wallet.upgrade_cost or 9999):
                    sim.wallet.upgrade_worker()
                for d_idx in range(len(sim.deployer.deck_keys)):
                    if sim.deployer.can_deploy(d_idx, sim.wallet.money, has_free_slot=True):
                        sim.spawn_cat(d_idx)
                if sim.pvp_mode:
                    if sim.p2_wallet.level < 4 and sim.p2_wallet.money > (sim.p2_wallet.upgrade_cost or 9999):
                        sim.upgrade_p2_worker()
                    for d_idx in range(len(sim.p2_deployer.deck_keys)):
                        if sim.p2_deployer.can_deploy(d_idx, sim.p2_wallet.money, has_free_slot=True):
                            sim.spawn_p2_unit(d_idx)

            if is_online_pvp:
                net_session.step_lockstep(sim, wait_timeout=0.04)
            else:
                sim.step()

            # Record victory in save file and award stage XP
            if sim.game_over and sim.winner == local_team and not stage_reward_awarded:
                current_stage_xp = 500 + current_stage_id * 50
                save_mgr.add_xp(current_stage_xp)
                save_mgr.mark_stage_cleared(current_stage_id)
                stage_reward_awarded = True
                print(f"[+] Stage {current_stage_id} Victory! Awarded {current_stage_xp} XP. Total XP: {save_mgr.xp}")

            renderer.process_visual_events(sim.consume_visual_events())
            renderer.render(sim)
            deploy_bar.render(screen, sim, team=local_team)
            net_status_str = net_session.get_hud_status() if net_session is not None else ""
            hud.render(screen, sim, local_team=local_team, net_status=net_status_str)
            if sim.game_over:
                settlement_dialog.render(screen, sim, xp_gained=current_stage_xp)

        # Render Online Lobby overlay if open
        if online_lobby.visible:
            online_lobby.render(screen, net_session=net_session, custom_unit_count=len(CustomUnitLoader.LOADED_RAW_SPECS))

        if not headless:
            pygame.display.flip()
            clock.tick(SIMULATION_FPS)

        # Termination check for testing
        if max_frames > 0 and frames_run >= max_frames:
            break

    if net_session is not None:
        net_session.close()

    if capture_screenshot:
        os.makedirs(os.path.dirname(os.path.abspath(capture_screenshot)), exist_ok=True)
        pygame.image.save(screen, capture_screenshot)
        print(f"[+] Final screenshot saved to: {capture_screenshot}")

    pygame.quit()
    print(f"[*] Game lifecycle finished at frame {frames_run}.")
    return sim

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="The Battle Cats Rebuilt Executable")
    parser.add_argument("--headless", action="store_true", help="Run in headless mode without UI window")
    parser.add_argument("--auto-play", action="store_true", help="Enable AI player auto-spawning for testing")
    parser.add_argument("--frames", "--max-frames", dest="frames", type=int, default=0, help="Max frames to simulate before exiting")
    parser.add_argument("--screenshot", type=str, default="", help="Path to save final frame screenshot")
    parser.add_argument("--state", type=str, default="title", choices=["title", "menu", "cat_base", "power_up", "formation", "stage_select", "battle"], help="Initial state")
    parser.add_argument("--debug", action="store_true", help="Start with debug overlay enabled")
    parser.add_argument("--pvp", action="store_true", help="Start directly in 2-Player Symmetric PvP battle mode")
    parser.add_argument("--host", nargs="?", const=7777, default=0, type=int, help="Host an Online Networked PvP room on TCP port (default 7777)")
    parser.add_argument("--connect", type=str, default="", help="Connect to an Online Networked PvP Host at <ip:port>")
    args = parser.parse_args()

    run_game(
        headless=args.headless,
        auto_play=args.auto_play,
        max_frames=args.frames,
        capture_screenshot=args.screenshot,
        start_state=args.state,
        debug=args.debug,
        pvp_mode=args.pvp,
        host_port=args.host,
        connect_addr=args.connect,
    )
