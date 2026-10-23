import unicorn
from unicorn import arm64_const
from so_extractor import verify_and_extract_bytes, BLOCK_MAGIC_DIV, BLOCK_HP_READ, BLOCK_HP_WRITE

class UnicornARM64Engine:
    def __init__(self):
        # We reuse or instantiate Unicorn instances per test
        pass

    @staticmethod
    def run_magic_div(w0: int, w23: int) -> int:
        """
        Executes raw 32 bytes from 0x004c6800 to 0x004c6820 in Unicorn AArch64.
        Inputs: w0 (multiplier), w23 (base damage)
        Output: w23 (scaled damage)
        """
        raw_code = verify_and_extract_bytes(BLOCK_MAGIC_DIV['offset'], BLOCK_MAGIC_DIV['size'])
        
        mu = unicorn.Uc(unicorn.UC_ARCH_ARM64, unicorn.UC_MODE_ARM)
        
        # Map code page (aligned to 4KB/64KB)
        CODE_PAGE = 0x4c0000
        mu.mem_map(CODE_PAGE, 0x10000)
        mu.mem_write(BLOCK_MAGIC_DIV['offset'], raw_code)
        
        # Set registers
        # Ensure 32-bit values are masked to unsigned 32-bit for Unicorn registers
        mu.reg_write(arm64_const.UC_ARM64_REG_W0, w0 & 0xffffffff)
        mu.reg_write(arm64_const.UC_ARM64_REG_W23, w23 & 0xffffffff)
        
        # Execute block
        start_addr = BLOCK_MAGIC_DIV['offset']
        end_addr = start_addr + BLOCK_MAGIC_DIV['size']
        mu.emu_start(start_addr, end_addr)
        
        # Read result
        res = mu.reg_read(arm64_const.UC_ARM64_REG_W23)
        # Convert to signed 32-bit int
        if res >= 0x80000000:
            res -= 0x100000000
        return res

    @staticmethod
    def run_hp_read(battlefield_base: int, team: int, unit: int, initial_mem: bytes) -> int:
        """
        Executes raw 28 bytes from 0x00959894 to 0x009598b0 in Unicorn AArch64.
        Inputs: x0=battlefield_base, w20=team, w19=unit
        Output: w0 (read HP)
        """
        raw_code = verify_and_extract_bytes(BLOCK_HP_READ['offset'], BLOCK_HP_READ['size'])
        
        mu = unicorn.Uc(unicorn.UC_ARCH_ARM64, unicorn.UC_MODE_ARM)
        
        # Map code page
        CODE_PAGE = 0x950000
        mu.mem_map(CODE_PAGE, 0x20000)
        mu.mem_write(BLOCK_HP_READ['offset'], raw_code)
        
        # Map battlefield memory (2MB)
        mu.mem_map(battlefield_base, 0x200000)
        mu.mem_write(battlefield_base, initial_mem)
        
        # Setup registers
        mu.reg_write(arm64_const.UC_ARM64_REG_X0, battlefield_base)
        mu.reg_write(arm64_const.UC_ARM64_REG_W20, team & 0xffffffff)
        mu.reg_write(arm64_const.UC_ARM64_REG_W19, unit & 0xffffffff)
        
        start_addr = BLOCK_HP_READ['offset']
        end_addr = start_addr + BLOCK_HP_READ['size']
        mu.emu_start(start_addr, end_addr)
        
        res = mu.reg_read(arm64_const.UC_ARM64_REG_W0)
        if res >= 0x80000000:
            res -= 0x100000000
        return res

    @staticmethod
    def run_hp_write(battlefield_base: int, team: int, unit: int, new_hp: int) -> int:
        """
        Executes raw 28 bytes from 0x009598dc to 0x009598f8 in Unicorn AArch64.
        Inputs: x0=battlefield_base, w21=team, w20=unit, w19=new_hp
        Output: value read back from memory at the effective address
        """
        raw_code = verify_and_extract_bytes(BLOCK_HP_WRITE['offset'], BLOCK_HP_WRITE['size'])
        
        mu = unicorn.Uc(unicorn.UC_ARCH_ARM64, unicorn.UC_MODE_ARM)
        
        CODE_PAGE = 0x950000
        mu.mem_map(CODE_PAGE, 0x20000)
        mu.mem_write(BLOCK_HP_WRITE['offset'], raw_code)
        
        # Map battlefield memory
        mu.mem_map(battlefield_base, 0x200000)
        
        # Setup registers
        mu.reg_write(arm64_const.UC_ARM64_REG_X0, battlefield_base)
        mu.reg_write(arm64_const.UC_ARM64_REG_W21, team & 0xffffffff)
        mu.reg_write(arm64_const.UC_ARM64_REG_W20, unit & 0xffffffff)
        mu.reg_write(arm64_const.UC_ARM64_REG_W19, new_hp & 0xffffffff)
        
        start_addr = BLOCK_HP_WRITE['offset']
        end_addr = start_addr + BLOCK_HP_WRITE['size']
        mu.emu_start(start_addr, end_addr)
        
        # Read back the written memory at calculated address
        target_addr = battlefield_base + (team * 0xc738) + (unit * 0x3e8) + 0x83960
        written_bytes = mu.mem_read(target_addr, 4)
        val = int.from_bytes(written_bytes, 'little', signed=True)
        return val

if __name__ == '__main__':
    # Quick sanity check
    res_div = UnicornARM64Engine.run_magic_div(1500, 200)
    print(f"Sanity Check Magic Div (1500 * 200 / 1000): {res_div} (Expected 300)")
    assert res_div == 300
    
    # Sanity check HP Write
    BASE = 0x10000000
    written = UnicornARM64Engine.run_hp_write(BASE, team=1, unit=5, new_hp=12345)
    print(f"Sanity Check HP Write (Team 1, Unit 5, HP 12345): {written} (Expected 12345)")
    assert written == 12345
    print("All Unicorn Harness Sanity Checks PASSED!")
