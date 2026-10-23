import capstone
import struct

def disassemble_range(path, start_addr, size):
    with open(path, 'rb') as f:
        f.seek(start_addr)
        code = f.read(size)
    
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    instructions = []
    for i in md.disasm(code, start_addr):
        instructions.append((i.address, i.bytes.hex(), i.mnemonic, i.op_str))
    return instructions

target_funcs = [
    ("appInit", 0x00309c5c, 208),
    ("appUpdateDraw", 0x00309d2c, 228),
    ("fsInit", 0x00309e10, 8),
    ("gfxInit", 0x00309e18, 276),
    ("appTouch", 0x0030a098, 192),
    ("kill", 0x0030a388, 112)
]

so_path = r"E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so"

for name, addr, sz in target_funcs:
    print(f"=== Disassembly of {name} (0x{addr:08x}, {sz} bytes) ===")
    insns = disassemble_range(so_path, addr, sz)
    for a, h, m, o in insns[:30]:
        print(f"  0x{a:08x}:  {h:8}  {m:8} {o}")
    if len(insns) > 30:
        print(f"  ... ({len(insns) - 30} more instructions)")
    print()
