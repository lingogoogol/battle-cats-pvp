from elftools.elf.elffile import ELFFile
import struct
import capstone

so_path = r'E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so'

targets = {
    0x001c11a1: "battleCheckLogic",
    0x001bf6ba: "battle_createButton",
    0x001befe1: "battle_initWin",
}

with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    
    # 1. Search for 64-bit pointer references across the entire ELF
    print("=== Scanning 64-bit Pointer References in Data Sections ===")
    for sec in elf.iter_sections():
        if sec['sh_type'] in ('SHT_PROGBITS', 'SHT_INIT_ARRAY'):
            sec_data = sec.data()
            sec_vma = sec['sh_addr']
            for offset in range(0, len(sec_data) - 7, 8):
                val = struct.unpack('<Q', sec_data[offset:offset+8])[0]
                if val in targets:
                    ref_vma = sec_vma + offset
                    print(f"Pointer at 0x{ref_vma:08x} in section `{sec.name}` points to `{targets[val]}` (0x{val:08x})")

    # 2. Search for ADRP + ADD/LDR references in .text
    print("\n=== Scanning ADRP + ADD/LDR in .text ===")
    text = elf.get_section_by_name('.text')
    text_vma = text['sh_addr']
    text_data = text.data()
    
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    insns = list(md.disasm(text_data, text_vma))
    
    for i in range(len(insns) - 1):
        i1 = insns[i]
        i2 = insns[i+1]
        if i1.mnemonic == 'adrp':
            page = int(i1.op_str.split('#')[1], 16)
            reg1 = i1.op_str.split(',')[0].strip()
            if i2.mnemonic in ('add', 'ldr'):
                parts = [p.strip() for p in i2.op_str.split(',')]
                if len(parts) >= 3 and parts[1] == reg1:
                    try:
                        off = int(parts[2].replace('#', '').replace(']', ''), 16)
                        target = page + off
                        if target in targets:
                            print(f"Code xref at 0x{i1.address:08x} in .text points to `{targets[target]}` (0x{target:08x})")
                            print(f"  0x{i1.address:08x}: {i1.mnemonic} {i1.op_str}")
                            print(f"  0x{i2.address:08x}: {i2.mnemonic} {i2.op_str}")
                    except Exception:
                        pass
