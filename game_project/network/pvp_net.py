"""
Online Networked PvP Lockstep Engine (`pvp_net.py`).
Enables two separate computers (LAN / Internet TCP/IP) to battle in real-time
deterministic lockstep with automatic Custom Character synchronization:
- Host (Player 1, Right Castle `TEAM_CAT`) binds a TCP server port (default 7777).
- Client (Player 2, Left Castle `TEAM_ENEMY`) connects to `<host_ip>:<port>`.
- Handshake exchanges `rng_seed`, `stage_config`, `deck`, `cat_levels`, `base_levels`,
  and full `custom_units` definitions (`CustomUnitLoader.export_all_specs()`) so custom characters
  created on one PC automatically exist and render on the friend's PC!
- Lockstep frame protocol (`FRAME`) exchanges player actions (`SPAWN_UNIT`, `UPGRADE_WORKER`,
  `FIRE_CANNON`, `SPAWN_CUSTOM`) for each frame `F` and executes `TEAM_CAT` then `TEAM_ENEMY`
  deterministically before `sim.step()`.
"""

import json
import time
import socket
import threading
from typing import Dict, List, Any, Optional, Tuple
from ..core.constants import TEAM_CAT, TEAM_ENEMY
from ..core.custom_unit_loader import CustomUnitLoader
from ..simulation.battle_sim import BattleSimulation


def get_local_ip() -> str:
    """Detects the primary LAN IPv4 address of this machine for hosting Online PvP."""
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.settimeout(0.5)
        s.connect(("8.8.8.8", 80))
        ip = s.getsockname()[0]
        s.close()
        return ip
    except Exception:
        try:
            return socket.gethostbyname(socket.gethostname())
        except Exception:
            return "127.0.0.1"


