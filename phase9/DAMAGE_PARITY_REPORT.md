# Phase 9 — 傷害計算模組功能等價性審計報告 (DAMAGE_PARITY_REPORT.md)

**審計模組**：`combat_core/` ([`unit_memory.py`](file:///E:/rea/phase9/combat_core/unit_memory.py) & [`damage_engine.py`](file:///E:/rea/phase9/combat_core/damage_engine.py))  
**測試檔案**：[`test_damage.py`](file:///E:/rea/phase9/test_damage.py) (7/7 PASS)  
**參考二進位**：`libnative-lib.so` (AArch64, `Battle_ApplyDamageToUnit` @ `0x004c6340`)  
**評定狀態**：**STATIC_CONSISTENT (靜態規格自洽) / PARITY_UNVERIFIED (動態未比對)**  

---

## 1. 嚴正聲明：一致性等級定義與邊界

依據 Phase 9 驗收規範，嚴格切分自製模組測試通過與原版動態一致性之界限：

| 等級代碼 | 定義標準 | 當前模組判定 | 說明 |
|---|---|---|---|
| **VERIFIED_PARITY** | 在合法 Android ARM64 執行期環境中注入相同輸入，比對原版函式暫存器、記憶體寫入與日誌，結果 100% 相同。 | **未達成 (NOT CLAIMED)** | 本機無可用 ARM64 模擬環境與 ADB 偵錯實體，無法進行執行期比對。 |
| **STATIC_CONSISTENT** | 重建模組之定址公式、千分比乘除常數（`0x10624dd3`）、條件分支與記憶體 Setter 呼叫順序完全符合 AArch64 反組譯與 Ghidra 反編譯所得之靜態規格。 | **ACHIEVED (已達成)** | 7 項涵蓋正常、邊界、極端值的單元測試全數通過。 |
| **PARITY_UNVERIFIED** | 因無原版動態環境比對，特此明確標記動態等價性尚未驗證。 | **CONFIRMED (已標記)** | 絕不因單元測試通過即宣稱原版完全一致。 |

---

## 2. 測試案例與二進位指令對應矩陣

| 測試案例 (Test Case) | 測試目的 | 輸入條件 (Inputs) | 逆向對應之 Native 指令 | 預期輸出 (Expected) | 實際輸出 (Actual) | 狀態 |
|---|---|---|---|---|---|---|
| `test_magic_division_permille_parity` | 驗證編譯器優化之千分比除法定點數計算 | 10 組不同數值組合，如 `12345 * 1234 / 1000` | `0x004c6800`: `mul`<br>`0x004c6810`: `smull x8, w9, 0x10624dd3`<br>`0x004c6818`: `asr x8, x8, #38` | `15233` | `15233` (誤差 0) | **PASS** |
| `test_normal_damage_application` | 驗證標準受傷扣血與記憶體回寫 | HP=100, Base Damage=35, Mult=1000 | `0x004c641c`: `GetUnitHP`<br>`0x004c659c`: `SetUnitHP` | Remaining HP=65, Alive=True, Killed=False | Remaining HP=65, Alive=True, Killed=False | **PASS** |
| `test_death_and_cleanup_trigger` | 驗證超量致死傷害與死亡除役清理 | HP=100, Damage=120 | `0x008b6f50`: `Battle_KillUnit`<br>HP=0, Alive=0, Timer=0 | Remaining HP=0, Killed=True, Alive=False | Remaining HP=0, Killed=True, Alive=False | **PASS** |
| `test_exact_hp_depletion_boundary` | 驗證傷害剛好等於剩餘生命值的臨界點 | HP=100, Damage=100 | `0x004c6420`: `cmp w0, w23` | Remaining HP=0, Killed=True | Remaining HP=0, Killed=True | **PASS** |
| `test_knockback_threshold_trigger` | 驗證扣血達標觸發擊退硬直狀態 | HP=100, Damage=40, KB Threshold=33 | `0x00959ca8`: `Battle_SetUnitKnockback` | Remaining HP=60, KB=1 | Remaining HP=60, KB=1 | **PASS** |
| `test_barrier_absorption_and_break` | 驗證護盾吸收與破盾機制 | Barrier=500; Dmg=300 (吸收), Dmg=600 (破盾) | `0x0095ac18`: `CheckDamageImmunity` | 300 傷: HP 不變<br>600 傷: 破盾並致死 | 300 傷: HP 不變<br>600 傷: 破盾並致死 | **PASS** |
| `test_attack_on_dead_unit_ignored` | 驗證對已死亡/未生成單位忽略傷害 | Alive=False, Damage=50 | `0x004c6410`: `tbz w8, #0, #0x4c6c1c` | Scaled Damage=0, Immune=True | Scaled Damage=0, Immune=True | **PASS** |

---

## 3. 測試執行命令與日誌

- **執行命令**：`python -m unittest discover -s "E:\rea\phase9" -p "test_*.py" -v`
- **執行時間**：2026-10-15T02:32:35+08:00
- **終端輸出**：
```text
test_attack_on_dead_unit_ignored (test_damage.TestNativeDamageEngine.test_attack_on_dead_unit_ignored)
Tests that damage is ignored on dead / non-spawned units. ... ok
test_barrier_absorption_and_break (test_damage.TestNativeDamageEngine.test_barrier_absorption_and_break)
Tests barrier defense immunity check (0x0095ac18). ... ok
test_death_and_cleanup_trigger (test_damage.TestNativeDamageEngine.test_death_and_cleanup_trigger)
Tests unit death when HP reaches 0 and Battle_KillUnit clean-up (0x008b6f50). ... ok
test_exact_hp_depletion_boundary (test_damage.TestNativeDamageEngine.test_exact_hp_depletion_boundary)
Tests boundary when incoming damage exactly equals current HP. ... ok
test_knockback_threshold_trigger (test_damage.TestNativeDamageEngine.test_knockback_threshold_trigger)
Tests knockback state setter when damage exceeds threshold (0x00959ca8). ... ok
test_magic_division_permille_parity (test_damage.TestNativeDamageEngine.test_magic_division_permille_parity)
Verifies ARM64 compiler division by 1000 magic constant 0x10624dd3 >> 38. ... ok
test_normal_damage_application (test_damage.TestNativeDamageEngine.test_normal_damage_application)
Tests standard damage application and memory writeback (0x004c6414 - 0x004c659c). ... ok

----------------------------------------------------------------------
Ran 7 tests in 0.000s

OK
```
