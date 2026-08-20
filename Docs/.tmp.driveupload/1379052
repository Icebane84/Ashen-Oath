# 🏛️ ASHEN OATH UNREAL CODING WORKFLOW BLUEPRINT
## Master Operational Directive for Continuous AI-Driven C++ Development

> **V-Control**: 2026-08-06T02:37:00-04:00  
> **Status**: ACTIVE & AUTHORITATIVE  
> **Target Engine**: Unreal Engine 5.8 (Win64 Development)  
> **Skill Path**: `C:\Users\Chris\.gemini\config\skills\ashen_oath_unreal_coding\SKILL.md`

---

## I. Executive Overview & Handoff Protocol

This blueprint provides the exact operational framework for any AI collaborator (Antigravity, Cursor, Claude, GPT-4, etc.) to seamlessly resume C++ development on *Ashen Oath* without breaking build continuity or losing momentum.

### How to Continue Where We Left Off:
1. **Read `Docs/RELEASE_HISTORY.md` (Line 1)**:
   - Identify the latest completed build number (e.g., **Build 675 / Milestone 675**).
   - Your next batch starts at `Latest Build + 1` (e.g., **Build 676**).
2. **Read `Docs/ARCHITECTURE_MAP.md`**:
   - Review active vertical slices, registered ProductFilter tests, and system subsystems.
3. **Execute 20-Build Master Batches**:
   - Follow the 20-Build Execution Loop below to implement `Builds N+1` through `Builds N+20`.

---

## II. The 20-Build Master Batch Execution Loop

To maximize development velocity and minimize token consumption, development is executed in **20-Build Master Batches**.

```
[Inspect RELEASE_HISTORY.md] ──► [Batch Create 40 Source Files (.h / .cpp)]
                                                  │
                                                  ▼
[Execute UBT Compilation Pass] ◄── [Write Complete C++ for All 20 Builds]
              │
              ▼
[Update RELEASE_HISTORY.md & ARCHITECTURE_MAP.md] ──► [Present Milestone Report]
```

### 1. Batch File Creation Command
Run a single PowerShell command to generate all `.h` and `.cpp` files in their respective domain folders:

```powershell
$BasePath = "c:\Users\Chris\Ashen Oath Unreal Engine\AshenOath\Source\AshenOath"

New-Item -ItemType File -Force -Path `
"$BasePath\DomainFolder\AshenNewSystem1.h", "$BasePath\DomainFolder\AshenNewSystem1.cpp", `
...
"$BasePath\Orchestration\AshenMilestoneXXXMasterSynthesisOrchestrator.h", "$BasePath\Orchestration\AshenMilestoneXXXMasterSynthesisOrchestrator.cpp"
```

### 2. Standard 20-Build Batch Composition
A standard 20-Build Batch (e.g. Builds 676–695) must be structured as follows:
- **Builds 676–659**: Domain-specific Subsystems, Actor Components, UMG Backing Widgets, or World Actors.
- **Build 680**: **Milestone 680 Synthesis Orchestrator & QA Suite** (4 ProductFilter tests).
- **Builds 681–689**: Deep mechanical subsystems, evaluators, calculators, and directors.
- **Build 690**: **Milestone 690 Synthesis Orchestrator & QA Suite** (4 ProductFilter tests).
- **Builds 691–694**: World Actors, AI Directors, and Audio Modulation controllers.
- **Build 695**: **Master Milestone 695 Production Synthesis Orchestrator & Master QA Suite** (4 ProductFilter tests).

---

## III. 12 Domain-Driven Vertical Slice Hierarchy

All project source files live strictly inside `Source/AshenOath/` categorized by **Domain Vertical Slices**, never by generic class type (`Actors/`, `Components/`).

```
Source/AshenOath/
├── Core/         # Base contracts, enforcers, rule auditors, mathematical utilities
├── Soul/         # FSoulStateVector, psychological translation, CAN anchors, identity
├── Memory/       # Memory Palace graph, node anchors, memory weaving
├── Companions/   # Garrett, Serafina, companion trust, divergence, annotations
├── Combat/       # GAS abilities, Oathbringer Greatsword, Aegis, Devil's Bargain, Willpower
├── Narrative/    # Semantic mention validators, chapter integration, dialogue triggers
├── UI/           # UMG backing widgets, Diegetic field journal, Somatic presentation
├── Audio/        # Atmospheric modulation, whisper emitters, spatial soundscapes
├── World/        # Atmospheric volumes, campfires, Heartstone shrines, loci
├── Orchestration/# Master synthesis orchestrators, runtime broadcasters
├── AI/           # EQS directors, flank interceptors, uncertainty directors
└── QA/           # Dedicated ProductFilter FAutomationTestBase automation test suites
```

---

## IV. Technical Guardrails & Compilation Protocol

### 1. The Single UBT Compilation Command
Always invoke UnrealBuildTool via PowerShell after writing all 20 builds in a batch:

```powershell
& "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" -project="c:\Users\Chris\Ashen Oath Unreal Engine\AshenOath\AshenOath.uproject" AshenOathEditor Win64 Development
```

### 2. Universal C++ Rules to Prevent Compilation Failures:
- **UHT Delegate Macro Names**: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_*` macro names generate global C++ types (`Z_Construct_UDelegateFunction_...`). EVERY delegate macro MUST have a globally unique name across the entire codebase.
- **UBT Non-Unity Filename Collisions**: No two `.cpp` files in `Source/AshenOath/` may share the same filename, even in different domain subfolders.
- **Enums**: Any enum exposed to Blueprints, delegates, or functions must use `UENUM(BlueprintType)` and derive from `: uint8`.
- **Automation Test Signatures**:
  - `TestEqual(TEXT("Description"), ActualValue, ExpectedValue);` (3 args)
  - `TestTrue(TEXT("Description"), Condition);` (2 args)
  - `TestNotNull(TEXT("Description"), Pointer);` (2 args)

---

## V. Custom Skill Registration

The custom skill has been registered in the global configuration directory:
- **Skill Path**: `C:\Users\Chris\.gemini\config\skills\ashen_oath_unreal_coding\SKILL.md`

Any AI collaborator can load this skill or refer to this document to execute work with 100% zero-drift precision.
