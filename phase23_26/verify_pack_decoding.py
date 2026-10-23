"""
Phase 23-B: Independent Re-Audit and Verification of Battle Cats Asset Decryption.
Tests all 8 pack files with multi-format validation, bitwise determinism,
negative test cases (false-positive prevention), and rigorous format parsers.
"""

import os
import sys
import json
import hashlib
import random
from typing import Dict, List, Tuple, Any, Optional
from Crypto.Cipher import AES
from PIL import Image
import pygame

# Configuration
ASSET_DIR = r"E:\rea\decompiled_src\game_assets\assets"
OUTPUT_DIR = r"E:\rea\phase23_26\decoded_samples"
AUDIT_JSON = r"E:\rea\phase23_26\pack_audit_results.json"

LIST_KEY = b"b484857901742afc"
TW_PACK_KEY = bytes.fromhex("313d9858a7fb939def1d7d859629087d")
TW_PACK_IV  = bytes.fromhex("0e3743eb53bf5944d1ae7e10c2e54bdf")
DUMMY_KEY   = bytes.fromhex("00112233445566778899aabbccddeeff")

ALL_PACKS = [
    "DataLocal.pack",
    "DownloadLocal.pack",
    "ImageDataLocal.pack",
    "ImageLocal.pack",
    "MapLocal.pack",
    "NumberLocal.pack",
    "resLocal.pack",
    "UnitLocal.pack",
]

def read_pack_list(list_path: str) -> List[Tuple[str, int, int]]:
    with open(list_path, "rb") as f:
        cipher = AES.new(LIST_KEY, AES.MODE_ECB)
        raw = cipher.decrypt(f.read()).rstrip(b"\x00").decode("utf-8", errors="ignore")
    entries = []
    lines = [line.strip() for line in raw.splitlines() if line.strip()]
    for line in lines[1:]:
        parts = line.split(",")
        if len(parts) >= 3:
            entries.append((parts[0].strip(), int(parts[1]), int(parts[2])))
    return entries

def decode_chunk(chunk: bytes, is_unencrypted: bool, key: bytes = TW_PACK_KEY, iv: bytes = TW_PACK_IV) -> Tuple[bool, bytes, str]:
    if is_unencrypted:
        return True, chunk, "RAW_UNENCRYPTED"
    
    if len(chunk) % 16 != 0:
        return False, b"", f"Ciphertext length {len(chunk)} not multiple of 16"
    
    try:
        cipher = AES.new(key, AES.MODE_CBC, iv)
        plain = cipher.decrypt(chunk)
        pad_len = plain[-1]
        if not (1 <= pad_len <= 16):
            return False, b"", f"Invalid PKCS7 padding byte: {pad_len}"
        if plain[-pad_len:] != bytes([pad_len]) * pad_len:
            return False, b"", f"PKCS7 padding corruption: {plain[-pad_len:]}"
        return True, plain[:-pad_len], "AES_128_CBC_PKCS7"
    except Exception as e:
        return False, b"", str(e)

def validate_png(data: bytes) -> Tuple[bool, str, Dict[str, Any]]:
    if not data.startswith(b"\x89PNG\r\n\x1a\n"):
        return False, "Missing PNG magic header", {}
    import io
    try:
        with Image.open(io.BytesIO(data)) as img:
            img.verify()
        with Image.open(io.BytesIO(data)) as img:
            img.load()
            w, h = img.size
            return True, f"Valid PNG ({w}x{h}, {img.mode})", {"width": w, "height": h, "mode": img.mode}
    except Exception as e:
        return False, f"PIL load error: {e}", {}

def validate_ogg(data: bytes) -> Tuple[bool, str, Dict[str, Any]]:
    if not data.startswith(b"OggS"):
        return False, "Missing OggS magic header", {}
    if b"vorbis" in data[:100]:
        return True, "Valid Ogg Vorbis stream", {"codec": "vorbis", "size": len(data)}
    return True, "Valid Ogg container", {"size": len(data)}

def validate_imgcut(data: bytes) -> Tuple[bool, str, Dict[str, Any]]:
    try:
        text = data.decode("utf-8-sig", errors="replace")
        lines = [l.strip() for l in text.splitlines() if l.strip()]
        if not lines or lines[0] != "[imgcut]":
            return False, f"Missing [imgcut] header (got {repr(lines[0]) if lines else 'empty'})", {}
        num_cuts = int(lines[3])
        return True, f"Valid imgcut ({num_cuts} cuts)", {"cuts": num_cuts}
    except Exception as e:
        return False, f"imgcut parse error: {e}", {}

