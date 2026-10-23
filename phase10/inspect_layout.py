import capstone

SO_PATH = r'E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so'

with open(SO_PATH, 'rb') as f:
    f.seek(0x959800)
    code = f.read(0xa00)

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
insns = list(md.disasm(code, 0x959800))

print(f"Total disassembled instructions: {len(insns)}")

# Let's group into functions separated by 'ret'
funcs = []
current = []
for insn in insns:
    current.append(insn)
    if insn.mnemonic == 'ret':
        funcs.append(current)
        current = []

print(f"Total functions identified: {len(funcs)}")

for idx, f in enumerate(funcs):
    start_addr = f[0].address
    end_addr = f[-1].address
    # Look for mov w9 / movk w9, and ldr/str
    offset_val = None
    access_insn = None
    stride_team = None
    stride_unit = None
    for insn in f:
        if insn.mnemonic == 'mov' and '0xc738' in insn.op_str:
            stride_team = 0xc738
        if insn.mnemonic == 'mov' and '0x3e8' in insn.op_str:
            stride_unit = 0x3e8

        if insn.mnemonic in ['ldr', 'str', 'ldrb', 'strb', 'ldrh', 'strh', 'cset']:
            if '[x8, x9]' in insn.op_str or '[x8]' in insn.op_str or insn.mnemonic == 'cset':
                access_insn = f"{insn.mnemonic} {insn.op_str}"
                
    # Calculate constant offset if mov + movk were used
    val = None
    for i in range(len(f)-1):
        if f[i].mnemonic == 'mov' and ('w9' in f[i].op_str or 'w10' in f[i].op_str):
            if f[i+1].mnemonic == 'movk' and ('w9' in f[i+1].op_str or 'w10' in f[i+1].op_str):
                try:
                    low_str = f[i].op_str.split(',')[1].strip().lstrip('#')
                    low = int(low_str, 0)
                    high_part = f[i+1].op_str.split(',')[1].strip().lstrip('#')
                    high = int(high_part.split()[0], 0)
                    val = (high << 16) | low
                except Exception as e:
                    pass
    print(f"Func #{idx:02d} [0x{start_addr:08x} - 0x{end_addr:08x}]: StrideTeam={stride_team} StrideUnit={stride_unit} ConstOffset={(hex(val) if val is not None else 'None')} Access={access_insn}")
