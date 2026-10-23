"""
Official Battle Cats Pack Decryptor and Extractor.
Supports Traditional Chinese v15.6.1 (and all modern regions) AES-128-CBC packs and unencrypted ImageDataLocal.
"""

import os
import sys
import argparse
from typing import Dict, List, Tuple, Optional
from Crypto.Cipher import AES

LIST_KEY = b"b484857901742afc"
# CountryCode.TW AES-128-CBC key & IV (for local packs)
TW_PACK_KEY = bytes.fromhex("313d9858a7fb939def1d7d859629087d")
TW_PACK_IV  = bytes.fromhex("0e3743eb53bf5944d1ae7e10c2e54bdf")
# Server packs (CDN) AES-128-ECB key
SERVER_PACK_KEY = b"89a0f99078419c28"

class PackExtractor:
    def __init__(self, asset_dir: str = r"E:\rea\decompiled_src\game_assets\assets"):
        self.asset_dir = asset_dir

    def read_list(self, list_name: str) -> List[Tuple[str, int, int]]:
        list_path = os.path.join(self.asset_dir, list_name)
        if not os.path.isfile(list_path):
            raise FileNotFoundError(f"List file not found: {list_path}")

        with open(list_path, "rb") as f:
            cipher = AES.new(LIST_KEY, AES.MODE_ECB)
            raw = cipher.decrypt(f.read()).rstrip(b"\x00").decode("utf-8", errors="ignore")

        entries = []
        lines = [line.strip() for line in raw.splitlines() if line.strip()]
        for line in lines[1:]:
            parts = line.split(",")
            if len(parts) >= 3:
                entries.append((parts[0], int(parts[1]), int(parts[2])))
        return entries

    def _decrypt_chunk(self, chunk: bytes, pack_name: str) -> bytes:
        pn_lower = pack_name.lower()
        if "imagedatalocal" in pn_lower:
            return chunk

        if "server" in pn_lower:
            cipher = AES.new(SERVER_PACK_KEY, AES.MODE_ECB)
        else:
            cipher = AES.new(TW_PACK_KEY, AES.MODE_CBC, TW_PACK_IV)

        data = cipher.decrypt(chunk)
        pad_len = data[-1]
        if 1 <= pad_len <= 16 and data[-pad_len:] == bytes([pad_len]) * pad_len:
            data = data[:-pad_len]
        return data

    def extract_file(self, pack_name: str, target_filename: str, output_path: str) -> bool:
        list_name = pack_name.replace(".pack", ".list")
        entries = self.read_list(list_name)
        pack_path = os.path.join(self.asset_dir, pack_name)

        target_entry = None
        for fn, offset, size in entries:
            if fn.lower() == target_filename.lower():
                target_entry = (fn, offset, size)
                break

        if not target_entry:
            return False

        fn, offset, size = target_entry
        with open(pack_path, "rb") as f:
            f.seek(offset)
            chunk = f.read(size)

        data = self._decrypt_chunk(chunk, pack_name)

        os.makedirs(os.path.dirname(os.path.abspath(output_path)), exist_ok=True)
        with open(output_path, "wb") as f:
            f.write(data)
        return True

    def extract_pack(self, pack_name: str, output_dir: str, filter_ext: Optional[str] = None) -> int:
        list_name = pack_name.replace(".pack", ".list")
        entries = self.read_list(list_name)
        pack_path = os.path.join(self.asset_dir, pack_name)

        extracted_count = 0
        os.makedirs(output_dir, exist_ok=True)

        with open(pack_path, "rb") as f:
            for fn, offset, size in entries:
                if filter_ext and not fn.lower().endswith(filter_ext.lower()):
                    continue

                f.seek(offset)
                chunk = f.read(size)
                data = self._decrypt_chunk(chunk, pack_name)

                out_file = os.path.join(output_dir, fn)
                with open(out_file, "wb") as out_f:
                    out_f.write(data)
                extracted_count += 1

        return extracted_count

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Official Battle Cats Pack Extractor")
    parser.add_argument("--pack", type=str, required=True, help="Pack file name (e.g. DataLocal.pack)")
    parser.add_argument("--file", type=str, default="", help="Single file to extract")
    parser.add_argument("--out", type=str, required=True, help="Output destination path or directory")
    parser.add_argument("--ext", type=str, default="", help="Filter by extension")
    args = parser.parse_args()

    extractor = PackExtractor()
    if args.file:
        ok = extractor.extract_file(args.pack, args.file, args.out)
        print(f"Extracted {args.file}: {'SUCCESS' if ok else 'FAILED'}")
    else:
        cnt = extractor.extract_pack(args.pack, args.out, filter_ext=args.ext if args.ext else None)
        print(f"Extracted {cnt} files to {args.out}")
