import os
import re
import struct

SO_PATH = r"E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so"
ACC_MAP = r"E:\rea\rea_battle_decomp\accessor_map.txt"
IN_DIR = r"E:\rea\rea_battle_decomp\c_out_batch2"
OUT_DIR = r"E:\rea\rea_battle_decomp\c_out_batch2_annot"

def load_so():
    with open(SO_PATH, "rb") as f:
        data = f.read()
    return data

def load_accessors():
    acc = {}
    with open(ACC_MAP, "r", encoding="utf-8") as f:
        for line in f:
            # 0x00957800 (Ghidra 0x00a57800) | len=16 | stride=... | off=0x839xx | ops=...
            m = re.match(r"0x([0-9a-fA-F]+)\s+\(Ghidra 0x([0-9a-fA-F]+)\)\s+\|\s+len=(\d+)\s+\|\s+stride=([^|]*)\|\s+off=([^|]*)\|\s+ops=(.*)", line.strip())
            if m:
                vma = int(m.group(1), 16)
                gaddr = int(m.group(2), 16)
                stride = m.group(4).strip()
                off = m.group(5).strip()
                ops = m.group(6).strip()
                acc[gaddr] = (vma, stride, off, ops)
    return acc

def read_rodata_str(so, elf_vma):
    # Check ELF PT_LOAD: file_offset == vma for PT_LOAD[1] (.rodata is at 0x1889c0..0x1f4384)
    if elf_vma < 0x1889c0 or elf_vma >= 0x1f4384:
        return None
    end = so.find(b"\x00", elf_vma, elf_vma + 128)
    if end == -1:
        end = elf_vma + 32
    raw = so[elf_vma:end]
    try:
        s = raw.decode("utf-8")
        if s and all(32 <= ord(c) < 127 or c in "\n\t" for c in s):
            return s
    except UnicodeDecodeError:
        pass
    # Also show 4/8 bytes hex/int/float if not printable ASCII
    if elf_vma + 8 <= len(so):
        u32 = struct.unpack_from("<I", so, elf_vma)[0]
        f32 = struct.unpack_from("<f", so, elf_vma)[0]
        return f"u32=0x{u32:x}({u32}) f32={f32:.4g}"
    return None

def decode_ascii_hex(val_str):
    try:
        v = int(val_str, 16)
    except ValueError:
        return None
    if v < 0x10000:
        return None
    b = v.to_bytes(8, "little").rstrip(b"\x00")
    if len(b) >= 4 and all(32 <= x < 127 for x in b):
        return b.decode("ascii")
    return None

def main():
    so = load_so()
    acc = load_accessors()
    os.makedirs(OUT_DIR, exist_ok=True)
    call_counts = {}

    for fname in sorted(os.listdir(IN_DIR)):
        if not fname.endswith(".c"):
            continue
        in_path = os.path.join(IN_DIR, fname)
        with open(in_path, "r", encoding="utf-8") as f:
            lines = f.readlines()

        out_lines = []
        for line in lines:
            notes = []
            # Find func_0x00xxxxxx calls
            for m in re.finditer(r"func_0x([0-9a-fA-F]+)", line):
                gaddr = int(m.group(1), 16)
                vma = gaddr - 0x100000
                call_counts[vma] = call_counts.get(vma, 0) + 1
                if gaddr in acc:
                    _, stride, off, ops = acc[gaddr]
                    notes.append(f"0x{vma:x}:[{stride}|off={off}|{ops}]")
            # Find UNK_00xxxxxx
            for m in re.finditer(r"UNK_00([0-9a-fA-F]+)", line):
                gaddr = int(m.group(1), 16)
                elf_vma = gaddr - 0x100000
                s = read_rodata_str(so, elf_vma)
                if s:
                    notes.append(f"UNK_{gaddr:06x}(vma=0x{elf_vma:x})={repr(s)}")
                elif gaddr >= 0x300000:
                    notes.append(f"field_off=0x{gaddr:x}")
            # Find 64-bit hex constants
            for m in re.finditer(r"\b0x([0-9a-fA-F]{8,16})\b", line):
                s = decode_ascii_hex(m.group(1))
                if s:
                    notes.append(f"ascii({m.group(0)})={repr(s)}")

            if notes:
                out_lines.append(line.rstrip("\n") + "  /* " + " ; ".join(notes) + " */\n")
            else:
                out_lines.append(line)

        with open(os.path.join(OUT_DIR, fname), "w", encoding="utf-8") as f:
            f.writelines(out_lines)

    # Print top non-accessor, non-runtime callees
    summary_path = os.path.join(OUT_DIR, "_callees.txt")
    with open(summary_path, "w", encoding="utf-8") as f:
        for vma, cnt in sorted(call_counts.items(), key=lambda x: -x[1]):
            gaddr = vma + 0x100000
            tag = "ACCESSOR" if gaddr in acc else "FUNC"
            extra = f" off={acc[gaddr][2]} ({acc[gaddr][1]})" if gaddr in acc else ""
            f.write(f"0x{vma:08x} (Ghidra 0x{gaddr:08x}) | count={cnt:4d} | {tag}{extra}\n")
    print(f"Annotated files written to {OUT_DIR}, {len(call_counts)} unique callees logged.")

if __name__ == "__main__":
    main()
