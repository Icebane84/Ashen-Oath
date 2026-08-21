---
name: ashen-oath-unreal-coding
description: Master operational methodology for high-velocity, 100% clean Unreal Engine 5.8 C++ production development in Ashen Oath across 20-Build Master Batches, 12 Domain-Driven Vertical Slices, and Canon Specification Document Generation.
---

# Ashen Oath Unreal Engine 5.8 C++ Architectural Synthesis Skill

This skill defines the exact cognitive loop, domain layout, 20-build cadence, compilation safeguards, and canon specification protocol used to achieve **2,455+ clean C++ builds (0 errors, 0 warnings)** for *Ashen Oath*. Any AI agent invoking or following this skill must execute with the same sovereign precision.

---

## 🏛️ Executive Rules of Execution

1. **Zero Drift & Zero Warning Mandate**:
   - Every C++ file written must compile cleanly under Unreal Engine 5.8 `UnrealBuildTool.exe` without a single error or warning.
   - Never swallow exceptions, mask broken logic, or return ungrounded stub fallbacks.

2. **20-Build Master Batch Execution Cadence (100% Pure Gameplay Density)**:
   - Operate in structured **20-Build Master Batches** (e.g. Builds 1776–1795) focused **100% on concrete gameplay systems, GAS abilities, AI logic, world interaction, audio/UI widgets, and value-asserting QA suites**.
   - Zero decorative scaffolding: Eliminate placeholder editor validator/stress tester classes that merely log strings and return true.
   - Divide every 20-build batch into 4 high-impact gameplay phases:
     - **Phase 1 (Builds N+1 to N+5)**: Core Domain Subsystems, State Machines & Mathematical Components (clamping, decay, transformation logic).
     - **Phase 2 (Builds N+6 to N+10)**: Gameplay Abilities (GAS), Combat Stances, Motion Warping, Status Effects & Interactive World Actors.
     - **Phase 3 (Builds N+11 to N+15)**: AI Perception/EQS Flanking Directors, Diegetic Audio Systems, Somatic UMG Widgets & Post-Process Adapters.
     - **Phase 4 (Builds N+16 to N+20)**: Cross-Domain Adapters, Narrative/Dialogue Triggers, SaveGame State, Master Domain Bridge & Deep Value-Asserting QA Automation Test Suites.
   - Execute a **single UBT compilation pass** per batch to conserve tokens and optimize compilation velocity.

3. **12 Domain-Driven Vertical Slices Hierarchy**:
   - Organize code strictly by **Domain**, NEVER by generic class type (`Actors/`, `Components/`).
   ```
   Source/AshenOath/
   ├── Core/         (Base contracts, save game serialization, state enforcers)
   ├── Soul/         (FSoulStateVector, Living Oaths, Interpretive Lenses)
   ├── Memory/       (Memory Palace graph, Memory Battles, Lorekeeper beacons)
   ├── Companions/   (Garrett, Serafina, trust divergence, fatigue, resonance)
   ├── Combat/       (GAS abilities, Oathbringer Greatsword, Sync Finishers, Motion Warping)
   ├── Narrative/    (Dialogue adapters, narrative barks, choice tree gates)
   ├── UI/           (UMG backing widgets, Somatic HUDs, lens grading)
   ├── Audio/        (Diegetic audio components, spatial whispers, MetaSound triggers)
   ├── World/        (Null Zones, consecrated anchors, memory fragments, altars)
   ├── Orchestration/(Master domain bridges, runtime event broadcasters)
   ├── AI/           (EQS directors, memory battle enemies, flanking interceptors)
   └── QA/           (ProductFilter FAutomationTestBase value-asserting test suites)
   ```

