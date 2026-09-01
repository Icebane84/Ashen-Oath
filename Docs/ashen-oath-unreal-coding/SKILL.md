---
name: ashen-oath-unreal-coding
description: Master operational methodology for high-velocity, 100% clean Unreal Engine 5.8 C++ production development in Ashen Oath across 20-Build Master Batches, 12 Domain-Driven Vertical Slices, and Canon Specification Document Generation.
---

# Ashen Oath Unreal Engine 5.8 C++ Architectural Synthesis Skill

This skill defines the exact cognitive loop, domain layout, 20-build cadence, compilation safeguards, and canon specification protocol used to achieve **3,175+ clean C++ builds (0 errors, 0 warnings)** for *Ashen Oath*. Any AI agent invoking or following this skill must execute with the same sovereign precision.

---

## 🏛️ Executive Rules of Execution

1. **Zero Drift & Zero Warning Mandate**:
   - Every C++ file written must compile cleanly under Unreal Engine 5.8 `UnrealBuildTool.exe` without a single error or warning.
   - Never swallow exceptions, mask broken logic, or return ungrounded stub fallbacks.

2. **20-Build Master Batch Execution Cadence (100% Pure Gameplay Density)**:
   - Operate in structured **20-Build Master Batches** (e.g. Builds 3156–3175) focused **100% on concrete gameplay systems, GAS abilities, AI logic, world interaction, audio/UI widgets, and value-asserting QA suites**.
   - Zero decorative scaffolding: Eliminate placeholder editor validator/stress tester classes that merely log strings and return true.
   - Divide every 20-build batch into 4 high-impact gameplay phases:
     - **Phase 1 (Builds N+1 to N+5)**: Core Domain Subsystems, State Machines & Mathematical Components (clamping, decay, transformation logic).
     - **Phase 2 (Builds N+6 to N+10)**: Gameplay Abilities (GAS), Combat Stances, Motion Warping, Status Effects & Interactive World Actors.
     - **Phase 3 (Builds N+11 to N+15)**: AI StateTree Evaluators / EQS Flanking Directors, Diegetic Audio Systems, Somatic UMG Widgets & Post-Process Adapters.
     - **Phase 4 (Builds N+16 to N+20)**: Cross-Domain Adapters, Narrative/Dialogue Triggers, SaveGame State, Master Domain Bridge & Deep Value-Asserting QA Automation Test Suites.
   - Execute a **single UBT compilation pass** per batch to conserve memory and optimize compilation velocity.

3. **12 Domain-Driven Vertical Slices Hierarchy**:
   - Organize code strictly by **Domain**, NEVER by generic class type (`Actors/`, `Components/`).
   ```
   Source/AshenOath/
   ├── Core/         (Base contracts, save game serialization, state enforcers)
   ├── Soul/         (FSoulStateVector, Living Oaths, 4 Interpretive Lenses)
   ├── Memory/       (Memory Palace graph, Campfire Sanctuary Subsystem, Lorekeeper beacons)
   ├── Companions/   (Garrett, Serafina, trust divergence, fatigue, resonance)
   ├── Combat/       (GAS Master Cuts, Oathbringer Greatsword, Sync Finishers, Motion Warping)
   ├── Narrative/    (Dialogue adapters, narrative barks, choice tree gates)
   ├── UI/           (UMG & Slate backing widgets, Somatic HUDs, lens grading)
   ├── Audio/        (Diegetic audio components, spatial whispers, MetaSounds triggers)
   ├── World/        (Null Zones, consecrated anchors, memory fragments, altars)
   ├── Orchestration/(Master domain bridges, runtime event broadcasters)
   ├── AI/           (StateTree 60Hz evaluators, Liechtenauer matrix data assets, EQS directors)
   └── QA/           (ProductFilter FAutomationTestBase value-asserting test suites)
   ```

4. **Canon Specification Documents (`*-SPEC-*.md`) Mandate**:
   - For every major feature or Master Batch, generate a dedicated canon specification document in `Docs/` (e.g. `PRS-001-SPEC-COMBAT-106.md`, `PRS-001-SPEC-SOUL-107.md`, `PRS-001-SPEC-INPUT-108.md`, `PRS-001-SPEC-AI-109.md`, `METALLURGY-SPEC-102.md`, `CONVERGENCE-SPEC-101.md`).
   - Every specification must contain:
     - **Thematic & Narrative Philosophy**: Core quotes framing the mechanics.
     - **Mermaid Architectural Diagrams**: Visual flowcharts and sequence diagrams.
     - **Mathematical Bounds & Formulas**: Explicit state equations and scaling curves.
     - **Complete C++ Class Mapping Tables**: Header paths, class names, and primary responsibilities.
   - Cross-reference and index all specifications in `Docs/README.md` and `Docs/ARCHITECTURE_MAP.md`.