class PvPNetworkSession:
    """
    Manages a TCP Lockstep Online PvP session between two computers (Host = TEAM_CAT, Client = TEAM_ENEMY).
    """

    def __init__(
        self,
        role: str,
        host_ip: str = "0.0.0.0",
        port: int = 7777,
        stage_config: Optional[Dict[str, Any]] = None,
        local_deck: Optional[List[Any]] = None,
        local_cat_levels: Optional[Dict[str, int]] = None,
        local_base_levels: Optional[Dict[str, int]] = None,
        rng_seed: Optional[int] = None,
    ):
        self.role = role.lower().strip()  # "host" or "client"
        self.local_team = TEAM_CAT if self.role == "host" else TEAM_ENEMY
        self.remote_team = TEAM_ENEMY if self.role == "host" else TEAM_CAT
        self.host_ip = host_ip
        self.port = int(port)

        self.stage_config = stage_config or {"name": "線上聯機對戰", "length": 3000, "cat_castle_hp": 20000, "enemy_castle_hp": 20000, "waves": []}
        self.local_deck = list(local_deck or ["cat", "tank_cat", "axe_cat", "gross_cat", "cow_cat", "bird_cat", "fish_cat", "lizard_cat", "titan_cat"])
        self.local_cat_levels = dict(local_cat_levels or {})
        self.local_base_levels = dict(local_base_levels or {})
        self.rng_seed = rng_seed if rng_seed is not None else (int(time.time() * 1000) & 0x7FFFFFFF)

        # Remote peer's synced data filled during handshake
        self.remote_deck: List[Any] = []
        self.remote_cat_levels: Dict[str, int] = {}
        self.remote_base_levels: Dict[str, int] = {}
        self.synced_custom_units: List[str] = []

        # Socket & Thread state
        self._server_sock: Optional[socket.socket] = None
        self._conn_sock: Optional[socket.socket] = None
        self._send_lock = threading.Lock()
        self._frame_lock = threading.Condition()

        self.state = "INIT"  # INIT -> WAITING_FOR_PEER / CONNECTING -> HANDSHAKING -> READY -> DISCONNECTED / ERROR
        self.status_message = "初始化網路連線..."
        self.error_message = ""
        self.peer_address: Optional[Tuple[str, int]] = None
        self.running = True

        # Lockstep queues
        self._pending_local_actions: List[Dict[str, Any]] = []
        self._sent_frames: Dict[int, List[Dict[str, Any]]] = {}
        self._received_frames: Dict[int, List[Dict[str, Any]]] = {}
        self.last_rtt_ms: float = 0.0
        self._frame_send_time: Dict[int, float] = {}

    def start(self):
        """Starts the background networking thread (Host listener or Client connector)."""
        t = threading.Thread(target=self._network_worker, daemon=True)
        t.start()

    def close(self):
        """Cleanly closes all sockets and stops background threads."""
        self.running = False
        with self._frame_lock:
            self._frame_lock.notify_all()
        try:
            if self._conn_sock:
                self._conn_sock.close()
        except Exception:
            pass
        try:
            if self._server_sock:
                self._server_sock.close()
        except Exception:
            pass
        if self.state not in ("ERROR",):
            self.state = "DISCONNECTED"

    def _send_json(self, payload: Dict[str, Any]):
        sock = self._conn_sock
        if sock is None:
            return
        line = (json.dumps(payload, ensure_ascii=False) + "\n").encode("utf-8")
        with self._send_lock:
            sock.sendall(line)

    def _network_worker(self):
        try:
            if self.role == "host":
                self.state = "WAITING_FOR_PEER"
                lan_ip = get_local_ip()
                self.status_message = f"等待玩家連入... 本機 IP: {lan_ip}:{self.port}"
                srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
                srv.bind((self.host_ip, self.port))
                srv.listen(1)
                srv.settimeout(0.5)
                self._server_sock = srv

                conn = None
                while self.running and conn is None:
                    try:
                        conn, addr = srv.accept()
                        self.peer_address = addr
                    except socket.timeout:
                        continue

                if not self.running or conn is None:
                    return

                conn.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
                conn.settimeout(None)
                self._conn_sock = conn
                self.state = "HANDSHAKING"
                self.status_message = f"已連線至 {self.peer_address[0]}，正在同步自製角色與牌組..."

                # Send HELLO_HOST with rng_seed, stage_config, deck, levels, and custom units
                custom_specs = CustomUnitLoader.export_all_specs()
                self._send_json({
                    "type": "HELLO_HOST",
                    "rng_seed": self.rng_seed,
                    "stage_config": self.stage_config,
                    "deck": self.local_deck,
                    "cat_levels": self.local_cat_levels,
                    "base_levels": self.local_base_levels,
                    "custom_units": custom_specs,
                })
            else:
                self.state = "CONNECTING"
                self.status_message = f"正在連線至房主 {self.host_ip}:{self.port} ..."
                conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                conn.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
                conn.settimeout(8.0)
                conn.connect((self.host_ip, self.port))
                conn.settimeout(None)
                self._conn_sock = conn
                self.peer_address = (self.host_ip, self.port)
                self.state = "HANDSHAKING"
                self.status_message = "已連上房主，正在同步自製角色與牌組..."

            # Reader loop (newline-delimited JSON)
            buf = b""
            while self.running and self._conn_sock is not None:
                chunk = self._conn_sock.recv(65536)
                if not chunk:
                    break
                buf += chunk
                while b"\n" in buf:
                    raw_line, buf = buf.split(b"\n", 1)
                    if not raw_line.strip():
                        continue
                    msg = json.loads(raw_line.decode("utf-8"))
                    self._handle_message(msg)

        except Exception as e:
            if self.running:
                self.state = "ERROR"
                self.error_message = str(e)
                self.status_message = f"連線中斷或錯誤: {e}"
        finally:
            if self.running and self.state != "ERROR":
                self.state = "DISCONNECTED"
                self.status_message = "對手已離線"
            with self._frame_lock:
                self._frame_lock.notify_all()

    def _handle_message(self, msg: Dict[str, Any]):
        mtype = msg.get("type")
        if mtype == "HELLO_HOST" and self.role == "client":
            self.rng_seed = int(msg.get("rng_seed", 42))
            if "stage_config" in msg and isinstance(msg["stage_config"], dict):
                self.stage_config = msg["stage_config"]
            self.remote_deck = list(msg.get("deck", []))
            self.remote_cat_levels = dict(msg.get("cat_levels", {}))
            self.remote_base_levels = dict(msg.get("base_levels", {}))
            peer_custom = msg.get("custom_units", [])
            if isinstance(peer_custom, list) and peer_custom:
                synced = CustomUnitLoader.sync_specs_from_list(peer_custom)
                self.synced_custom_units.extend(synced)

            # Reply with HELLO_CLIENT
            my_custom = CustomUnitLoader.export_all_specs()
            self._send_json({
                "type": "HELLO_CLIENT",
                "deck": self.local_deck,
                "cat_levels": self.local_cat_levels,
                "base_levels": self.local_base_levels,
                "custom_units": my_custom,
            })
            with self._frame_lock:
                self.state = "READY"
                self.status_message = f"連線成功 (Client P2 左堡) | 已同步 {len(self.synced_custom_units)} 個自製角色"
                self._frame_lock.notify_all()

        elif mtype == "HELLO_CLIENT" and self.role == "host":
            self.remote_deck = list(msg.get("deck", []))
            self.remote_cat_levels = dict(msg.get("cat_levels", {}))
            self.remote_base_levels = dict(msg.get("base_levels", {}))
            peer_custom = msg.get("custom_units", [])
            if isinstance(peer_custom, list) and peer_custom:
                synced = CustomUnitLoader.sync_specs_from_list(peer_custom)
                self.synced_custom_units.extend(synced)

            with self._frame_lock:
                self.state = "READY"
                self.status_message = f"連線成功 (Host P1 右堡) | 已同步 {len(self.synced_custom_units)} 個自製角色"
                self._frame_lock.notify_all()

        elif mtype == "FRAME":
            frame_no = int(msg.get("frame", 0))
            actions = list(msg.get("actions", []))
            with self._frame_lock:
                self._received_frames[frame_no] = actions
                if frame_no in self._frame_send_time:
                    self.last_rtt_ms = (time.perf_counter() - self._frame_send_time.pop(frame_no)) * 1000.0
                self._frame_lock.notify_all()

    def wait_until_ready(self, timeout: float = 10.0) -> bool:
        """Blocks up to `timeout` seconds until handshake completes and state == 'READY'."""
        deadline = time.time() + timeout
        with self._frame_lock:
            while self.running and self.state not in ("READY", "ERROR", "DISCONNECTED"):
                rem = deadline - time.time()
                if rem <= 0:
                    return False
                self._frame_lock.wait(timeout=min(0.2, rem))
            return self.state == "READY"

    def create_synchronized_simulation(self) -> BattleSimulation:
        """
        Creates a deterministic `BattleSimulation` after handshake completes so both Host and Client
        have identical `rng_seed`, decks, levels, and custom characters.
        """
        if self.role == "host":
            p1_deck = self.local_deck
            p1_levels = self.local_cat_levels
            p1_base = self.local_base_levels
            p2_deck = self.remote_deck or self.local_deck
            p2_levels = self.remote_cat_levels or self.local_cat_levels
            p2_base = self.remote_base_levels or self.local_base_levels
        else:
            p1_deck = self.remote_deck or self.local_deck
            p1_levels = self.remote_cat_levels or self.local_cat_levels
            p1_base = self.remote_base_levels or self.local_base_levels
            p2_deck = self.local_deck
            p2_levels = self.local_cat_levels
            p2_base = self.local_base_levels

        # Ensure symmetric castle HP for Online PvP
        stg = dict(self.stage_config)
        stg["cat_castle_hp"] = stg.get("cat_castle_hp", 20000)
        stg["enemy_castle_hp"] = stg["cat_castle_hp"]

        return BattleSimulation(
            stage_config=stg,
            deck=p1_deck,
            cat_levels=p1_levels,
            base_levels=p1_base,
            pvp_mode=True,
            p2_deck=p2_deck,
            p2_levels=p2_levels,
            p2_base_levels=p2_base,
            rng_seed=self.rng_seed,
        )

    def queue_local_action(self, action_type: str, payload: Any = None):
        """Queues a local player input (`SPAWN_UNIT`, `UPGRADE_WORKER`, `FIRE_CANNON`, `SPAWN_CUSTOM`) for the next lockstep frame."""
        with self._frame_lock:
            self._pending_local_actions.append({"action": action_type, "payload": payload})

    @staticmethod
    def _apply_team_actions(sim: BattleSimulation, team: int, actions: List[Dict[str, Any]]):
        for act_obj in actions:
            act = act_obj.get("action")
            payload = act_obj.get("payload")
            if act == "SPAWN_UNIT":
                sim.deploy_unit(team, int(payload))
            elif act == "UPGRADE_WORKER":
                sim.wallets[team].upgrade_worker()
            elif act == "FIRE_CANNON":
                sim.fire_cannon(team)
            elif act == "SPAWN_CUSTOM":
                if isinstance(payload, dict) and "key" in payload:
                    CustomUnitLoader.load_from_dict(payload)
                    sim.spawn_custom_unit(payload["key"], team=team)
                elif isinstance(payload, str):
                    sim.spawn_custom_unit(payload, team=team)

    def step_lockstep(self, sim: BattleSimulation, wait_timeout: float = 0.05) -> bool:
        """
        Executes one deterministic lockstep frame `F = sim.current_frame + 1`:
        1. Sends local queued actions for frame `F` if not yet sent.
        2. Waits up to `wait_timeout` seconds for remote peer's actions for frame `F`.
        3. Applies Team 0 (`TEAM_CAT`) actions then Team 1 (`TEAM_ENEMY`) actions deterministically, and calls `sim.step()`.
        """
        if self.state != "READY" or sim.game_over:
            return False

        target_frame = sim.current_frame + 1
        with self._frame_lock:
            if target_frame not in self._sent_frames:
                my_actions = list(self._pending_local_actions)
                self._pending_local_actions.clear()
                self._sent_frames[target_frame] = my_actions
                self._frame_send_time[target_frame] = time.perf_counter()
                try:
                    self._send_json({
                        "type": "FRAME",
                        "frame": target_frame,
                        "actions": my_actions,
                    })
                except Exception as e:
                    self.state = "ERROR"
                    self.error_message = str(e)
                    return False

            deadline = time.perf_counter() + wait_timeout
            while self.running and self.state == "READY" and target_frame not in self._received_frames:
                rem = deadline - time.perf_counter()
                if rem <= 0:
                    return False
                self._frame_lock.wait(timeout=rem)

            if target_frame not in self._received_frames:
                return False

            my_actions = self._sent_frames.pop(target_frame, [])
            peer_actions = self._received_frames.pop(target_frame, [])

        # Deterministic execution order: TEAM_CAT (Host) first, TEAM_ENEMY (Client) second
        if self.local_team == TEAM_CAT:
            p1_actions, p2_actions = my_actions, peer_actions
        else:
            p1_actions, p2_actions = peer_actions, my_actions

        self._apply_team_actions(sim, TEAM_CAT, p1_actions)
        self._apply_team_actions(sim, TEAM_ENEMY, p2_actions)
        sim.step()
        return True

    def get_hud_status(self) -> str:
        role_str = "P1 房主 (右側主堡)" if self.local_team == TEAM_CAT else "P2 訪客 (左側主堡)"
        if self.state == "READY":
            return f"【線上聯機對戰】{role_str} | Ping: {self.last_rtt_ms:.1f}ms | 自製角色已同步 ({len(self.synced_custom_units)})"
        return f"【線上聯機對戰】{self.status_message}"
