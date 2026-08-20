---
name: ashen-oath-unreal-coding
description: Master operational methodology for high-velocity, 100% clean Unreal Engine 5.8 C++ production development in Ashen Oath across 20-Build Master Batches and 12 Domain-Driven Vertical Slices.
---

# Ashen Oath Unreal Engine 5.8 C++ Architectural Synthesis Skill

This skill defines the exact cognitive loop, folder layout, build rules, and execution protocol used to achieve **675+ clean C++ builds (0 errors, 0 warnings)** for *Ashen Oath*. Any AI agent invoking or following this skill must execute with the same sovereign precision.

---

## 🏛️ Executive Rules of Execution

1. **Zero Drift & Zero Warning Mandate**:
   - Every C++ file written must compile cleanly under Unreal Engine 5.8 `UnrealBuildTool.exe` without a single error or warning.
   - Never swallow exceptions, mask broken logic, or return stub fallbacks.

2. **20-Build Master Batch Execution Cadence**:
   - Operate in **20-Build Master Batches** (e.g. Builds 676–695).
   - Batch creation of all header (`.h`) and implementation (`.cpp`) files upfront in Powershell/CMD.
   - Write complete, robust, production C++ into every file.
   - Execute a **single UBT compilation pass** per batch to conserve tokens and compile time.

3. **12 Domain-Driven Vertical Slices Hierarchy**:
   - Organize code strictly by **Domain**, NEVER by class type (`Actors/`, `Components/`).
   ```
   Source/AshenOath/
   ├── Core/         (Base contracts, enforcers, rule auditors)
   ├── Soul/         (FSoulStateVector, psychological translation, CAN anchors)
   ├── Memory/       (Memory Palace graph, node anchors)
   ├── Companions/   (Garrett, Serafina, companion trust, divergence, annotations)
   ├── Combat/       (GAS abilities, Oathbringer Greatsword, Aegis, Devil's Bargain, Willpower)
   ├── Narrative/    (Semantic mention validators, chapter integration)
   ├── UI/           (UMG backing widgets, Diegetic field journal, Somatic presentation)
   ├── Audio/        (Atmospheric modulation, whisper emitters, soundscapes)
   ├── World/        (Atmospheric volumes, campfires, Heartstone shrines, loci)
   ├── Orchestration/(Master synthesis orchestrators, runtime broadcasters)
   ├── AI/           (EQS directors, flank interceptors, uncertainty directors)
   └── QA/           (ProductFilter FAutomationTestBase automation suites)
   ```

---

## ⚙️ Step-by-Step Batch Execution Protocol

### Step 1: Check Current Milestone State
- Read `Docs/RELEASE_HISTORY.md` line 1 to identify the last build completed (e.g. `Build 675`).
- Determine target batch range: `Build N+1` to `Build N+20` (e.g. `676` to `695`).

### Step 2: Batch Create Source Files
- Use a single PowerShell script to create all `.h` and `.cpp` files in their respective domain folders inside `Source/AshenOath/`.

### Step 3: Write C++ Implementation Files
For each build in the batch:
- **Delegates**: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_*` MUST have globally unique type names across all project headers to avoid UHT collisions.
- **Enums**: Must be marked `UENUM(BlueprintType)`.
- **Classes**: Inherit from standard Unreal base classes (`UGameInstanceSubsystem`, `UWorldSubsystem`, `UActorComponent`, `UUserWidget`, `AActor`, `AVolume`, `UObject`).
- **QA Automation Tests**: Every batch MUST include dedicated `ProductFilter` automation tests inheriting from `FAutomationTestBase` via `IMPLEMENT_SIMPLE_AUTOMATION_TEST`.
- **Orchestration**: End each batch with a **Master Synthesis Orchestrator** subsystem (`UAshenMilestoneXXXMasterSynthesisOrchestrator`) that logs and verifies all builds in the batch.

### Step 4: Execute Single UBT Compilation Pass
- Run UnrealBuildTool via PowerShell:
  ```powershell
  & "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" -project="c:\Users\Chris\Ashen Oath Unreal Engine\AshenOath\AshenOath.uproject" AshenOathEditor Win64 Development
  ```
- Wait for completion and verify `Result: Succeeded`.

### Step 5: Update Documentation & Release Logs
- Prepend all 20 builds to `Docs/RELEASE_HISTORY.md`.
- Update `Docs/ARCHITECTURE_MAP.md` with the new master milestone and cumulative test counts.
- Report completion clearly to the user.

---

## 🛡️ Critical Technical Guardrails

1. **UHT Delegate Collisions**:
   - BAD: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStanceActivatedSignature, ...)` in two separate files.
   - GOOD: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAegisStanceActivatedSignature, ...)` vs `DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBerserkStanceActivatedSignature, ...)`.

2. **UBT Non-Unity Filename Collisions**:
   - No two `.cpp` files anywhere in the project can share the exact same filename even if they live in different subfolders.

3. **Automation Test Signature Rigor**:
   - `TestEqual(TEXT("Description"), ActualValue, ExpectedValue);` expects 3 arguments.
   - `TestTrue(TEXT("Description"), Condition);` expects 2 arguments.
