#!/usr/bin/env python3
"""
symbol_verifier.py — API surface gate for Ashen Oath.

Cross-references C++ method call sites in source files against a manifest of
confirmed-real / confirmed-hallucinated symbols per Unreal Engine 5.8 class.

Outcomes per call site:
  PASS       - method is in known_methods
  CRITICAL   - method is in known_hallucinated (previously confirmed fake)
  UNVERIFIED - method is in neither list
"""

import argparse
import json
import os
import re
import sys
from dataclasses import dataclass, asdict
from pathlib import Path

MEMBER_DECL_RE = re.compile(
    r'(?:TObjectPtr<\s*([A-Za-z0-9_]+)\s*>|([A-Za-z0-9_]+)\s*\*)\s*([A-Za-z_][A-Za-z0-9_]*)\s*;'
)
LOCAL_DECL_RE = re.compile(
    r'\b([A-Za-z_][A-Za-z0-9_]*)\s*\*\s*([A-Za-z_][A-Za-z0-9_]*)\s*='
)
CALL_RE = re.compile(r'\b([A-Za-z_][A-Za-z0-9_]*)\s*->\s*([A-Za-z_][A-Za-z0-9_]*)\s*\(')


@dataclass
class Finding:
    status: str  # PASS | CRITICAL | UNVERIFIED
    line: int
    variable: str
    class_name: str
    method: str
    message: str
    file_path: str = ""


def build_variable_class_map(header_text: str, source_text: str) -> dict[str, str]:
    var_class: dict[str, str] = {}
    for text in (header_text, source_text):
        for m in MEMBER_DECL_RE.finditer(text):
            cls = m.group(1) or m.group(2)
            var = m.group(3)
            var_class[var] = cls
        for m in LOCAL_DECL_RE.finditer(text):
            var_class[m.group(2)] = m.group(1)
    return var_class


def verify_file(source_path: Path, header_path: Path, manifest: dict) -> list[Finding]:
    header_text = header_path.read_text(encoding="utf-8", errors="replace") if header_path and header_path.exists() else ""
    source_text = source_path.read_text(encoding="utf-8", errors="replace") if source_path and source_path.exists() else ""
    var_class = build_variable_class_map(header_text, source_text)

    findings: list[Finding] = []
    lines = source_text.splitlines()
    for i, line in enumerate(lines, 1):
        for m in CALL_RE.finditer(line):
            var, method = m.group(1), m.group(2)
            cls = var_class.get(var)
            if not cls or cls not in manifest:
                continue
            entry = manifest[cls]
            if method in entry.get("known_hallucinated", []):
                findings.append(Finding("CRITICAL", i, var, cls, method,
                    f"{cls}::{method} is a CONFIRMED fake/hallucinated Unreal method. Will fail UBT compilation.",
                    str(source_path)))
            elif method in entry.get("known_methods", []):
                findings.append(Finding("PASS", i, var, cls, method,
                    f"{cls}::{method} confirmed real against engine manifest.",
                    str(source_path)))
            else:
                findings.append(Finding("UNVERIFIED", i, var, cls, method,
                    f"{cls}::{method} is not in ground-truth manifest. Verify against engine headers.",
                    str(source_path)))
    return findings


def scan_directory(source_root: Path, manifest: dict) -> list[Finding]:
    all_findings: list[Finding] = []
    for root, _, files in os.walk(source_root):
        for f in files:
            if f.endswith(".cpp"):
                cpp_path = Path(root) / f
                h_path = cpp_path.with_suffix(".h")
                findings = verify_file(cpp_path, h_path, manifest)
                all_findings.extend(findings)
    return all_findings


def main():
    parser = argparse.ArgumentParser(description="Ashen Oath API Symbol Verifier")
    parser.add_argument("--source-root", type=Path, default=None)
    parser.add_argument("--source", type=Path, default=None)
    parser.add_argument("--header", type=Path, default=None)
    parser.add_argument("--manifest", type=Path, default=Path(__file__).parent / "known_api_symbols.json")
    args = parser.parse_args()

    if not args.manifest.exists():
        print(f"[FAIL] Manifest not found: {args.manifest}", file=sys.stderr)
        sys.exit(2)

    manifest = json.loads(args.manifest.read_text(encoding="utf-8"))

    findings: list[Finding] = []
    if args.source_root:
        findings = scan_directory(args.source_root, manifest)
    elif args.source:
        findings = verify_file(args.source, args.header, manifest)
    else:
        # Default: scan workspace Source/AshenOath
        default_root = Path(__file__).resolve().parent.parent / "AshenOath" / "Source" / "AshenOath"
        if default_root.exists():
            findings = scan_directory(default_root, manifest)
        else:
            print(f"[WARN] Default source root not found: {default_root}")
            sys.exit(0)

    critical = [f for f in findings if f.status == "CRITICAL"]
    passed = [f for f in findings if f.status == "PASS"]
    unverified = [f for f in findings if f.status == "UNVERIFIED"]

    print("=== [Ashen Oath Symbol Verifier (Anti-Hallucination Gate)] ===")
    print(f"[INFO] Scanned call sites against {len(manifest)} manifest classes.")
    print(f"[INFO] Results: {len(passed)} PASS | {len(unverified)} UNVERIFIED | {len(critical)} CRITICAL")

    for c in critical:
        print(f"[CRITICAL FAIL] {c.file_path}:{c.line} -> {c.class_name}::{c.method} ({c.message})")

    if critical:
        print("[FAIL] Hallucinated API symbols detected! Aborting before UBT invocation.")
        sys.exit(1)
    else:
        print("[SUCCESS] Zero hallucinated API symbols detected.")
        sys.exit(0)


if __name__ == "__main__":
    main()
