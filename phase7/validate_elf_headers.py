import struct
from elftools.elf.elffile import ELFFile

so_path = r'E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so'

with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    header = elf.header
    
    print("=== ELF Header Analysis ===")
    print(f"ELF Magic:            {header['e_ident']['EI_MAG']}")
    print(f"Class:                {header['e_ident']['EI_CLASS']} (ELF64)")
    print(f"Data:                 {header['e_ident']['EI_DATA']} (2's complement, little endian)")
    print(f"OS/ABI:               {header['e_ident']['EI_OSABI']}")
    print(f"Type:                 {header['e_type']} (Shared object file)")
    print(f"Machine:              {header['e_machine']} (AArch64 - ARM 64-bit)")
    print(f"Version:              {header['e_version']}")
    print(f"Entry point:          0x{header['e_entry']:08x}")
    print(f"Flags:                0x{header['e_flags']:08x}")
    
    print("\n=== Program Headers (Segments) ===")
    print("| Type | Offset | VirtAddr | PhysAddr | FileSiz | MemSiz | Flags | Align |")
    print("| --- | --- | --- | --- | --- | --- | --- | --- |")
    for seg in elf.iter_segments():
        flags = []
        if seg['p_flags'] & 4: flags.append('R')
        if seg['p_flags'] & 2: flags.append('W')
        if seg['p_flags'] & 1: flags.append('E')
        flag_str = ''.join(flags)
        print(f"| {seg['p_type']} | 0x{seg['p_offset']:x} | 0x{seg['p_vaddr']:x} | 0x{seg['p_paddr']:x} | {seg['p_filesz']:,} | {seg['p_memsz']:,} | {flag_str} | {seg['p_align']} |")
        
    print("\n=== Key Sections ===")
    print("| Section Name | Type | VirtAddr (VMA) | File Offset | Size | Flags | Align |")
    print("| --- | --- | --- | --- | --- | --- | --- |")
    for sec in elf.iter_sections():
        if sec.name in ('.text', '.rodata', '.data', '.bss', '.dynsym', '.dynstr', '.got', '.plt'):
            flags = []
            if sec['sh_flags'] & 1: flags.append('WRITE')
            if sec['sh_flags'] & 2: flags.append('ALLOC')
            if sec['sh_flags'] & 4: flags.append('EXEC')
            flag_str = ' '.join(flags)
            print(f"| `{sec.name}` | {sec['sh_type']} | `0x{sec['sh_addr']:08x}` | `0x{sec['sh_offset']:08x}` | {sec['sh_size']:,} | {flag_str} | {sec['sh_addralign']} |")

    # Address validation test on reported addresses
    test_addrs = [
        ("battleCheckLogic string", 0x001c11a1),
        ("battle_createButton string", 0x001bf6ba),
        ("battle_initWin string", 0x001befe1),
        ("MyActivity_appInit code", 0x00309c5c),
        ("MyActivity_appUpdateDraw code", 0x00309d2c),
        ("MyActivity_fsInit code", 0x00309e10),
    ]
    
    print("\n=== Address Validation Test ===")
    print("| Target Label | Virtual Address | Alignment (mod 4) | Containing Section | Permitted Executable? | Conclusion |")
    print("| --- | --- | --- | --- | --- | --- |")
    
    rodata = elf.get_section_by_name('.rodata')
    text = elf.get_section_by_name('.text')
    
    for label, addr in test_addrs:
        mod4 = addr % 4
        sec_name = "UNKNOWN"
        is_exec = False
        for sec in elf.iter_sections():
            if sec['sh_addr'] <= addr < sec['sh_addr'] + sec['sh_size']:
                sec_name = sec.name
                is_exec = bool(sec['sh_flags'] & 4)
                break
        
        valid_code = (mod4 == 0) and is_exec
        conclusion = "Valid AArch64 Code Entry" if valid_code else "INVALID Code Entry (Data / String)"
        print(f"| {label} | `0x{addr:08x}` | {mod4} | `{sec_name}` | {is_exec} | **{conclusion}** |")
