import struct
with open(r"E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so", "rb") as f:
    eh = f.read(64)
    e_phoff, e_shoff = struct.unpack("<QQ", eh[32:48])
    e_phentsize, e_phnum, e_shentsize, e_shnum, e_shstrndx = struct.unpack("<HHHHH", eh[54:64])
    for i in range(e_phnum):
        f.seek(e_phoff + i * e_phentsize)
        p_type, p_flags, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_align = struct.unpack("<IIQQQQQQ", f.read(56))
        if p_type == 1:
            print(f"PT_LOAD[{i}]: p_offset=0x{p_offset:x}, p_vaddr=0x{p_vaddr:x}, p_filesz=0x{p_filesz:x}, p_memsz=0x{p_memsz:x}, flags=0x{p_flags:x}")
    f.seek(e_shoff + e_shstrndx * e_shentsize)
    shstr_hdr = struct.unpack("<IIQQQQIIQQ", f.read(64))
    f.seek(shstr_hdr[4])
    shstr = f.read(shstr_hdr[5])
    for i in range(e_shnum):
        f.seek(e_shoff + i * e_shentsize)
        sh = struct.unpack("<IIQQQQIIQQ", f.read(64))
        name = shstr[sh[0]:].split(b'\x00')[0].decode('ascii', 'replace')
        if name in [".text", ".rodata", ".bss", ".plt", ".data", ".data.rel.ro"]:
            print(f"SEC {name:12s}: sh_addr=0x{sh[3]:x}, sh_offset=0x{sh[4]:x}, sh_size=0x{sh[5]:x}")
