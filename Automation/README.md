# Ashen Oath — Tier-0 Pre-Flight Verification Arsenal

This directory houses the standalone, sub-second static verification and anti-hallucination test suite for **Ashen Oath** (Unreal Engine 5.8 C++).

Executing this suite before triggering UnrealBuildTool (UBT) ensures that binary memory contracts, reflection metadata, DAG phase dependencies, and engine API call signatures are 100% verified in **$< 1.0\text{s}$**, eliminating compilation failures and protecting our multi-thousand clean build streak.

---

## 🚀 Quick Start

Run all 5 verification layers simultaneously:

```powershell
python Automation/run_all_checks.py
```

---

## 🛡️ The 5 Verification Layers

### 1. UMB C++ Struct Layout Contract (`test_struct_layout.cpp`)
* Verifies strict 128-byte cache-line packing and member alignment (`<ffffffI100s`) across the C++ and Python interop boundary (`SharedMemoryBridge.hpp`).

### 2. AST Header & Reflection Scanner (`pre_build_check.py`)
* Scans all Unreal Engine C++ headers in `Source/AshenOath/` for forbidden pattern violations:
  * Forbidden `bIsActive` parameter names in `UFUNCTION(BlueprintCallable)` signatures.
  * Ensures compliance with UHT dynamic reflection rules.

### 3. AOP-001 DAG Pipeline Validator (`aop_dag_runner.py`)
* Enforces cycle-free Directed Acyclic Graph (DAG) execution across all 4 production batch phases:
  1. `Phase1_DataContracts`
  2. `Phase1_FirewallValidation`
  3. `Phase2_WorldActors` & `Phase2_GASAbilities`
  4. `Phase3_Actuators_UI_Audio`
  5. `Phase4_SaveGameBridge` & `Phase4_QATestSuite`

### 4. SELT-001 Telemetry & Coherence Auditor (`selt_audit.py`)
* Audits `selt_telemetry.jsonl` to ensure that all state transitions maintain a mean Coherence Index $\ge 0.90$.

### 5. API Surface Symbol Verifier (`symbol_verifier.py` & `known_api_symbols.json`)
* **Anti-Hallucination Gate**: Cross-references all `Object->Method()` call sites in `.cpp` files against `known_api_symbols.json`.
* Flags non-existent, fabricated, or deprecated Unreal Engine methods (e.g. `ApplyStrainField` vs. `ApplyPhysicsField`) as `CRITICAL FAIL` before spawning UBT.
