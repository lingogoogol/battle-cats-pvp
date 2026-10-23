import struct, sys

def parse_dynsym(path):
    with open(path, 'rb') as f:
        data = f.read()
    
    e_shoff = struct.unpack('<Q', data[40:48])[0]
    e_shentsize = struct.unpack('<H', data[58:60])[0]
    e_shnum = struct.unpack('<H', data[60:62])[0]
    e_shstrndx = struct.unpack('<H', data[62:64])[0]
    
    shstr_hdr = data[e_shoff + e_shstrndx * e_shentsize : e_shoff + (e_shstrndx + 1) * e_shentsize]
    shstr_offset = struct.unpack('<Q', shstr_hdr[24:32])[0]
    shstr_size = struct.unpack('<Q', shstr_hdr[32:40])[0]
    shstrtab = data[shstr_offset:shstr_offset+shstr_size]
    
    dynsym_info = None
    dynstr_info = None
    
    for i in range(e_shnum):
        hdr = data[e_shoff + i * e_shentsize : e_shoff + (i + 1) * e_shentsize]
        sh_name_idx = struct.unpack('<I', hdr[0:4])[0]
        sh_name = shstrtab[sh_name_idx:].split(b'\x00')[0].decode('latin1', errors='ignore')
        sh_offset = struct.unpack('<Q', hdr[24:32])[0]
        sh_size = struct.unpack('<Q', hdr[32:40])[0]
        sh_entsize = struct.unpack('<Q', hdr[56:64])[0]
        if sh_name == '.dynsym':
            dynsym_info = (sh_offset, sh_size, sh_entsize)
        elif sh_name == '.dynstr':
            dynstr_info = (sh_offset, sh_size)
            
    dynsym_offset, dynsym_size, dynsym_entsize = dynsym_info
    dynstr_offset, dynstr_size = dynstr_info
    dynstr = data[dynstr_offset:dynstr_offset+dynstr_size]
    
    jni_symbols = []
    num_symbols = dynsym_size // dynsym_entsize
    for i in range(num_symbols):
        sym_entry = data[dynsym_offset + i * dynsym_entsize : dynsym_offset + (i + 1) * dynsym_entsize]
        st_name = struct.unpack('<I', sym_entry[0:4])[0]
        st_value = struct.unpack('<Q', sym_entry[8:16])[0]
        st_size = struct.unpack('<Q', sym_entry[16:24])[0]
        
        name = dynstr[st_name:].split(b'\x00')[0].decode('latin1', errors='ignore')
        if name.startswith('Java_jp_co_ponos'):
            jni_symbols.append((name, st_value, st_size))
            
    return jni_symbols

symbols = parse_dynsym(r'E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so')
print(f'Total JNI Symbols Found: {len(symbols)}')
print('| Symbol Name | Virtual Address | Size (Bytes) |')
print('| --- | --- | --- |')
for name, val, sz in sorted(symbols, key=lambda x: x[1]):
    print(f'| `{name}` | `0x{val:08x}` | {sz} |')
