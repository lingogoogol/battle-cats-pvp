import re
import struct
import capstone
from elftools.elf.elffile import ELFFile

so_path = r'E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so'

with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    text_sec = elf.get_section_by_name('.text')
    rodata_sec = elf.get_section_by_name('.rodata')
    
    text_addr = text_sec['sh_addr']
    text_size = text_sec['sh_size']
    text_offset = text_sec['sh_offset']
    
    rodata_addr = rodata_sec['sh_addr']
    rodata_size = rodata_sec['sh_size']
    rodata_offset = rodata_sec['sh_offset']
    
    f.seek(rodata_offset)
    rodata_data = f.read(rodata_size)
    
    f.seek(text_offset)
    text_data = f.read(text_size)

print(f".text:  vma=0x{text_addr:x}, size={text_size:,} bytes")
print(f".rodata: vma=0x{rodata_addr:x}, size={rodata_size:,} bytes")

# 1. Search for key Battle strings in .rodata
battle_keywords = [
    b'battle_initWin',
    b'battle_createBu',
    b'battleCheckLogi',
    b'showBattleResum',
    b'BattleTextureContext',
    b'BattleButton',
    b'BattleInit',
    b'BattleContinue',
    b'BattleXPx2',
    b'BattleStartSE',
    b'BattleFinishWinSE',
    b'BattleFinishLoseSE',
    b'DataLocal.pack',
    b'DataLocal.list',
    b'UnitLocal.pack',
    b'UnitLocal.list',
    b'AbilityData.csv',
    b'Adreward_table.csv',
    b'CC_AllParts_status.csv'
]

string_addrs = {}
for kw in battle_keywords:
    pos = 0
    while True:
        idx = rodata_data.find(kw, pos)
        if idx == -1:
            break
        vma = rodata_addr + idx
        string_addrs[vma] = kw.decode('latin1', errors='ignore')
        pos = idx + len(kw)

print(f"\nFound {len(string_addrs)} string occurrences in .rodata:")
for vma, name in sorted(string_addrs.items()):
    print(f"  0x{vma:08x}: {name}")

# 2. Find xrefs in .text using Capstone
# We scan for adrp instructions that target the page of these strings
string_pages = set((vma >> 12) for vma in string_addrs.keys())

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail = True

print(f"\nScanning .text for xrefs to target pages ({len(string_pages)} unique pages)...")
xrefs = []

# Process in chunks of 64KB for speed
chunk_size = 65536
for offset in range(0, text_size, chunk_size):
    chunk = text_data[offset:offset+chunk_size]
    chunk_vma = text_addr + offset
    for insn in md.disasm(chunk, chunk_vma):
        if insn.mnemonic == 'adrp':
            # op_str format: xN, #0xXXXXX000
            target_page = int(insn.op_str.split('#')[1], 16) >> 12
            if target_page in string_pages:
                xrefs.append((insn.address, insn.op_str))

print(f"Total potential ADRP xrefs found: {len(xrefs)}")
for addr, op in xrefs[:30]:
    print(f"  0x{addr:08x}: adrp {op}")
