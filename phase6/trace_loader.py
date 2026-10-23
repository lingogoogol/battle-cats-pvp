import capstone

so_path = r'E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so'

def disasm_block(start_addr, count=40):
    with open(so_path, 'rb') as f:
        f.seek(start_addr)
        code = f.read(count * 4)
    
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    for i in md.disasm(code, start_addr):
        print(f"  0x{i.address:08x}:  {i.bytes.hex():8}  {i.mnemonic:8} {i.op_str}")

print("=== Disassembly around 0x0030b8e0 (UnitLocal/DataLocal load) ===")
disasm_block(0x0030b8e0, 50)

print("\n=== Disassembly around 0x00310500 (DataLocal.pack loading) ===")
disasm_block(0x00310500, 50)