5. **Hierarchical Master Architecture Atlas Protocol (`Docs/MASTER_ARCHITECTURE_ATLAS.md`)**:
   - Maintain the **Hierarchical Master Architecture Atlas** as the supreme systemic equipment linking all 12 Vertical Slices to the **Macro-Systemic Closed Loop Engine**.
   - Map concrete C++ classes, structs, hardware routing, and delegates into the 4-Stage Causal Chain:
     - **Layer 1 (Remember)**: Objective ground truth logging (`FSoulStateVector`, Epistemic Grounding).
     - **Layer 2 (Interpret)**: Campfire Sanctuary Reflection & 4 Morally Ambiguous Lenses (`InvokeIntegration()`).
     - **Layer 3 (Relate)**: Companion behavior as relationship (Dynamic spacing $\le 200\text{uu}$, DualSense tactical whispers, Shepherd's Gambit containment).
     - **Layer 4 (Express)**: Physicalized world provenance (Live PBR metallurgy morphing, Living Journal multi-author marginalia, procedural skin pallor).

---

## ⚡ The 6-Step Causal Wiring & Anti-Theater Law (Sentinel Protocol)

1. **Non-Negotiable Value-Asserting Exit Criterion**:
   - **A real automation test must fail when you break the mechanic on purpose, and pass when you fix it.**
   - Zero tautologies: Never author `TestTrue(..., Orchestrator->ValidateX())` where `ValidateX()` is hardcoded to `return true;`.
   - Every test must assert against an actual resulting game state (a health float, a material parameter, a blend ratio, a gameplay tag, or a physics impulse).

2. **The 6-Step Causal Wiring Sequence**:
   - **Step 1: Find the Entry Point** — Identify or author the GAS ability, input binding, or melee hit-trace callback that player action reaches first.
   - **Step 2: Find the Source of Truth Class** — Locate the authoritative domain state holder (`UAshenSoulPublisher`, `UAshenCampfireReflectionSubsystem`). Route state changes through it.
   - **Step 3: Fan Out to Existing Adapters** — Connect the authoritative source downstream into existing `World/`, `UI/`, and `Audio/` adapter classes (`UAshenOathbringerMorphComponent`, `SAshenCampfireConstellationWidget`).
   - **Step 4: Place Actors & Subobjects** — Ensure actors are placed in levels/spawners and subobjects are instantiated and owned by the player/enemy character (`CreateDefaultSubobject`).
   - **Step 5: Replace QA-Only Stubs with Value-Asserting Tests** — Write integration tests simulating live conditions and verifying state mutations.
   - **Step 6: Anti-Hallucination & Dead-Code Verification** — Verify that all methods have genuine callers and that no check passes without the underlying mechanic functioning.

3. **The Data-Driven Balancing & Invariant Safety Law (Zero-Recompile Protocol)**:
   - **Decouple Tuning from Mechanics**: Never hardcode combat scalars (damage, stagger multipliers, fatigue costs, radii, time dilation rates, sanity drain) as raw constants in `.cpp` files.
   - **Primary DataAsset Exposure**: Encapsulate tuning parameters in typed `USTRUCT`s inside dedicated `UPrimaryDataAsset` classes (e.g. `UAshenLiechtenauerMatrixDataAsset`, `UAshenMartialStanceBalanceDataAsset`).
   - **Defensive C++ Boundary Clamping**: The C++ accessor methods must enforce mathematical hard limits (`FMath::Clamp`).
   - **Headless Unit-Test Fallbacks**: If the DataAsset pointer is `nullptr`, C++ must gracefully fall back to canonical default struct values.

---

## ⚙️ Step-by-Step Batch Execution Protocol

### Step 1: Check Current Milestone State
- Read `Docs/RELEASE_HISTORY.md` to identify the last build/patch completed (e.g. `Patch v158.19.0 / Milestone 3175`).
- Determine target batch range: `Build N+1` to `Build N+20`.

### Step 2: Write Source Files Across the 4 Gameplay Phases
1. **Phase 1 (N+1 to N+5)**: Write Core Domain Subsystems, Mathematical Evaluators & State Components.
2. **Phase 2 (N+6 to N+10)**: Write Gameplay Abilities (GAS), Combat Components & Interactive World Actors.
3. **Phase 3 (N+11 to N+15)**: Write AI StateTree Evaluators / EQS Directors, Diegetic Audio Emitters, UMG UserWidgets & Post-Process Adapters.
4. **Phase 4 (N+16 to N+20)**: Write Domain Adapters, SaveGame Serialization, Narrative Dialogue Gates, Master Bridge & Concrete QA Automation Suites.

### Step 3: Update Release Documentation
- Prepend builds with domain tables to `Docs/RELEASE_HISTORY.md`.
- Update `Docs/ARCHITECTURE_MAP.md` and `Docs/ARCHITECTURAL_SYNERGIES_&_PATTERNS.md` (`SYN-XXX`).
- Generate the dedicated `Docs/*-SPEC-*.md` document and update `Docs/README.md`.

### Step 4: Execute Single UBT Compilation Pass with Memory Safeguards
- Run UnrealBuildTool passing `-MaxParallelActions=4` to protect memory thresholds:
  ```powershell
  & "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat" AshenOathEditor Win64 Development "c:\Users\Chris\Ashen Oath Unreal Engine\AshenOath\AshenOath.uproject" -waitmutex -MaxParallelActions=4
  ```
- Verify `Result: Succeeded` (0 Errors, 0 Warnings).

### Step 5: Single-File Surgical Failure Triage Protocol
- If UBT encounters an error in 1 of the files:
  1. **Locate**: Parse the UBT log output to identify the exact failing file path, line number, and error code.
  2. **Surgically Fix**: Modify **ONLY** the specific failing `.h` or `.cpp` file. **NEVER** re-generate or wipe sibling files.
  3. **Incremental Retry**: Re-execute the UBT command with `-MaxParallelActions=4`.

### Step 6: Architectural Reflection & Synergy Discovery Protocol
- Following successful compilation and test verification:
  1. **Record in Synergy Registry**: Add findings with formal `SYN-XXX` identifiers to `Docs/ARCHITECTURAL_SYNERGIES_&_PATTERNS.md`.
  2. **Evaluate Prototype Candidates**: Create standalone, zero-dependency HTML5 playable sandboxes in `Docs/Prototypes/` and index in `Docs/PROTOTYPES.md`.

---

## 🛡️ Critical Technical Guardrails

1. **Subsystem Base Class Selection**:
   - Use `UGameInstanceSubsystem` when state must persist across level changes (`UAshenCampfireReflectionSubsystem`).
   - Use `UWorldSubsystem` for level-bound or world-ticking orchestration.
   - Use `UEditorSubsystem` for all editor tooling and validation suites.

2. **UE 5.8 Format String Sanitization (`FormatStringSanErrors.inl`)**:
   - In `UE_LOG` or `FString::Printf` format strings, literal `%` characters MUST be escaped as `%%`.

3. **UHT Delegate & Class Identifier Uniqueness**:
   - `DECLARE_DYNAMIC_MULTICAST_DELEGATE_*` must have globally unique type names across all project headers.

4. **UHT 64-Bit Integer Restriction (`int64` vs `uint64`)**:
   - Blueprint reflection **does NOT support `uint64`**. Always use **`int64`** for all 64-bit integers and monotonic `StateVersion` counters.

5. **Automation Test Overload & Flag Rigor (UE 5.8)**:
   - Use `EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter`.
   - `TestEqual` requires strict matching types.
   - `TestNotNull` with `TObjectPtr<T>` requires `.Get()`: `TestNotNull(TEXT("..."), Component->MyDataAsset.Get());`.

6. **Single Authoritative Source Tree**:
   - The engine target project resides at `AshenOath\AshenOath.uproject` with the canonical source root at `AshenOath\Source\AshenOath\`.

7. **Strict Forward Declaration & Header Cleanliness Mandate**:
   - Public headers (`.h`) MUST only `#include "CoreMinimal.h"` and direct parent class headers.
   - All referenced components, actors, subsystems, and USTRUCTs must be forward-declared (`class UMyClass;`, `struct FMyStruct;`).
   - Concrete `#include` directives are strictly confined to `.cpp` translation units.

8. **Macro-Systemic Event Spine & Invariant Laws**:
   - All state scalars clamped in $[0.0, 1.0]$.
   - Integration Debt reduction enforces the Zero-Debt Invariant ($Debt \to 0.0$ at Campfire Sanctuary).
   - Every state commit monotonically increments `int64 StateVersion`.
   - The Anti-Arcade Law: `EmissiveIntensity == 0.0f` across grounded metallurgical tiers.
