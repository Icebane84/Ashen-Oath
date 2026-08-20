# Ashen Oath — Walkthrough: Phase I Complete (Build 58)
**V-Control:** 2026-07-30T08:01:13-04:00  
**Governed By:** ENGINE-SPEC-001 (DEFINITIVE CANON) + AOP-STATE-001

---

## ✅ Phase I Complete — The Psychological Runtime Kernel

The Soul Constellation Subsystem is online. The Engine of Consequence now has its single source of truth.

---

## What Was Built

### 1. [AshenSoulStateVector.h](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenSoulStateVector.h)
The canonical MVSC data contract. All downstream systems reference this file.

**Key types:**
- `FSoulStateVector` — 6 floats + 1 enum + `FBehavioralProfile` (< 128 bytes, cache-line safe)
- `FBehavioralProfile` — 3-byte evaluated semantic cache: `EStanceProfile`, `EEmpathicProfile`, `ETacticalProfile`
- `EInterpretiveLens` — `Accountability | Grace | Utility`
- `EIntegrationDebtStage` — `Dormant | MemoryBleed | RuntimeNoise | ForcedCollapse`
- `GetDebtStage()` — single canonical threshold evaluation (no duplicate logic in subsystems)
- `IsResonanceSyncActive()` — inline resonance condition check

### 2. [AshenOath_ImprintBufferComponent.h](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenOath_ImprintBufferComponent.h) / [.cpp](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenOath_ImprintBufferComponent.cpp)
Session-volatile psychological pressure accumulator. Lives on `AAshenCombatCharacter`.

**Key behaviors:**
- `AddImprint(Type, Weight)` — FIFO-evicts oldest imprint at capacity (64 max, pre-reserved)
- `DecayBuffer()` — called on death before Heartstone. Wipes array, reduces `IntegrationDebt` by `DecayOnDeathFraction` (default 0.2). No permanent StateVector change.
- `ConsumeBuffer()` — called during `InvokeIntegration()`. Returns snapshot for `CompileIdentity()`, resets debt to 0.
- `GetDominantImprintType()` — weight-tallied per type, returns heaviest (used to select Mindscape enemy archetype)
- `OnDebtStageChanged` delegate — fires only on actual stage transitions, not on every `AddImprint()` call

### 3. [AshenSoulConstellationSubsystem.h](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenSoulConstellationSubsystem.h) / [.cpp](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenSoulConstellationSubsystem.cpp)
The Psychological Runtime Kernel. `UGameInstanceSubsystem`. AXIOM I enforced.

**Full integration pipeline (call order):**
```
InvokeIntegration(bForced)
  └─ ExecuteMindscapeSimulation()   → async loads L_Mindscape_Master, fires OnMindscapeEntered
  
[Mindscape resolves Memory Battle, then calls:]
FinalizeIntegration(SelectedLens)
  └─ ApplyInterpretiveFilter()      → applies Lens trust bias weights to pending deltas
  └─ ImprintBuffer.ConsumeBuffer()  → snapshot of all pending imprints
  └─ CompileIdentity()              → builds new FSoulStateVector from SanityComp + ManifestationComp + deltas
                                       evaluates FBehavioralProfile from thresholds
  └─ PublishStateVector()           → fires FOnStateVectorInvalidated native multicast to all C++ subscribers
  └─ InvalidateSubsystems()         → updates MPC_AshenOath scalars in a single pass
  └─ RelieveDespairOnIntegration()
  └─ OnIntegrationComplete.Broadcast(bWasForced)
```

**Trust write API:** `ApplyGarrettTrustDelta()` / `ApplySerafinaTrustDelta()` accumulate into pending deltas — not written to `CurrentState` until `FinalizeIntegration()`. Enforces the **Temporary State / Permanent State** rule from DEFINITIVE CANON.

**MPC Update:** `InvalidateSubsystems()` writes `MPC_Corruption`, `MPC_Resolve`, `MPC_IntegrationDebt`, `MPC_Isolation`, `MPC_GarrettTrust`, `MPC_SerafinaTrust`, `MPC_Despair` in one pass via `UMaterialParameterCollectionInstance`. Zero per-frame per-MID writes.

### 4. [AshenCombatCharacter.h](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenCombatCharacter.h) / [.cpp](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenCombatCharacter.cpp)
`UAshenOath_ImprintBufferComponent* ImprintBufferComponent` added as `CreateDefaultSubobject` in constructor.

---

## Compiler Errors Resolved

| # | File | Error | Fix |
|:--|:-----|:------|:----|
| 1 | `AshenSoulConstellationSubsystem.h:29` | `DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneBoolParam` — UHT macro does not exist | `DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIntegrationComplete, bool, bWasForced)` |
| 2 | `AshenSoulConstellationSubsystem.h:204` | `AllowedClasses = "MaterialParameterCollection"` — not a valid long path name | Removed meta tag; `TSoftObjectPtr<UMaterialParameterCollection>` constrains editor picker natively |
| 3 | `AshenOath_ImprintBufferComponent.cpp:29` | `TArray::RemoveAt(0, 1, false)` — UE 5.3+ requires `EAllowShrinking` enum, not `bool` | `EAllowShrinking::No` |

---

## Build Result
```
Result: Succeeded
Total execution time: 10.87 seconds
0 errors | 0 warnings
```

---

## PHOENIX CODEX Compliance Audit
- ✅ No `GetAllActorsOfClass` — components cached via `DirectorSubsystem.GetPlayerPawn()`
- ✅ All actor/component pointers in `UPROPERTY()` or `TWeakObjectPtr` — GC-safe
- ✅ No raw `new` / `delete`
- ✅ `FSoulStateVector` < 128 bytes (28 bytes actual)
- ✅ Global MPC updated once per compilation tick, not per-MID per-frame
- ✅ All downstream systems read `ActiveProfile` enum fields — never raw floats
- ✅ Single Source of Truth: `CurrentState` is `private`, only written by `PublishStateVector()`

---

## What's Next — Cluster 1 Continues

**Phase IV: Lenses — `EInterpretiveLens` Selection & Save Persistence**

| Milestone | Target |
|:----------|:-------|
| M74 | `ApplyInterpretiveFilter()` bias weights (already scaffolded in `CompileIdentity()`) |
| M75 | `UW_LensSelectionWidget` — Heartstone rest radial UI |
| M76 | `CompileIdentity()` full evaluation pass verification |
| M77 | `UAshenSaveGame` lens + trust persistence (`SavedLens`, `GarrettTrust`, `SerafinaTrust`) |

The Lens subsystem is partially wired — `ApplyInterpretiveFilter()` is live inside the Kernel. The remaining work is the **widget** (Lens Selection UI shown during `InvokeIntegration()`) and **save persistence**.

> **Editor Setup Required:** Before Phase IV widgets compile correctly, create `MPC_AshenOath` in the Unreal Editor (`Content Browser → Add → Materials → Material Parameter Collection`) with the following scalar parameters: `MPC_Corruption`, `MPC_Resolve`, `MPC_IntegrationDebt`, `MPC_Isolation`, `MPC_GarrettTrust`, `MPC_SerafinaTrust`, `MPC_Despair`. Assign it to `USoulConstellationSubsystem.MPC_AshenOath` in the subsystem's Details panel.
