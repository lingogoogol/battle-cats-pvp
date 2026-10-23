import capstone

def disassemble_func(path, start_addr, count=50):
    with open(path, 'rb') as f:
        f.seek(start_addr)
        code = f.read(count * 4)
    
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    for i in md.disasm(code, start_addr):
        print(f"  0x{i.address:08x}:  {i.bytes.hex():8}  {i.mnemonic:8} {i.op_str}")

disassemble_func(r"E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so", 0x450dc8, 40)
