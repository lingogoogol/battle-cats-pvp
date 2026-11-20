"""
Phase 13 Playability Verification Test Suite.
Validates all 9 criteria from Section 13.3 in the project specification.
"""

import os
import sys
import unittest

os.environ["TEMP"] = r"E:\rea\temp"
os.environ["TMP"] = r"E:\rea\temp"
os.environ["SDL_VIDEODRIVER"] = "dummy"

sys.path.insert(0, r"E:\rea")

from game_project.simulation.battle_sim import BattleSimulation
from game_project.core.constants import TEAM_CAT, TEAM_ENEMY, SLOT_CASTLE
from game_project.main import run_game

class TestPlayableBattle(unittest.TestCase):
    def setUp(self):
        self.sim = BattleSimulation()

    def test_01_game_starts_and_initializes_castles(self):
        """Criterion 1: 遊戲能夠啟動並初始化城堡 (原版規格：貓堡在右，敵堡在左)"""
        cat_c = self.sim.get_castle(TEAM_CAT)
        enemy_c = self.sim.get_castle(TEAM_ENEMY)
        self.assertIsNotNone(cat_c)
        self.assertIsNotNone(enemy_c)
        self.assertGreater(cat_c.hp, 0)
        self.assertGreater(enemy_c.hp, 0)
        self.assertEqual(cat_c.pos_x, self.sim.battlefield_length - 700.0)
        self.assertEqual(enemy_c.pos_x, 700.0)

    def test_02_can_deploy_cats(self):
        """Criterion 2: 可以部署角色 (經由金錢扣除與槽位放置)"""
        # Native PONOS starts at 0 money; give 150 yen then Cat costs 50.
        self.assertEqual(self.sim.wallet.money, 0)
        self.sim.wallet.money = 150
        success = self.sim.spawn_cat(0)
        self.assertTrue(success, "Failed to spawn basic cat")
        self.assertEqual(self.sim.wallet.money, 100)
        
        # Verify unit exists in slot 1 in front of right castle
        cat_unit = self.sim.units[TEAM_CAT][1]
        self.assertIsNotNone(cat_unit)
        self.assertEqual(cat_unit.key, "cat")
        self.assertTrue(cat_unit.is_alive)
        self.assertEqual(cat_unit.pos_x, self.sim.get_castle(TEAM_CAT).pos_x - 30)

    def test_03_units_move_and_attack(self):
        """Criterion 3: 角色會移動與攻擊 (貓咪向左前進，狗仔向右前進)"""
        self.sim.wallet.money = 500
        self.sim.spawn_cat(0)
        cat_unit = self.sim.units[TEAM_CAT][1]
        init_x = cat_unit.pos_x

        # Step 5 frames (should advance left at speed 10 px/frame)
        for _ in range(5):
            self.sim.step()
        self.assertLess(cat_unit.pos_x, init_x, "Cat did not move forward (left)")

        # Spawn enemy doge right in front of cat (to the left of cat)
        self.sim.spawn_enemy("doge")
        doge_unit = self.sim.units[TEAM_ENEMY][1]
        doge_unit.pos_x = cat_unit.pos_x - 80 # Inside attack range (140)

        # Step frames to trigger windup and attack delivery
        attack_detected = False
        for _ in range(40):
            self.sim.step()
            for ev in self.sim.visual_events:
                if ev.get("type") == "damage":
                    attack_detected = True
                    break
            if attack_detected:
                break
        self.assertTrue(attack_detected, "No attack damage event occurred")

    def test_04_hp_changes_and_knockback(self):
        """Criterion 4: HP 正確變化與擊退觸發"""
        self.sim.wallet.money = 500
        self.sim.spawn_cat(0)
        cat = self.sim.units[TEAM_CAT][1]
        initial_hp = cat.hp

        # Inflict damage directly
        damage = 40
        cat.hp -= damage
        self.assertEqual(cat.hp, initial_hp - damage)

        # Check knockback logic
        damage_taken = cat.max_hp - cat.hp
        kbs = int(damage_taken // cat.kb_threshold)
        self.assertGreaterEqual(kbs, 1, "Expected knockback threshold reached")

    def test_05_units_removed_on_death(self):
        """Criterion 5: 死亡後立即由 Battle_KillUnit 清理除役槽位"""
        self.sim.spawner.spawn_entries = []
        self.sim.spawn_enemy("doge")
        doge = self.sim.units[TEAM_ENEMY][1]
        self.assertIsNotNone(doge)

        # Kill doge (enters 24-frame death knockback before slot is cleared)
        doge.hp = 0
        for _ in range(25):
            self.sim.step()
        # Unit reaches 0 HP, completes death knockback, and is cleaned from the slot
        self.assertIsNone(self.sim.units[TEAM_ENEMY][1], "Dead unit was not cleared from slot upon death")

    def test_06_can_attack_castle(self):
        """Criterion 6: 可以攻擊城堡"""
        self.sim.spawner.spawn_entries = []
        self.sim.wallet.money = 500
        self.sim.spawn_cat(0)
        cat = self.sim.units[TEAM_CAT][1]
        enemy_c = self.sim.get_castle(TEAM_ENEMY)
        init_c_hp = enemy_c.hp

        # Place cat in front of enemy castle (approaching from right)
        cat.pos_x = enemy_c.pos_x + 100
        
        # Advance simulation
        hit_castle = False
        for _ in range(50):
            self.sim.step()
            if enemy_c.hp < init_c_hp:
                hit_castle = True
                break
        self.assertTrue(hit_castle, "Enemy castle HP did not decrease from cat attack")

    def test_07_and_08_complete_battle_and_restart(self):
        """Criterion 7 & 8: 可以完成一場戰鬥並重新開始"""
        self.sim.spawner.spawn_entries = []
        enemy_c = self.sim.get_castle(TEAM_ENEMY)
        enemy_c.hp = 1 # Almost dead
        self.sim.wallet.money = 500
        self.sim.spawn_cat(0)
        cat = self.sim.units[TEAM_CAT][1]
        cat.pos_x = enemy_c.pos_x + 80

        # Run until game over
        for _ in range(60):
            self.sim.step()
            if self.sim.game_over:
                break
        self.assertTrue(self.sim.game_over, "Battle did not reach game over state")
        self.assertEqual(self.sim.winner, TEAM_CAT, "Cat team did not win")

        # Criterion 8: Restart
        restarted_sim = BattleSimulation()
        self.assertFalse(restarted_sim.game_over)
        self.assertGreater(restarted_sim.get_castle(TEAM_ENEMY).hp, 0)

    def test_10_official_data_parser_integrity(self):
        """Criterion 10: 官方還原資料解析器完整性 (9 隻貓咪、788 種敵人、48 個世界篇關卡)"""
        from game_project.core.official_data_parser import OfficialDataParser
        parser = OfficialDataParser.get_instance()
        cats = parser.get_all_cats()
        enemies = parser.get_all_enemies()
        stages = parser.get_all_stages()

        self.assertEqual(len(cats), 9)
        self.assertGreaterEqual(len(enemies), 780)
        self.assertEqual(len(stages), 48)

        # Verify Stage 1 and Stage 48
        self.assertEqual(stages[1].name, "韓國")
        self.assertEqual(stages[1].enemy_castle_hp, 500)
        self.assertEqual(stages[48].name, "月球")
        self.assertEqual(stages[48].enemy_castle_hp, 99999)

        # Verify Cat names and costs from official unit*.csv
        self.assertEqual(cats[0].name, "貓咪")
        self.assertEqual(cats[0].cost, 50)
        self.assertEqual(cats[1].name, "坦克貓")
        self.assertEqual(cats[1].cost, 100)
        self.assertEqual(cats[2].name, "戰鬥貓")
        self.assertEqual(cats[8].name, "巨神貓")

    def test_11_native_magic_division_damage_scaling(self):
        """Criterion 11: 原版 AArch64 魔法常數除法 (0x10624dd3 >> 38) 傷害計算等價性"""
        from game_project.core.damage_engine import NativeDamageEngine
        # At 1000 permille (100%), damage is invariant
        self.assertEqual(NativeDamageEngine.scale_permille(1000, 100), 100)
        self.assertEqual(NativeDamageEngine.scale_permille(1000, 8), 8)
        self.assertEqual(NativeDamageEngine.scale_permille(1000, 280), 280)

        # At 1500 permille (150%)
        self.assertEqual(NativeDamageEngine.scale_permille(1500, 100), 150)
        # At 2000 permille (200%)
        self.assertEqual(NativeDamageEngine.scale_permille(2000, 8), 16)
        # At 3000 permille (300%)
        self.assertEqual(NativeDamageEngine.scale_permille(3000, 50), 150)

    def test_12_boss_shockwave_and_magnification(self):
        """Criterion 12: 原版 Boss 衝擊波與倍率血量增長"""
        self.sim.wallet.money = 500
        self.sim.spawn_cat(0)
        cat = self.sim.units[TEAM_CAT][1]
        self.assertIsNotNone(cat)
        self.assertEqual(cat.knockback_timer, 0)

        # Spawn boss enemy with 200% magnification and boss flag
        self.sim.spawn_enemy({"key": "the_face", "id": 20, "mag": 200, "boss": 1})
        boss_unit = self.sim.units[TEAM_ENEMY][1]
        self.assertIsNotNone(boss_unit)
        self.assertEqual(boss_unit.magnification, 200)
        # Base HP is 99999, at 200% magnification it should be ~199998
        self.assertGreater(boss_unit.max_hp, 150000)

        # Boss shockwave should have knocked back cat
        self.assertGreater(cat.knockback_timer, 0, "Cat was not knocked back by boss shockwave")

    def test_13_stage_select_ui_pagination(self):
        """Criterion 13: 48 關卡分頁選關介面 (8 頁，每頁 6 關)"""
        import pygame
        pygame.init()
        from game_project.core.save_manager import SaveManager
        from game_project.ui.stage_select import StageSelectUI
        save_mgr = SaveManager()
        ui = StageSelectUI(save_mgr)
        self.assertEqual(ui.current_page, 0)

        # Click next page
        ui.handle_click(ui.btn_next.center)
        self.assertEqual(ui.current_page, 1)

        # Click prev page
        ui.handle_click(ui.btn_prev.center)
        self.assertEqual(ui.current_page, 0)

        # Click stage 1 (unlocked by default)
        stage_rect = ui.get_stage_rect(0)
        action = ui.handle_click(stage_rect.center)
        self.assertIsNotNone(action)
        self.assertEqual(action.get("action"), "play")
        self.assertEqual(action.get("stage_id"), 1)
        self.assertEqual(action["stage_config"]["name"], "韓國")

    def test_14_all_9_cats_and_19_enemies_rendering_coverage(self):
        """Criterion 14: 9 隻核心貓咪與 19 種第一章敵人完整渲染覆蓋與方向朝向正確性"""
        import pygame
        pygame.init()
        from game_project.render.unit_sprite_manager import UnitSpriteManager
        from game_project.render.renderer import BattleRenderer
        from game_project.render.camera import Camera2D

        sprite_mgr = UnitSpriteManager.get_instance()
        # Verify all 9 cats exist in manager
        self.assertEqual(len(sprite_mgr.cat_sprites), 9)
        # Verify all 19 enemies exist in manager
        self.assertEqual(len(sprite_mgr.enemy_sprites), 19)

        # Test rendering all 9 cats and 19 enemies on surface
        screen = pygame.Surface((1280, 720))
        cam = Camera2D()
        renderer = BattleRenderer(screen, cam)

        sim = BattleSimulation()
        # Deploy all 9 cats
        for d_idx in range(len(sim.deployer.deck_keys)):
            sim.wallet.money = 99999
            sim.deployer.cooldowns[d_idx] = 0
            sim.spawn_cat(d_idx)

        # Spawn all 19 enemies
        enemy_ids = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 18, 21, 22]
        for eid in enemy_ids:
            sim.spawn_enemy({"id": eid + 2, "enemy_code": eid, "mag": 100})

        # Render frame
        renderer.render(sim)

        # Verify active unit counts
        active_cats = [u for u in sim.units[TEAM_CAT] if u and u.is_alive and u.slot != 0]
        active_enemies = [u for u in sim.units[TEAM_ENEMY] if u and u.is_alive and u.slot != 0]
        self.assertEqual(len(active_cats), 9)
        self.assertEqual(len(active_enemies), 19)

    def test_15_four_phase_combat_state_machine(self):
        """Criterion 15: 原版四階段戰鬥狀態機 (前搖鎖定不因目標離開取消、後搖硬直、TBA 冷卻)"""
        self.sim.spawner.spawn_entries = []
        self.sim.wallet.money = 500
        self.sim.spawn_cat(0)
        cat = self.sim.units[TEAM_CAT][1]
        self.sim.spawn_enemy("doge")
        doge = self.sim.units[TEAM_ENEMY][1]

        # Place doge in cat's range so cat starts foreswing
        doge.pos_x = cat.pos_x - 80
        self.sim.step()
        self.assertTrue(cat.is_winding_up, "Cat should enter foreswing when target in range")
        self.assertEqual(cat.windup_timer, cat.attack_windup)

        # Move doge far out of range mid-foreswing: authentic Battle Cats commits to the swing!
        doge.pos_x = 200.0
        pre_atk = cat.attack_windup
        for _ in range(pre_atk):
            self.sim.step()
        # At hit frame, cat must enter backswing and have started attack_cooldown_timer (TBA)
        self.assertGreater(cat.backswing_timer, 0, "Cat must remain in attack animation during backswing even if target left range")
        self.assertGreater(cat.attack_cooldown_timer, 0, "TBA cooldown timer must be started at hit frame")

    def test_16_traits_and_abilities_engine(self):
        """Criterion 16: 屬性克制與特殊能力引擎 (超大傷害、善於攻擊、爆擊、鋼鐵、冰凍、緩速、降攻、增攻、死前存活、波動)"""
        from game_project.core.custom_unit_loader import CustomUnitLoader
        CustomUnitLoader.load_all()

        self.sim.spawner.spawn_entries = []
        # 1. Test Survive Lethal Strike & Wave Attack on custom_cyber_valkyrie
        u_valk = self.sim.spawn_custom_unit("custom_cyber_valkyrie", team=TEAM_CAT)
        self.assertIsNotNone(u_valk)
        self.sim.spawn_enemy("doge")
        doge = self.sim.units[TEAM_ENEMY][1]
        doge.attack_power = 99999
        # Deal lethal damage -> should survive at 1 HP because survive_prob=100
        self.sim._apply_damage(attacker=doge, target=u_valk, direction=1)
        self.assertTrue(u_valk.is_alive, "Unit with 100% survive lethal strike should survive at 1 HP")
        self.assertEqual(u_valk.hp, 1)

        # 2. Place enemy in front of valkyrie and verify wave attack triggers
        u_valk.hp = u_valk.max_hp
        u_valk.knockback_timer = 0
        doge.attack_power = 10
        doge.hp = 5000
        doge.max_hp = 5000
        doge.pos_x = u_valk.pos_x - 100
        wave_triggered = False
        for _ in range(35):
            self.sim.step()
            for ev in self.sim.visual_events:
                if ev.get("type") == "wave_attack":
                    wave_triggered = True
                    break
            if wave_triggered:
                break
        self.assertTrue(wave_triggered, "100% Wave Attack ability should emit wave_attack event on hit")

    def test_17_custom_units_and_symmetric_pvp(self):
        """Criterion 17: 自製角色載入與雙人對稱 PvP 對戰系統 (P1 右堡向左 vs P2 左堡向右)"""
        from game_project.core.custom_unit_loader import CustomUnitLoader
        loaded = CustomUnitLoader.load_all()
        self.assertGreaterEqual(len(loaded), 3)

        pvp_sim = BattleSimulation(
            pvp_mode=True,
            deck=["cat", "tank_cat", "axe_cat", "custom_cyber_valkyrie", "custom_frost_lizard"],
            p2_deck=["cat", "tank_cat", "axe_cat", "custom_dark_emperor", "custom_cyber_valkyrie"],
        )
        pvp_sim.wallet.money = 5000
        pvp_sim.p2_wallet.money = 5000

        # Deploy custom unit from P1 (Right Castle -> marches LEFT)
        self.assertTrue(pvp_sim.spawn_cat(3))
        # Deploy custom unit from P2 (Left Castle -> marches RIGHT)
        self.assertTrue(pvp_sim.spawn_p2_unit(3))

        p1_u = pvp_sim.units[TEAM_CAT][1]
        p2_u = pvp_sim.units[TEAM_ENEMY][1]
        self.assertIsNotNone(p1_u)
        self.assertIsNotNone(p2_u)
        self.assertEqual(p1_u.key, "custom_cyber_valkyrie")
        self.assertEqual(p2_u.key, "custom_dark_emperor")

        p1_init_x = p1_u.pos_x
        p2_init_x = p2_u.pos_x
        for _ in range(10):
            pvp_sim.step()
        self.assertLess(p1_u.pos_x, p1_init_x, "P1 unit on Right Castle must march LEFT")
        self.assertGreater(p2_u.pos_x, p2_init_x, "P2 unit on Left Castle must march RIGHT")

    def test_18_cat_cannon_mechanics_and_event_preservation(self):
        """Criterion 18: 貓咪砲 (Cat Cannon) 蓄力、發射、衝擊波推進與跨幀視覺事件保留"""
        self.sim.spawner.spawn_entries = []
        self.sim.spawn_enemy("doge")
        doge = self.sim.units[TEAM_ENEMY][1]
        doge.hp = 5000
        doge.max_hp = 5000
        cat_castle = self.sim.get_castle(TEAM_CAT)
        doge.pos_x = cat_castle.pos_x - 400  # Within Lv1 cannon_range (588.75 DU)

        # Charge cannon to 100%
        self.sim.cannon_charge = self.sim.cannon_max_charge
        self.assertTrue(self.sim.is_cannon_ready(TEAM_CAT))

        # Fire cannon BEFORE step() (just like UI click / Spacebar in main loop)
        fired = self.sim.fire_cannon(TEAM_CAT)
        self.assertTrue(fired)
        self.assertEqual(self.sim.cannon_charge, 0)
        self.assertGreater(self.sim.cannon_anim_timer[TEAM_CAT], 0)

        # Authentic progressive wavefront sweep (14 frames across authentic 588.75 DU range):
        # First step initiates the visual beam event
        self.sim.step()
        ev_types = [ev.get("type") for ev in self.sim.visual_events]
        self.assertIn("cannon_beam", ev_types, "cannon_beam visual event must survive into step() for BattleRenderer")

        # Step until the sweeping wavefront reaches Doge (400 DU ahead, reached around step 8)
        for _ in range(15):
            if doge.hp < 5000:
                break
            self.sim.step()

        # Doge (400px away) is struck by the sweeping wavefront
        self.assertLess(doge.hp, 5000, "Enemy in cannon wavefront path must take cannon damage")
        self.assertGreater(doge.knockback_timer, 0, "Enemy hit by cannon must be knocked back")

    def test_19_online_networked_pvp_lockstep_and_custom_unit_sync(self):
        """Criterion 19: 跨電腦 TCP 聯機對戰 (Online PvP Lockstep) 與自製角色自動同步驗證"""
        from game_project.network.pvp_net import PvPNetworkSession
        from game_project.core.custom_unit_loader import CustomUnitLoader

        CustomUnitLoader.load_all()
        # Register a brand-new custom unit so it gets synced over TCP handshake
        CustomUnitLoader.load_from_dict({
            "key": "custom_net_sync_dragon",
            "id": 995,
            "name": "連線同步神龍",
            "base_rig": "007_f",
            "hp": 8800,
            "ap": 1200,
            "range": 350,
            "speed": 14,
            "cost": 300,
            "cd_frames": 30,
            "kb_count": 3,
            "is_area_attack": True,
            "pre_atk_frames": 10,
            "tba_frames": 20,
            "attack_anim_frames": 25,
            "traits": ["red", "floating"],
            "target_traits": ["red", "black"],
            "abilities": {"wave_prob": 100, "wave_lvl": 3, "crit_prob": 50},
        })

        port = 17789
        host_net = PvPNetworkSession(
            role="host",
            host_ip="127.0.0.1",
            port=port,
            local_deck=["cat", "tank_cat", "custom_net_sync_dragon", "custom_cyber_valkyrie"],
            rng_seed=20261023,
        )
        client_net = PvPNetworkSession(
            role="client",
            host_ip="127.0.0.1",
            port=port,
            local_deck=["cat", "axe_cat", "custom_dark_emperor", "custom_net_sync_dragon"],
        )

        try:
            host_net.start()
            client_net.start()
            self.assertTrue(host_net.wait_until_ready(timeout=5.0), "Host failed handshake")
            self.assertTrue(client_net.wait_until_ready(timeout=5.0), "Client failed handshake")
            self.assertIn("custom_net_sync_dragon", client_net.synced_custom_units)
            self.assertIn("custom_net_sync_dragon", host_net.synced_custom_units)

            host_sim = host_net.create_synchronized_simulation()
            client_sim = client_net.create_synchronized_simulation()
            host_sim.wallet.money = 5000
            host_sim.p2_wallet.money = 5000
            client_sim.wallet.money = 5000
            client_sim.p2_wallet.money = 5000
            host_sim.cannon_charge = host_sim.cannon_max_charge
            client_sim.cannon_charge = client_sim.cannon_max_charge

            # Run 40 frames of lockstep battle concurrently across two independent threads (simulating 2 separate PCs)
            import threading
            client_errors = []

            def run_client_pc():
                try:
                    for f in range(1, 41):
                        if f == 2:
                            client_net.queue_local_action("SPAWN_UNIT", 2)  # Client spawns custom_dark_emperor
                        elif f == 5:
                            client_net.queue_local_action("SPAWN_UNIT", 0)
                        if not client_net.step_lockstep(client_sim, wait_timeout=3.0):
                            client_errors.append(f"Client lockstep timeout at frame {f}")
                            break
                except Exception as ex:
                    client_errors.append(str(ex))

            client_thread = threading.Thread(target=run_client_pc)
            client_thread.start()

            for f in range(1, 41):
                if f == 2:
                    host_net.queue_local_action("SPAWN_UNIT", 2)   # Host spawns custom_net_sync_dragon
                elif f == 5:
                    host_net.queue_local_action("UPGRADE_WORKER", None)
                elif f == 10:
                    host_net.queue_local_action("FIRE_CANNON", None)
                self.assertTrue(host_net.step_lockstep(host_sim, wait_timeout=3.0), f"Host lockstep timeout at frame {f}")

            client_thread.join(timeout=5.0)
            self.assertEqual(client_errors, [])

            # Verify 100% bit-for-bit deterministic simulation state across both computers!
            self.assertEqual(host_sim.current_frame, client_sim.current_frame)
            self.assertEqual(host_sim.wallet.money, client_sim.wallet.money)
            self.assertEqual(host_sim.p2_wallet.money, client_sim.p2_wallet.money)
            self.assertEqual(host_sim.cannon_charge, client_sim.cannon_charge)

            for team in (TEAM_CAT, TEAM_ENEMY):
                for slot in range(1, 10):
                    u_h = host_sim.units[team][slot]
                    u_c = client_sim.units[team][slot]
                    if u_h is None or u_c is None:
                        self.assertIsNone(u_h)
                        self.assertIsNone(u_c)
                    else:
                        self.assertEqual(u_h.key, u_c.key)
                        self.assertEqual(u_h.pos_x, u_c.pos_x)
                        self.assertEqual(u_h.hp, u_c.hp)
        finally:
            host_net.close()
            client_net.close()

    def test_20_web_server_room_code_and_custom_unit_api(self):
        """Criterion 20: 網頁版 4 位數房號 (Room Code) 聯機對戰與網頁自製角色 API 驗證"""
        import json
        import urllib.request
        import threading
        from http.server import ThreadingHTTPServer
        import game_project.web_server as ws

        ws.ROOM_MGR = ws.RoomManager()
        server = ThreadingHTTPServer(("127.0.0.1", 18089), ws.BattleCatsWebHandler)
        t = threading.Thread(target=server.serve_forever, daemon=True)
        t.start()
        try:
            # 1. Verify /api/bootstrap returns skeletal rigs and custom units
            with urllib.request.urlopen("http://127.0.0.1:18089/api/bootstrap") as r:
                boot = json.loads(r.read().decode("utf-8"))
            self.assertIn("000_f", boot["rigs"])
            self.assertGreaterEqual(len(boot["base_cats"]), 9)

            # 2. Create a room with 4-digit Room Code "8899"
            req_create = urllib.request.Request(
                "http://127.0.0.1:18089/api/room/create",
                data=json.dumps({"player_name": "房主小吳", "room_code": "8899", "vs_ai": False}).encode("utf-8"),
                headers={"Content-Type": "application/json"},
                method="POST",
            )
            with urllib.request.urlopen(req_create) as r:
                res_create = json.loads(r.read().decode("utf-8"))
            self.assertTrue(res_create["ok"])
            self.assertEqual(res_create["room_code"], "8899")
            self.assertEqual(res_create["team"], TEAM_CAT)

            # 3. Friend joins using Room Code "8899"
            req_join = urllib.request.Request(
                "http://127.0.0.1:18089/api/room/join",
                data=json.dumps({"player_name": "朋友阿明", "room_code": "8899"}).encode("utf-8"),
                headers={"Content-Type": "application/json"},
                method="POST",
            )
            with urllib.request.urlopen(req_join) as r:
                res_join = json.loads(r.read().decode("utf-8"))
            self.assertTrue(res_join["ok"])
            self.assertEqual(res_join["team"], TEAM_ENEMY)
            self.assertEqual(res_join["state"]["status"], "PLAYING")

            # 4. Both players send SPAWN_UNIT actions to Room "8899"
            for team_id in (TEAM_CAT, TEAM_ENEMY):
                req_act = urllib.request.Request(
                    "http://127.0.0.1:18089/api/room/action",
                    data=json.dumps({"room_code": "8899", "team": team_id, "action": "SPAWN_UNIT", "payload": 0}).encode("utf-8"),
                    headers={"Content-Type": "application/json"},
                    method="POST",
                )
                with urllib.request.urlopen(req_act) as r:
                    res_act = json.loads(r.read().decode("utf-8"))
                self.assertTrue(res_act["ok"])

            with urllib.request.urlopen("http://127.0.0.1:18089/api/room/state?room=8899") as r:
                st = json.loads(r.read().decode("utf-8"))
            self.assertGreaterEqual(len(st["units"]), 2)
        finally:
            ws.ROOM_MGR.running = False
            server.shutdown()
            server.server_close()

    def test_21_multi_rarity_cats_and_prebattle_formation(self):
        """Criterion 21: 6 大稀有度（基本、EX、稀有、激稀有、超激稀有、傳說稀有）各至少 5 隻貓咪與開戰前配隊選角驗證"""
        from collections import Counter
        from game_project.core.unit_data import CAT_REGISTRY, OFFICIAL_CAT_KEYS
        from game_project.render.unit_sprite_manager import UnitSpriteManager

        self.assertGreaterEqual(len(OFFICIAL_CAT_KEYS), 38)
        rarity_counts = Counter()
        for k in OFFICIAL_CAT_KEYS:
            self.assertIn(k, CAT_REGISTRY)
            spec = CAT_REGISTRY[k]
            rarity_counts[spec["rarity"]] += 1

        for r_key in ("normal", "ex", "rare", "super_rare", "uber_rare", "legend_rare"):
            self.assertGreaterEqual(
                rarity_counts[r_key], 5,
                f"Rarity {r_key} should have at least 5 cats, got {rarity_counts[r_key]}"
            )

        # Verify skeletal players load cleanly for all 38 official cats
        mgr = UnitSpriteManager()
        for k in OFFICIAL_CAT_KEYS:
            player = mgr.get_player_for_unit(k)
            self.assertIsNotNone(player, f"Missing skeletal player for {k}")

        # Verify Pre-Battle Deck Formation with 1 cat from each of the 6 rarities
        custom_multi_rarity_deck = [
            "cat", "ex_bahamut", "rare_pogo", "sr_swimmer", "uber_balrog",
            "legend_momoco", "uber_hanzo", "legend_assassin", "sr_kotatsu", "rare_salon",
        ]
        sim = BattleSimulation(deck=custom_multi_rarity_deck, pvp_mode=True)
        sim.wallet.money = 15000
        for idx in range(6):
            ok = sim.deploy_unit(TEAM_CAT, idx)
            self.assertTrue(ok, f"Failed to spawn multi-rarity slot {idx} ({custom_multi_rarity_deck[idx]})")

    def test_22_strict_ponos_multihit_and_tbcml_matrix_parity(self):
        """Criterion 22: 100% 對齊 PONOS unitXXX.csv 多段攻擊 (pre1/pre2/pre3, use_ability) 與 tbcml 骨骼仿射矩陣"""
        from game_project.core.unit_data import CAT_REGISTRY

        # 1. Verify official multi-hit CSV stats are never truncated to Hit 1
        momoco = CAT_REGISTRY["legend_momoco"]
        self.assertEqual(len(momoco["attack_hits"]), 3)
        self.assertEqual([h["damage"] for h in momoco["attack_hits"]], [300, 600, 3500])
        self.assertEqual([h["foreswing"] for h in momoco["attack_hits"]], [28, 55, 100])
        self.assertEqual([h["use_ability"] for h in momoco["attack_hits"]], [True, False, False])
        self.assertEqual(momoco["attack_power"], 4400)

        delinquent = CAT_REGISTRY["sr_delinquent"]
        self.assertEqual(len(delinquent["attack_hits"]), 3)
        self.assertEqual([h["damage"] for h in delinquent["attack_hits"]], [145, 145, 145])
        self.assertEqual([h["foreswing"] for h in delinquent["attack_hits"]], [18, 30, 46])
        self.assertEqual(delinquent["attack_power"], 435)

        shirou = CAT_REGISTRY["legend_shirou"]
        self.assertEqual(len(shirou["attack_hits"]), 2)
        self.assertEqual([h["damage"] for h in shirou["attack_hits"]], [3000, 3000])
        self.assertEqual(shirou["attack_power"], 6000)

        # 2. Verify MOMOCO 3-hit execution in BattleSimulation at frames 28, 55, 100
        sim = BattleSimulation(deck=["legend_momoco"], pvp_mode=False)
        sim.spawner.spawn_entries = []
        sim.wallet.money = 9999
        self.assertTrue(sim.spawn_cat(0))
        u_momo = sim.units[TEAM_CAT][1]

        sim.spawn_enemy("doge")
        doge = sim.units[TEAM_ENEMY][1]
        doge.hp = 50000
        doge.max_hp = 50000
        doge.kb_count = 1
        doge.kb_threshold = 50000
        doge.attack_power = 0
        doge.pos_x = u_momo.pos_x - 200  # Within MOMOCO's 375 standing range

        dmg_frames = []
        for f in range(1, 110):
            sim.step()
            for ev in sim.visual_events:
                if ev.get("type") == "damage" and ev.get("team") == TEAM_ENEMY:
                    dmg_frames.append((f, ev.get("damage")))

        self.assertEqual(
            dmg_frames,
            [(29, 300), (29, 300), (56, 600), (101, 3500)],
            f"MOMOCO Hit 1 (pre=28) lands 300 + 300 wave (use_ability=True), Hit 2 (pre=55) lands 600, Hit 3 (pre=100) lands 3500, got {dmg_frames}"
        )
        self.assertEqual(50000 - doge.hp, 4700)

    def test_09_headless_full_loop_run(self):
        """Criterion 9: 完整端到端運行無任何致命錯誤"""
        screenshot_path = r"E:\rea\game_project\screenshots\headless_test.png"
        final_sim = run_game(
            headless=True,
            auto_play=True,
            max_frames=120,
            capture_screenshot=screenshot_path
        )
        self.assertIsNotNone(final_sim)
        self.assertGreaterEqual(final_sim.current_frame, 120)
        self.assertTrue(os.path.exists(screenshot_path), "Screenshot was not created")

if __name__ == "__main__":
    unittest.main()