4. **Canon Specification Documents (`*-SPEC-*.md`) Mandate**:
   - For every major feature or Master Batch, generate a dedicated canon specification document in `Docs/` (e.g. `FINISHER-SPEC-014.md`, `OATH-SPEC-016.md`, `MEMORY-SPEC-017.md`, `CORRUPTION-SPEC-019.md`, `LENS-SPEC-020.md`, `COMPANION-SPEC-021.md`, `PROVENANCE-SPEC-040.md`).
   - Every specification must contain:
     - **Thematic & Narrative Philosophy**: Core quotes framing the mechanics.
     - **Mermaid Architectural Diagrams**: Visual flowcharts and sequence diagrams.
     - **Mathematical Bounds & Formulas**: Explicit state equations and scaling curves.
     - **Complete C++ Class Mapping Tables**: Header paths, class names, and primary responsibilities.
   - Embed the primary Mermaid architecture diagrams directly into `Docs/ARCHITECTURE_MAP.md`.

5. **Hierarchical Master Architecture Atlas Protocol (`Docs/MASTER_ARCHITECTURE_ATLAS.md`)**:
   - Maintain the **Hierarchical Master Architecture Atlas** as the supreme systemic equipment linking all 12 Vertical Slices to the **Macro-Systemic Closed Loop Engine**.
   - Rather than attempting unreadable monolithic diagrams, maintain high-resolution, domain-driven subsystem diagrams mapping concrete C++ classes, structs, hardware routing, and delegates into the 4-Stage Causal Chain:
     - **Layer 1 (Remember)**: Objective ground truth logging (`FSoulStateVector`, Epistemic Grounding).
     - **Layer 2 (Interpret)**: Mindscape Crucibles & Keystone Lenses (`InvokeIntegration()`).
     - **Layer 3 (Relate)**: Companion behavior as relationship (Dynamic spacing, DualSense tactical whispers, Shepherd's Gambit containment).
     - **Layer 4 (Express)**: Physicalized world provenance (Somatic weapon soot, Living Journal multi-author marginalia, procedural skin pallor).

---

## ⚙️ Step-by-Step Batch Execution Protocol

### Step 1: Check Current Milestone State
- Read `Docs/RELEASE_HISTORY.md` to identify the last build completed (e.g. `Build 1775`).
- Determine target batch range: `Build N+1` to `Build N+20` (e.g. `1776` to `1795`).

### Step 2: Write Source Files Across the 4 Gameplay Phases
1. **Phase 1 (N+1 to N+5)**: Write Core Domain Subsystems, Mathematical Evaluators & State Components.
2. **Phase 2 (N+6 to N+10)**: Write Gameplay Abilities (GAS), Combat Components & Interactive World Actors.
3. **Phase 3 (N+11 to N+15)**: Write AI EQS Directors, Diegetic Audio Emitters, UMG UserWidgets & Post-Process Adapters.
4. **Phase 4 (N+16 to N+20)**: Write Domain Adapters, SaveGame Serialization, Narrative Dialogue Gates, Master Bridge & Concrete QA Automation Suites.

### Step 3: Update Release Documentation
- Prepend all 20 builds with domain tables to `Docs/RELEASE_HISTORY.md`.
- Update `Docs/ARCHITECTURE_MAP.md` header to the new milestone count and embed the architectural Mermaid diagram.
- Generate the dedicated `Docs/*-SPEC-*.md` document.

### Step 4: Execute Single UBT Compilation Pass
- Run UnrealBuildTool using parameterized environment variables or local engine paths:
  ```powershell
  # Environment-agnostic parameterized invocation
  & "$env:UE_5_8_PATH\Engine\Build\BatchFiles\Build.bat" AshenOathEditor Win64 Development "$ProjectDir\AshenOath\AshenOath.uproject" -waitmutex

  # Local default fallback
  & "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat" AshenOathEditor Win64 Development "c:\Users\Chris\Ashen Oath Unreal Engine\AshenOath\AshenOath.uproject" -waitmutex
  ```
- Verify `Result: Succeeded` (0 Errors, 0 Warnings).

### Step 5: Single-File Surgical Failure Triage Protocol
- If UBT encounters a compiler or linker error in 1 of the 20 files:
  1. **Locate**: Parse the UBT log output to identify the exact failing file path, line number, and compiler error code (e.g. `C2666`, `C2065`, `UHT error`).
  2. **Surgically Fix**: Modify **ONLY** the specific failing `.h` or `.cpp` file. **NEVER** re-generate, wipe, or rewrite the 19 valid sibling files.
  3. **Incremental Retry**: Re-execute the UBT command. The Unreal Build Accelerator (UBA) will recompile only the modified translation unit and link the DLL in seconds.

### Step 6: Architectural Reflection & Synergy Discovery Protocol
- Following successful compilation and test verification, perform explicit architectural reflection across the 20 newly forged classes:
  1. **Identify Mathematical Invariants**: Isolate new clamping formulas, boundary refusal equations, or state transitions.
  2. **Identify Cross-Subsystem Bridges**: Map how C++ systems interconnect with AI EQS queries, MetaSounds audio envelopes, or DualSense haptics.
  3. **Record in Synergy Registry**: Prepend the new findings with formal `SYN-XXX` identifiers to `Docs/ARCHITECTURAL_SYNERGIES_&_PATTERNS.md` (`SYNERGY-REGISTRY-001`).
  4. **Evaluate Prototype Candidates**: Identify prime candidate mechanics to scaffold into standalone, zero-dependency HTML5 playable sandboxes in `Docs/Prototypes/` and index in `Docs/PROTOTYPES.md`.

---

## 🛡️ Critical Technical Guardrails

1. **Subsystem Base Class Selection**:
   - Use `UGameInstanceSubsystem` when state must persist across level changes and be accessible by diagnostic HUDs or global menus via `GameInstance->GetSubsystem<T>()`.
   - Use `UWorldSubsystem` for level-bound or world-ticking orchestration.
   - Use `UEditorSubsystem` for all editor tooling and validation suites.

2. **UE 5.8 Format String Sanitization (`FormatStringSanErrors.inl`)**:
   - In `UE_LOG` or `FString::Printf` format strings, literal `%` characters MUST be escaped as `%%` (or written as `percent`), otherwise UBT compile will fail with `PRINTF_FORMAT_STRING_ERROR`.

3. **UHT Delegate & Class Identifier Uniqueness**:
   - `DECLARE_DYNAMIC_MULTICAST_DELEGATE_*` must have globally unique type names across all project headers.
   - Class names and structs must never collide across different modules or Unity translation units.

4. **UHT 64-Bit Integer Restriction (`int64` vs `uint64`)**:
   - Blueprint reflection (`UFUNCTION(BlueprintCallable)`, `UPROPERTY(BlueprintReadWrite)`, dynamic multicast delegates) **does NOT support `uint64`**.
   - Attempting to expose `uint64` parameters or struct properties produces UHT compile errors: `Error: Type 'uint64' is not supported by blueprint`.
   - **Rule**: Always use **`int64`** for all 64-bit integers, monotonic `StateVersion` counters, and transaction IDs exposed to Blueprint reflection.

5. **Automation Test Overload & Flag Rigor (UE 5.8)**:
   - Use `EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter` for editor/engine test execution.
   - `TestEqual` has strict overload resolution across `int32`, `int64`, `SIZE_T`, `float`, and `double`. Passing mismatched signedness (e.g. comparing `int64` against `(uint64)1` or untyped literals) triggers compiler error `C2666: 'FAutomationTestBase::TestEqual': overloaded functions have similar conversions`.
   - **Rule**: Always explicitly cast expected literals to match the exact signed type: `TestEqual(TEXT("State Version"), Registry->GetStateVersion(), (int64)1);`.

6. **Single Authoritative Source Tree**:
   - The engine target project resides at `AshenOath\AshenOath.uproject` with the single canonical source root at `AshenOath\Source\AshenOath\`.
   - All 2,455+ builds compile cleanly from this single authoritative directory without duplicate sync folders.

7. **Tier-0 Standalone Pre-Flight Automation Protocol (`Automation/`)**:
   - Before running full Unreal Engine compilation passes, developers and AI agents can execute the sub-second pre-flight suite:
     ```powershell
     python Automation/run_all_checks.py
     ```
   - Validates all 5 static verification layers in $< 1\text{s}$:
     1. **UMB Struct Layout**: C++ 128-byte cache-line alignment contracts (`test_struct_layout.cpp`).
     2. **AST Header Guardrails**: Scans for forbidden parameter names and missing reflection metadata (`pre_build_check.py`).
     3. **AOP DAG Pipeline**: Validates acyclic dependency execution graph across all 4 phases (`aop_dag_runner.py`).
     4. **SELT Telemetry & Coherence**: Audits mean coherence scores across transaction events (`selt_audit.py`).
     5. **API Surface Symbol Verifier**: Anti-hallucination gate cross-referencing call-sites against confirmed UE 5.8 symbols (`symbol_verifier.py` & `known_api_symbols.json`).

8. **Blueprint Function Parameter Naming Guardrail (`bIsActive`)**:
   - Never use `bIsActive` as a parameter name in `UFUNCTION(BlueprintCallable)` signatures to prevent collisions with generated Blueprint class properties. Use contextual names (e.g. `bInActive`, `bInDeceptionActive`, `bInWheelActive`).

9. **Strict Forward Declaration & Header Cleanliness Mandate**:
   - Public headers (`.h`) MUST only `#include "CoreMinimal.h"` and direct parent class headers.
   - All referenced components, actors, subsystems, and USTRUCTs must be **forward-declared** (e.g. `class UMyComponent;`, `struct FMyPayload;`).
   - Concrete `#include` directives are strictly confined to `.cpp` translation units. This prevents cross-domain circular header dependencies and minimizes compilation times.

10. **Macro-Systemic Event Spine & Invariant Laws (`CONTRACT-SPEC-051` through `INTENT-SPEC-056`)**:
    - Every somatic state transition must preserve causal lineage through `SourceTransactionId` and `SourceStateVersion`.
    - Enforce the 7 Canonical Invariants:
      1. All state scalars clamped in $[0.0, 1.0]$.
      2. Integration Debt reduction requires an authorized `Resolution.*` gameplay tag.
      3. Every state commit monotonically increments `int64 StateVersion`.
      4. Corruption $\uparrow$ and Resolve $\uparrow$ simultaneous increase is forbidden without `Resolution.BifurcatedWill`.
      5. `TrioResonance` bounded in $[\min(Tr_S, Tr_G) - 0.2, \max(Tr_S, Tr_G) + 0.2]$.
      6. Resolution never purges historical `RelatedImprintIds`.
      7. Salience Gate rate limiter: $0.25$ threshold, $3.0\,\text{s}$ dwell, $0.50$ critical shock bypass.
    - Enforce Trigger Resistance Priority Arbitration:
      - **Priority 1 (`DialogueWillStruggle`)**: $\text{Resistance} \ge 0.85 \implies 100\%$ Mechanical Hard-Stop Lockout.
      - **Priority 2 (`CombatStagger`)**: $50\%$ baseline spring $\implies 0\%$ give-way on poise-break.
      - **Priority 3 (`AmbientSomatic`)**: Continuous background tension ($0.0 \to 0.35$).
    - Enforce the **4-Stage Zero-Entropy Cognitive Firewall** (`VOICE-SPEC-054` / `JOURNAL-SPEC-055`):
      - Stage 1: Schema Validation $\rightarrow$ Stage 2: Provenance Audit $\rightarrow$ Stage 3: Tag Registry Check $\rightarrow$ Stage 4: Float Clamp $[0.0, 1.0]$.
    - Enforce the **Intent Resolution Model** (`INTENT-SPEC-056`):
      - Trust is confidence in intent, NOT blind obedience. Differentiate Heroic Rescue vs Blind Wrath vs Tactical Flank.

