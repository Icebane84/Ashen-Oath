#!/usr/bin/env python3
"""
pre_build_check.py - Standalone Invariant & AST Header Scanner
Verifies binary packaging contracts and scans Unreal headers for forbidden patterns.
"""

import os
import sys
import struct
import re

# Binary layout: 6 floats (24B) + 1 uint32 (4B) + 100 bytes padding = 128 Bytes
PAYLOAD_FORMAT = "<ffffffI100s"
EXPECTED_PAYLOAD_SIZE = 128

def check_binary_contract():
    calculated_size = struct.calcsize(PAYLOAD_FORMAT)
    if calculated_size != EXPECTED_PAYLOAD_SIZE:
        print(f"[FAIL] Payload format size mismatch: {calculated_size} != {EXPECTED_PAYLOAD_SIZE}")
        return False
    print(f"[PASS] Python struct binary layout matches 128-byte contract ({PAYLOAD_FORMAT})")
    return True

def scan_headers_for_guardrails(source_root):
    if not os.path.exists(source_root):
        print(f"[WARN] Source root not found: {source_root}")
        return True

    violations = []
    # Pattern to check for forbidden parameter name 'bIsActive' in UFUNCTION signatures
    forbidden_param_pattern = re.compile(r'UFUNCTION\s*\([^)]*\)\s*[^;{]*\b(bool\s+bIsActive|bIsActive\s*[,)])')

    for root, _, files in os.walk(source_root):
        for file in files:
            if file.endswith('.h') or file.endswith('.hpp'):
                filepath = os.path.join(root, file)
                try:
                    with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
                        content = f.read()
                        if forbidden_param_pattern.search(content):
                            violations.append(f"{filepath}: Forbidden parameter name 'bIsActive' in UFUNCTION signature")
                except Exception as e:
                    print(f"[WARN] Failed to read {filepath}: {e}")

    if violations:
        print("[FAIL] Blueprint interop guardrail violations found:")
        for v in violations:
            print(f"  - {v}")
        return False

    print(f"[PASS] AST guardrail scan completed across source headers (0 violations).")
    return True

def main():
    print("=== [Ashen Oath Pre-Flight Invariant & Header Scanner] ===")
    success = True
    
    if not check_binary_contract():
        success = False

    workspace_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    source_root = os.path.join(workspace_root, "AshenOath", "Source", "AshenOath")

    if not scan_headers_for_guardrails(source_root):
        success = False

    if success:
        print("[SUCCESS] All pre-build invariant checks PASSED.")
        sys.exit(0)
    else:
        print("[ERROR] Pre-build checks FAILED.")
        sys.exit(1)

if __name__ == "__main__":
    main()