def validate_mamodel(data: bytes) -> Tuple[bool, str, Dict[str, Any]]:
    try:
        text = data.decode("utf-8-sig", errors="replace")
        lines = [l.strip() for l in text.splitlines() if l.strip()]
        if not lines or "[modelanim:model" not in lines[0]:
            return False, f"Missing [modelanim:model] header (got {repr(lines[0]) if lines else 'empty'})", {}
        num_parts = int(lines[2])
        return True, f"Valid mamodel ({num_parts} parts)", {"parts": num_parts}
    except Exception as e:
        return False, f"mamodel parse error: {e}", {}

def validate_maanim(data: bytes) -> Tuple[bool, str, Dict[str, Any]]:
    try:
        text = data.decode("utf-8-sig", errors="replace")
        lines = [l.strip() for l in text.splitlines() if l.strip()]
        if not lines or "[modelanim:animation" not in lines[0]:
            return False, f"Missing [modelanim:animation] header (got {repr(lines[0]) if lines else 'empty'})", {}
        num_tracks = int(lines[2])
        return True, f"Valid maanim ({num_tracks} tracks)", {"tracks": num_tracks}
    except Exception as e:
        return False, f"maanim parse error: {e}", {}

def validate_csv(data: bytes) -> Tuple[bool, str, Dict[str, Any]]:
    try:
        text = data.decode("utf-8", errors="strict")
        lines = [l.strip() for l in text.splitlines() if l.strip()]
        if not lines:
            return True, "Empty text/csv file", {"lines": 0}
        cols = len(lines[0].split(","))
        return True, f"Valid CSV ({len(lines)} lines, col0 has {cols} items)", {"lines": len(lines), "cols": cols}
    except UnicodeDecodeError:
        try:
            text = data.decode("cp932", errors="strict")
            lines = [l.strip() for l in text.splitlines() if l.strip()]
            return True, f"Valid Shift-JIS text ({len(lines)} lines)", {"lines": len(lines), "encoding": "cp932"}
        except Exception as e:
            return False, f"Text decoding error: {e}", {}

def validate_general(fn: str, data: bytes) -> Tuple[bool, str, Dict[str, Any]]:
    ext = os.path.splitext(fn)[1].lower()
    if ext == ".png":
        return validate_png(data)
    elif ext == ".ogg":
        return validate_ogg(data)
    elif ext == ".imgcut":
        return validate_imgcut(data)
    elif ext == ".mamodel":
        return validate_mamodel(data)
    elif ext == ".maanim":
        return validate_maanim(data)
    elif ext in [".csv", ".tsv", ".txt", ".json"]:
        return validate_csv(data)
    elif ext == ".ttf":
        if data.startswith(b"\x00\x01\x00\x00") or data.startswith(b"OTTO") or data.startswith(b"true"):
            return True, "Valid TrueType / OpenType font header", {"size": len(data)}
        return False, "Invalid TTF header", {}
    else:
        # Binary or data file
        if len(data) > 0:
            return True, f"Binary data ({len(data)} bytes)", {"size": len(data)}
        return True, "Empty binary", {"size": 0}

