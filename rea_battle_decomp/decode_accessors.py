import capstone, struct

with open(r"E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so", "rb") as f:
    data = f.read()

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)

# Find all BL targets in [0x957800..0x96b600]
targets = set()
for start, end in [(0x5c731c, 0x5df500), (0x4c3f24, 0x4c7000), (0x8b6dec, 0x8bb000), (0x90ebc4, 0x918000)]:
    for pc in range(start, end, 4):
        w = struct.unpack("<I", data[pc:pc+4])[0]
        if (w & 0xFC000000) == 0x94000000:
            imm = w & 0x03FFFFFF
            if imm & (1 << 25): imm -= (1 << 26)
            dest = pc + (imm << 2)
            if 0x957800 <= dest <= 0x96c000:
                targets.add(dest)

with open(r"E:\rea\rea_battle_decomp\accessor_map.txt", "w", encoding="utf-8") as out:
    for addr in sorted(targets):
        insns = []
        for ins in md.disasm(data[addr:addr+0x140], addr):
            insns.append(ins)
            if ins.mnemonic == "ret":
                break
        # extract constants like #0x80000 / #0x3908 / #0xc738 / #0x3e8
        mov_w9 = {}
        offsets = []
        strides = []
        ops = []
        for i, ins in enumerate(insns):
            s = f"{ins.mnemonic} {ins.op_str}"
            if "#0xc738" in ins.op_str:
                strides.append("team*51000")
            if "#0x3e8" in ins.op_str:
                strides.append("slot*1000")
            if "#0x1f0" in ins.op_str:
                strides.append("team*0x1f0")
            if ins.mnemonic == "mov" and ", #0x" in ins.op_str:
                reg, imm = ins.op_str.split(", #")
                mov_w9[reg.strip()] = int(imm, 16)
            elif ins.mnemonic == "movk" and "lsl #16" in ins.op_str:
                parts = ins.op_str.split(",")
                reg = parts[0].strip()
                imm = int(parts[1].strip().lstrip("#"), 16) << 16
                mov_w9[reg] = mov_w9.get(reg, 0) + imm
                offsets.append(hex(mov_w9[reg]))
            elif ins.mnemonic in ("ldr", "str", "ldrb", "strb", "ldrh", "strh", "ldrsw", "add", "sub") and "sp" not in ins.op_str:
                if ins.mnemonic in ("ldr", "str", "ldrb", "strb"):
                    ops.append(s)
        out.write(f"0x{addr:08x} (Ghidra 0x{addr+0x100000:08x}) | len={len(insns):2d} | stride={','.join(sorted(set(strides))):20s} | off={','.join(offsets):18s} | ops={' ; '.join(ops[:4])}\n")

print(f"Decoded {len(targets)} accessors to accessor_map.txt")
