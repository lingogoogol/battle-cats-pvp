import os
import hashlib

SO_PATH = r'E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so'
EXPECTED_SHA256 = '6f821c3cba94f96d34e1b2c501a482c0887daf71e68328722a58a456cb6baa0f'

def verify_and_extract_bytes(offset: int, size: int) -> bytes:
    assert os.path.exists(SO_PATH), f"Target SO not found: {SO_PATH}"
    
    # Verify hash of SO
    with open(SO_PATH, 'rb') as f:
        data = f.read()
    actual_hash = hashlib.sha256(data).hexdigest()
    assert actual_hash.lower() == EXPECTED_SHA256.lower(), f"SHA-256 mismatch! {actual_hash} != {EXPECTED_SHA256}"
    
    # Extract exact byte slice
    slice_bytes = data[offset : offset + size]
    assert len(slice_bytes) == size, f"Expected {size} bytes, got {len(slice_bytes)}"
    return slice_bytes

# Block Definitions:
# 1. Magic division: 0x004c6800 to 0x004c6820 (32 bytes)
BLOCK_MAGIC_DIV = {
    'name': 'magic_div_permille',
    'offset': 0x004c6800,
    'size': 0x20,
    'expected_hex': '097c171b68ba895221008052480ca272287d289b09fd7fd308fd66931701090b'
}

# 2. HP Address Calc and Read: 0x00959894 to 0x009598b0 (28 bytes)
BLOCK_HP_READ = {
    'name': 'hp_address_read',
    'offset': 0x00959894,
    'size': 0x1c,
    'expected_hex': '08e79852097d80528802289b6822299b092c87520901a072006969b8'
}

# 3. HP Address Calc and Write: 0x009598dc to 0x009598f8 (28 bytes)
BLOCK_HP_WRITE = {
    'name': 'hp_address_write',
    'offset': 0x009598dc,
    'size': 0x1c,
    'expected_hex': '08e79852097d8052a802289b8822299b092c87520901a072136929b8'
}

if __name__ == '__main__':
    print(f"Verifying SO at: {SO_PATH}")
    for blk in [BLOCK_MAGIC_DIV, BLOCK_HP_READ, BLOCK_HP_WRITE]:
        extracted = verify_and_extract_bytes(blk['offset'], blk['size'])
        assert extracted.hex() == blk['expected_hex'], f"Hex mismatch for {blk['name']}!"
        print(f"[*] Verified block '{blk['name']}': {len(extracted)} bytes @ 0x{blk['offset']:08x} (MATCH)")