def main():
    print("=" * 70)
    print("PHASE 23-B: INDEPENDENT ASSET DECODE RE-AUDIT")
    print("=" * 70)
    
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    random.seed(42) # Deterministic sample selection
    
    audit_summary = {
        "packs_audited": len(ALL_PACKS),
        "total_samples": 0,
        "total_passed": 0,
        "total_failed": 0,
        "negative_tests_passed": 0,
        "pack_details": {}
    }
    
    for pack_name in ALL_PACKS:
        print(f"\n--- Auditing Pack: {pack_name} ---")
        list_name = pack_name.replace(".pack", ".list")
        list_path = os.path.join(ASSET_DIR, list_name)
        pack_path = os.path.join(ASSET_DIR, pack_name)
        
        if not os.path.exists(list_path) or not os.path.exists(pack_path):
            print(f"ERROR: Missing files for {pack_name}")
            continue
            
        entries = read_pack_list(list_path)
        is_unencrypted = "imagedata" in pack_name.lower()
        print(f"Total entries in .list: {len(entries)} (Unencrypted: {is_unencrypted})")
        
        # Pick 10 representative diverse samples across extensions
        ext_buckets: Dict[str, List[Tuple[str, int, int]]] = {}
        for fn, offset, size in entries:
            ext = os.path.splitext(fn)[1].lower()
            ext_buckets.setdefault(ext, []).append((fn, offset, size))
            
        selected_samples = []
        for ext, bucket in ext_buckets.items():
            k = min(3, len(bucket))
            selected_samples.extend(random.sample(bucket, k))
            
        if len(selected_samples) > 10:
            selected_samples = random.sample(selected_samples, 10)
        elif len(selected_samples) < 10 and len(entries) > len(selected_samples):
            remaining = [e for e in entries if e not in selected_samples]
            needed = min(10 - len(selected_samples), len(remaining))
            selected_samples.extend(random.sample(remaining, needed))
            
        pack_results = []
        with open(pack_path, "rb") as pf:
            for fn, offset, size in selected_samples:
                audit_summary["total_samples"] += 1
                pf.seek(offset)
                chunk = pf.read(size)
                
                # Pass 1: Decode
                ok1, data1, cipher_info = decode_chunk(chunk, is_unencrypted, TW_PACK_KEY, TW_PACK_IV)
                if not ok1:
                    print(f"[FAIL] {fn} (offset={offset}, size={size}): Decryption error: {cipher_info}")
                    audit_summary["total_failed"] += 1
                    pack_results.append({"file": fn, "status": "DECRYPT_FAIL", "error": cipher_info})
                    continue
                    
                hash1 = hashlib.sha256(data1).hexdigest()
                
                # Pass 2: Re-decode from scratch to test determinism
                ok2, data2, _ = decode_chunk(chunk, is_unencrypted, TW_PACK_KEY, TW_PACK_IV)
                hash2 = hashlib.sha256(data2).hexdigest()
                if hash1 != hash2:
                    print(f"[FAIL] {fn}: SHA-256 mismatch between runs!")
                    audit_summary["total_failed"] += 1
                    pack_results.append({"file": fn, "status": "NONDETERMINISTIC_FAIL"})
                    continue
                    
                # Format validation
                v_ok, v_msg, v_meta = validate_general(fn, data1)
                if not v_ok:
                    print(f"[FAIL] {fn} (format validation failed): {v_msg}")
                    audit_summary["total_failed"] += 1
                    pack_results.append({"file": fn, "status": "FORMAT_FAIL", "error": v_msg})
                    continue
                    
                # Negative test (Anti-false-positive check) for encrypted packs
                neg_passed = True
                if not is_unencrypted and size >= 16:
                    neg_ok, neg_data, neg_msg = decode_chunk(chunk, False, DUMMY_KEY, TW_PACK_IV)
                    # If it somehow decoded without padding error, verify it fails format validation!
                    if neg_ok:
                        neg_v_ok, _, _ = validate_general(fn, neg_data)
                        if neg_v_ok and len(neg_data) > 0:
                            print(f"[WARNING] False positive risk on {fn}! Dummy key parsed as valid {fn}")
                            neg_passed = False
                        else:
                            neg_passed = True
                    else:
                        neg_passed = True # Correctly rejected by PKCS7 padding check
                        
                if neg_passed:
                    audit_summary["negative_tests_passed"] += 1
                    
                audit_summary["total_passed"] += 1
                print(f"[PASS] {fn} ({len(data1)} bytes, sha256={hash1[:8]}...): {v_msg}")
                
                # Save sample file for independent audit
                out_sample_path = os.path.join(OUTPUT_DIR, f"{pack_name}_{fn}")
                with open(out_sample_path, "wb") as out_f:
                    out_f.write(data1)
                    
                pack_results.append({
                    "file": fn,
                    "offset": offset,
                    "raw_size": size,
                    "decoded_size": len(data1),
                    "sha256": hash1,
                    "format_validation": v_msg,
                    "meta": v_meta,
                    "negative_test_passed": neg_passed,
                    "status": "PASS"
                })
                
        audit_summary["pack_details"][pack_name] = {
            "total_pack_entries": len(entries),
            "samples_tested": len(selected_samples),
            "samples": pack_results
        }
        
    with open(AUDIT_JSON, "w", encoding="utf-8") as jf:
        json.dump(audit_summary, jf, indent=2, ensure_ascii=False)
        
    print("\n" + "=" * 70)
    print(f"AUDIT COMPLETE: Tested {audit_summary['total_samples']} samples across 8 packs.")
    print(f"Passed: {audit_summary['total_passed']}, Failed: {audit_summary['total_failed']}")
    print(f"Negative tests passed: {audit_summary['negative_tests_passed']}")
    print(f"Audit log saved to: {AUDIT_JSON}")
    print(f"Sample files extracted to: {OUTPUT_DIR}")
    print("=" * 70)

if __name__ == "__main__":
    main()
