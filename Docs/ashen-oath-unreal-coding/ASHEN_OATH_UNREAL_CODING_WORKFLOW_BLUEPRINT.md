# 🏛️ ASHEN OATH UNREAL CODING WORKFLOW BLUEPRINT
## Master Operational Directive for Continuous AI-Driven C++ Development

> **V-Control**: 2026-09-01T14:30:00-04:00  
> **Status**: ACTIVE & AUTHORITATIVE  
> **Target Engine**: Unreal Engine 5.8 (Win64 Development)  
> **Skill Path**: `C:\Users\Chris\.gemini\config\skills\ashen_oath_unreal_coding\SKILL.md`

---

## I. Executive Overview & Handoff Protocol

This blueprint provides the exact operational framework for any AI collaborator (Antigravity, Cursor, Claude, GPT-4, etc.) to seamlessly resume C++ development on *Ashen Oath* without breaking build continuity or losing momentum.

### How to Continue Where We Left Off:
1. **Read `Docs/RELEASE_HISTORY.md` (Line 1)**:
   - Identify the latest completed build/patch (e.g. **Patch v158.19.0 / Milestone 3175**).
   - Your next batch starts at `Latest Build + 1` (e.g., **Build 3176**).
2. **Read `Docs/README.md` & `Docs/ARCHITECTURE_MAP.md`**:
   - Review active vertical slices, registered ProductFilter tests, and system subsystems.
3. **Inspect the Four Pillars**:
   - `RELEASE_HISTORY.md` (The Log), `ARCHITECTURE_MAP.md` (The Map), `ARCHITECTURAL_SYNERGIES_&_PATTERNS.md` (The Math & Law Vault), and `PROTOTYPES.md` (The Playable Sandbox Lab).
4. **Execute 20-Build Master Batches**:
   - Follow the 20-Build Execution Loop below to implement `Builds N+1` through `Builds N+20`.

---

## II. The 20-Build Master Batch Execution Loop

To maximize development velocity, preserve memory headroom, and minimize token consumption, development is executed in **20-Build Master Batches** (100% Pure Gameplay Density).

```
[Inspect RELEASE_HISTORY.md] ──► [Batch Create 40 Source Files (.h / .cpp)]
                                                  │
                                                  ▼
[Execute UBT with -MaxParallelActions=4] ◄── [Write Complete C++ for All 20 Builds]
              │
              ▼
[Update RELEASE_HISTORY.md & Docs/README.md] ──► [Present Milestone Report]
```

### Standard 20-Build Batch Composition
A standard 20-Build Batch (e.g. Builds 3156–3175) is structured as follows:
- **Phase 1 (Builds N+1 to N+5)**: Core Domain Subsystems, State Machines & Mathematical Components.
- **Phase 2 (Builds N+6 to N+10)**: Gameplay Abilities (GAS), Combat Stances, Motion Warping, Status Effects & Interactive World Actors.
- **Phase 3 (Builds N+11 to N+15)**: AI StateTree Evaluators, Diegetic Audio Systems, Somatic UMG Widgets & Post-Process Adapters.
- **Phase 4 (Builds N+16 to N+20)**: Cross-Domain Adapters, Narrative/Dialogue Triggers, SaveGame State, Master Domain Bridge & Deep Value-Asserting QA Automation Test Suites.

---

## III. 12 Domain-Driven Vertical Slice Hierarchy

All project source files live strictly inside `Source/AshenOath/` categorized by **Domain Vertical Slices**, never by generic class type (`Actors/`, `Components/`).

```
Source/AshenOath/
├── Core/         # Base contracts, enforcers, rule auditors, mathematical utilities
├── Soul/         # FSoulStateVector, psychological translation, CAN anchors, identity
├── Memory/       # Memory Palace graph, Campfire Sanctuary Subsystem, Lorekeeper beacons
├── Companions/   # Garrett, Serafina, companion trust, divergence, annotations
├── Combat/       # GAS Master Cuts, Oathbringer Greatsword, Sync Finishers, Motion Warping
├── Narrative/    # Semantic mention validators, chapter integration, dialogue triggers
├── UI/           # UMG & Slate backing widgets, Diegetic field journal, Somatic presentation
├── Audio/        # Atmospheric modulation, whisper emitters, MetaSounds, Quartz 115 BPM
├── World/        # Atmospheric volumes, campfires, Heartstone shrines, loci
├── Orchestration/# Master domain bridges, runtime event broadcasters
├── AI/           # StateTree 60Hz evaluators, Liechtenauer matrix data assets, EQS directors
└── QA/           # Dedicated ProductFilter FAutomationTestBase automation test suites
```

---

## IV. Technical Guardrails & Compilation Protocol

### 1. The Authoritative UBT Compilation Command
Always invoke UnrealBuildTool via PowerShell after writing all 20 builds in a batch, passing `-MaxParallelActions=4` to avoid compiler virtual memory exhaustion:

```powershell
& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat" AshenOathEditor Win64 Development "c:\Users\Chris\Ashen Oath Unreal Engine\AshenOath\AshenOath.uproject" -waitmutex -MaxParallelActions=4
```

### 2. Universal C++ Rules to Prevent Compilation Failures:
- **UHT Delegate Macro Names**: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_*` macro names generate global C++ types. EVERY delegate macro MUST have a globally unique name across the entire codebase.
- **UBT Non-Unity Filename Collisions**: No two `.cpp` files in `Source/AshenOath/` may share the same filename, even in different domain subfolders.
- **Automation Test Pointer Rigor**: When testing `TObjectPtr<T>` with `TestNotNull`, always pass `.Get()`: `TestNotNull(TEXT("..."), Component->MyDataAsset.Get());`.
- **Strict Forward Declarations**: Public headers (`.h`) MUST only `#include "CoreMinimal.h"` and parent classes; forward-declare all other classes and structs. Concrete `#include` directives are strictly confined to `.cpp` translation units.
