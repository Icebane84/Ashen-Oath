# Ashen Oath: Comprehensive Multi-Phase Implementation Plan
**V-Control:** 2026-07-30T07:40:00-04:00  
**Primary Index:** PRS-001-ENG-SPEC-001-V1.2 (Definitive Canon)  
**Governed By:** PHOENIX CODEX v1.0 + ENGINE-SPEC-001 (DEFINITIVE CANON) + AOP-EXEC-001  
**C++ Skill Protocol:** OGLN.AGENT.Skill.C++Proficiency v1.1.0

> [!NOTE]
> **Historical Foundational Document**: This multi-phase implementation plan documents the early Phase I foundational architecture (Builds 1–58). The production architecture has since matured and is fully realized across **Master Batches #1–#111 (Builds 1–2235)** governed by [CONTRACT-SPEC-051](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/CONTRACT-SPEC-051%20%28CANONICAL%20VARIABLE%20REGISTRY%20&%20MACRO-SYSTEMIC%20EVENT%20CONTRACTS%29.md) and [ORCH-SPEC-052](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/ORCH-SPEC-052%20%28THE%20CANONICAL%20SOMATIC%20TRANSLATION%20ENGINE%20&%20UNIFIED%20EVENT%20SPINE%29.md).

---

## Executive Summary

ENGINE-SPEC-001 is now **architecturally closed, structurally hardened, and canonized.** The question is no longer *what* the Engine of Consequence is. The question is how to build the **Minimum Viable Soul Constellation (MVSC)** and deliver the full cognitive loop within the first 120 minutes of gameplay without overwhelming the player. This plan directly reflects both the Definitive Canon spec and the Practical Implementation Framework, and updates the previous plan with three major structural corrections:

1. **`FSoulStateVector` is the MVSC** — 6 core floats + 2 relational tethers + 1 lens enum. No more than 128 bytes on the stack.
2. **`FBehavioralProfile` is the semantic firewall** — downstream systems (Animation, Audio, AI, Shaders) query profile fields, never raw floats.
3. **Integration Debt is a first-class 4-stage escalation system**, not just a buffer counter.

---

## Ground Truth Baselines (AOP-STATE-001)

| Dimension | Decision | Rationale |
|:----------|:---------|:----------|
| **Level Streaming** | Async Sub-Level `L_Mindscape_Master` via `UGameplayStatics::LoadStreamLevel` | No greybox exists yet; built from scratch with dynamic geometry driven by `AMindscapeReactivityActor` + `MPC_MindscapeState` |
| **Dialogue Engine** | Native C++ `UAshenDialogueSubsystem` + `UAshenDialogueGraph` DataAssets | Zero third-party plugin overhead; `FDialogueNodeRecord` natively reads `FSoulStateVector` fields directly |
| **Audio Engine** | Unreal Engine 5 Native MetaSounds API | Thread-safe parameter binding via `AudioComponent->SetParameterFloat()`; no Wwise/FMOD licensing overhead |
| **Art Pipeline** | C++ MID stubs + `AshenSocketNames.h` registry | DCC textures (`T_CorruptionMasks`) pending import; all material parameters pre-named to spec (`CorruptionAmount`, `ShadowMarkAlpha`, `EmissiveIntensity`) so art plugs in without code changes |
| **Execution Order** | Priority Cluster system (see below) | Vertical slice readiness drives ordering; Kernel + Lenses first, then Companion, then World/Dialogue |

### Cluster Execution Priority

| Cluster | Phases | Focus |
|:--------|:-------|:------|
| **Cluster 1** | Phase I + Phase IV (Lenses) | Soul Constellation MVSC Kernel + Identity Compilation |
| **Cluster 2** | Phase V (Companions) + Phase IX (Oaths) | Companion Interdependence + Living Oaths |
| **Cluster 3** | Phase VI (World Corruption) + Phase VIII (Dialogue) | Null Zones + Lens-Gated Dialogue Engine |
| **Cluster 4** | Phases X–XII | Economy, Visual/Audio Polish, Endgame |

---

## Current State Audit

### ✅ Infrastructure (57 Builds Complete)
- Sovereign Subsystems: `DirectorSubsystem`, `GameEventSubsystem`
- Core Combat Loop: `HealthComponent`, `HitboxComponent`, `HurtboxComponent`, Poise, Parry, Stagger, Hitstop, Time Dilation
- Player Character Hierarchy: `AAshenOathCharacter` → `AAshenCombatCharacter`
- Resource Economy: Stamina, Mana, Sanity, Poise
- AI Cognitive Architecture: `UAICognitiveComponent`, `ThreatPerceptionComponent`, StateTree tasks (EvaluateAction, ExecuteAbility)
- NPC Reactivity: `NPCReactivityComponent` + StateTree Condition
- Kaelen Visual Corruption: MID parameter interpolation, dual-phase shader transitions
- Oathbringer: Sanity-reactive, Guts-style morphing greatsword
- Save/Load: `AshenSaveManager` with stats, inventory, quest persistence
- Settings: `UAshenGameSettings` DeveloperSettings hub (fully centralized)
- Pooling: Projectile pool, Damage text pool, VFX Manager
- Post-Process: `UAshenSanityPostProcessComponent`
- World Interactables: Chests, Doors, Levers, Sanctuary/Heartstone
- Chaos Boss: `AAshenChaosBossOrchestrator` with physics fields
- Creature Types + Socket Names headers defined

### ❌ Not Yet Implemented (Target of This Plan)
Phases 0–XI below.

---

## Phase Structure Overview

| Phase | Focus Area | Milestones | Priority |
|:------|:-----------|:-----------|:---------|
| **0** | Act I Onboarding Arc — The First 120 Minutes | M58–M60 | 🔴 Critical |
| **I** | MVSC Kernel — `FSoulStateVector` + `FBehavioralProfile` | M61–M65 | 🔴 Critical |
| **II** | Integration Debt — 4-Stage Escalation Pipeline | M66–M68 | 🔴 Critical |
| **III** | `InvokeIntegration()` — Heartstone & Mindscape Loop | M69–M72 | 🟠 High |
| **IV** | Lenses — `ApplyInterpretiveFilter()` & Identity Compilation | M73–M77 | 🟠 High |
| **V** | Companion System — Trust, Divergence & Fatigue | M78–M82 | 🟠 High |
| **VI** | World Corruption — Null Zones, Whispering Winds, Anchoring | M83–M87 | 🟡 Medium |
| **VII** | Memory System — Fragments, Memory Battles, Lorekeeper | M88–M93 | 🟡 Medium |
| **VIII** | Dialogue Engine — Lens-Gated Nodes, Tone Filters, NPC Receptivity | M94–M97 | 🟡 Medium |
| **IX** | Oath System — Living Oaths, Oathbringer Mindscape | M98–M102 | 🟡 Medium |
| **X** | Economy — Ember & Ash, Upgrade Stations | M103–M106 | 🟢 Later |
| **XI** | Visual & Audio Production | M107–M112 | 🟢 Later |
| **XII** | Endgame — Vigil, Fugitive's Network, Prismatic Realm | M113–M117 | 🔵 Final |

---

## PHASE 0 — Act I Onboarding Arc: The First 120 Minutes
**Source: AOP-EXEC-001 (Practical Implementation Framework)**

> [!IMPORTANT]
> The onboarding arc is a **first-class engineering requirement**, not a level design task. The engine must be wired to execute four distinct phases across the first two hours without exposing raw state vectors to the player. The player must *feel* the cognitive loop before they are shown any of its mechanics.

### M58 — Silent Spire Opening Combat Sequence (Witness + Kinetic Trauma)
**Diegetic:** The Incident at the Silent Spire — Kaelen, Garrett, and Serafina in desperate scripted defense.  
**C++ Execution:**
- Combat Events fire silently into the `UImprint_Buffer` (to be built in Phase I)
- No HUD meters visible — `UAshenUserWidget_HUD` suppresses all resource bars via a `bIntroductionMode` flag
- Parry, stagger, and hitstop systems fully active; player experiences the combat feel with no psychological UI noise
- `bIntroductionMode` stored in `UAshenGameSettings`; HUD binding checks this flag before drawing any widget

### M59 — Shadowfen Avoidance Arc: Integration Debt as Physical Sensation (30–60 min)
**Diegetic:** Kaelen refuses to rest after the Spire. The Trio pushes through the Shadowfen.  
**C++ Execution:**
- When `FSoulStateVector.IntegrationDebt` crosses `0.5f` (Memory Bleed threshold):
  - `UAshenWhisperingWindSubsystem` increases ambient whisper audio volume
  - `UAshenSanityPostProcessComponent` begins edge desaturation pulse
  - Serafina's `UAshenOath_NPCReactivityComponent` sets a `bShowingFatigue` flag, triggering an "uneasy shiver" Animation Blueprint state
- **Player reads:** "Something is wrong. My character is breaking down." — no tutorial pop-up required

### M60 — First Heartstone Ritual Scripting Hook (60–90 min)
**Diegetic:** Garrett demands a break. Serafina collapses. Kaelen rests at a ruined Heartstone Crucible.  
**C++ Execution:**
- `AAshenSanctuaryActor` extended with `bIsFirstRitual` flag
- When `bIsFirstRitual = true`: `InvokeIntegration()` triggers a scripted cinematic sequence before the Mindscape loads, playing a brief Memory Battle against the Silent Spire echo
- After Memory Battle: First Lens Selection widget presented (Accountability / Grace / Utility)
- On selection: `CompileIdentity()` runs for the first time — `PublishStateVector()` fires `InvalidateSubsystems()`
- `bIsFirstRitual` saved to `UAshenSaveGame.bFirstRitualComplete` to prevent replay

---

## PHASE I — MVSC Kernel: `FSoulStateVector` & `FBehavioralProfile`
**Source: ENGINE-SPEC-001 (DEFINITIVE CANON), Section 3 + AOP-EXEC-001, Part I**

> [!IMPORTANT]
> This is the foundational phase. Every subsequent phase depends on the Kernel existing. The MVSC (Minimum Viable Soul Constellation) is the correct starting target — 6 floats + 2 relational tethers + 1 enum. Do not inflate the struct. Cache efficiency is mandatory: `FSoulStateVector` must stay under 128 bytes.

### M61 — `FSoulStateVector` MVSC Struct
**What:** The canonical memory contract for compiled identity state.  
**How:**
```cpp
// AshenSoulStateVector.h
USTRUCT(BlueprintType)
struct ASHENOATH_API FSoulStateVector
{
    GENERATED_BODY()

    // Identity Triad (0.0 – 1.0)
    UPROPERTY(BlueprintReadOnly) float Resolve     = 1.0f; // Stance Profile driver
    UPROPERTY(BlueprintReadOnly) float Corruption  = 0.0f; // Shader & Visual driver
    UPROPERTY(BlueprintReadOnly) float Isolation   = 0.0f; // Dialogue Tone & Audio driver

    // Relational Tethers (0.0 – 1.0)
    UPROPERTY(BlueprintReadOnly) float GarrettTrust  = 0.5f;
    UPROPERTY(BlueprintReadOnly) float SerafinaTrust = 0.5f;

    // Systemic Pressure
    UPROPERTY(BlueprintReadOnly) float IntegrationDebt = 0.0f; // 0 = Clear, 1 = Forced Collapse

    // Interpretive State
    UPROPERTY(BlueprintReadOnly) EInterpretiveLens PrimaryLens = EInterpretiveLens::Accountability;

    // Evaluated Cache (written by CompileIdentity(), read by subsystems)
    UPROPERTY(BlueprintReadOnly) FBehavioralProfile ActiveProfile;
};
```
- Struct defined in `AshenSoulStateVector.h`, included by `USoulConstellationSubsystem`

### M62 — `FBehavioralProfile` Semantic Abstraction Layer
**What:** The cache-friendly semantic firewall between raw floats and subsystem logic. Subsystems query `ActiveProfile` fields — never raw `FSoulStateVector` floats.  
**How:**
```cpp
UENUM(BlueprintType)
enum class EStanceProfile : uint8 { Hunched_Guarded, Balanced_Steady, Upright_Grounded };

UENUM(BlueprintType)
enum class EEmpathicProfile : uint8 { Burned_Out, Resonant_Attuned, Radiant_Shield };

UENUM(BlueprintType)
enum class ETacticalProfile : uint8 { Cynical_Isolated, Calculated_Pragmatic, Unshakeable_Anchor };

USTRUCT(BlueprintType)
struct ASHENOATH_API FBehavioralProfile
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadOnly) EStanceProfile   Stance   = EStanceProfile::Balanced_Steady;
    UPROPERTY(BlueprintReadOnly) EEmpathicProfile Empathic = EEmpathicProfile::Resonant_Attuned;
    UPROPERTY(BlueprintReadOnly) ETacticalProfile Tactical = ETacticalProfile::Calculated_Pragmatic;
};
```
- `CompileIdentity()` evaluates raw floats into these discrete enums:
  - `Resolve < 0.35f` → `Hunched_Guarded`; `> 0.65f` → `Upright_Grounded`; else `Balanced_Steady`
  - `SerafinaTrust < 0.35f` → `Burned_Out`; `> 0.65f` → `Radiant_Shield`; else `Resonant_Attuned`
  - `GarrettTrust < 0.35f` → `Cynical_Isolated`; `> 0.65f` → `Unshakeable_Anchor`; else `Calculated_Pragmatic`

### M63 — `USoulConstellationSubsystem` (Psychological Runtime Kernel)
**What:** The `UGameInstanceSubsystem` serving as the single source of truth.  
**How:**
- Holds `FSoulStateVector CurrentState` (private, read via `GetStateVector()`)
- `DECLARE_MULTICAST_DELEGATE_OneParam(FOnStateVectorInvalidated, const FSoulStateVector&)`
- `PublishStateVector(FSoulStateVector)`: sets `CurrentState`, evaluates `ActiveProfile`, fires `OnStateVectorInvalidated`
- `CompileIdentity()`: reads from `SanityComponent`, `ManifestationComponent`, trust records → builds and publishes a new `FSoulStateVector`
- Registered in `UAshenOath_DirectorSubsystem` for global access via `Director->GetSoulConstellation()`
- Uses `UMaterialParameterCollection` to set global shader parameters once per compilation tick (not per-MID per frame) — per DEFINITIVE CANON Appendix Engineering Note 3

### M64 — `FPsychologicalImprint` Buffer
**What:** Contiguous session buffer of unresolved experiential records.  
**How:**
```cpp
UENUM(BlueprintType)
enum class EImprintType : uint8 { Combat, Relationship, Memory, Environmental, Oath, Identity };

USTRUCT()
struct FPsychologicalImprint
{
    GENERATED_BODY()
    UPROPERTY() EImprintType Type    = EImprintType::Combat;
    UPROPERTY() float         Weight = 0.0f;
    UPROPERTY() float         Timestamp = 0.0f;
};
```
- `UAshenOath_ImprintBufferComponent` on `AAshenCombatCharacter`: `TArray<FPsychologicalImprint>` (pre-reserved to 64 entries to avoid per-frame reallocation)
- Imprints decay to zero on player death before Sanctuary (wipes buffer without touching persistent StateVector)
- On `InvokeIntegration()`: buffer is consumed, driving `IntegrationDebt` delta calculation, then cleared

### M65 — `OnStateVectorInvalidated` Subscriber Migrations
**What:** Migrate all existing subsystems to query `FSoulStateVector` via the Kernel's multicast delegate instead of polling raw component values.  
**How:**
- `UAshenSanityPostProcessComponent` → subscribe to `OnStateVectorInvalidated`, read `ActiveProfile.Stance` and `State.Corruption` instead of directly querying `SanityComponent` every tick
- `UAshenOath_NPCReactivityComponent` → subscribe, read `SerafinaTrust` / `GarrettTrust` from Kernel
- `AAshenWeapon_Oathbringer` → subscribe, read `Corruption` for blade emissive and `IntegrationDebt` for audio pitch
- `UAshenOath_ManifestationComponent` → subscribe, read `Isolation` to drive hallucination probability weighting
- `UAshenAudioSubsystem` → subscribe, adjust music state from `ActiveProfile`

---

## PHASE II — Integration Debt: 4-Stage Escalation Pipeline
**Source: ENGINE-SPEC-001 (DEFINITIVE CANON), Section 2**

> [!IMPORTANT]
> Integration Debt is **not a soft warning system**. At 100%, it forces a catastrophic psychological collapse mid-exploration or mid-combat. Subsystem degradation at the Runtime Noise stage (75–99%) must be mechanically meaningful — not just visual noise.

### M66 — Integration Debt Manager & Stage Thresholds
**What:** The formal 4-stage escalation system driven by `FSoulStateVector.IntegrationDebt`.  
**Stages:**

| Debt Level | Stage | Effect |
|:-----------|:------|:-------|
| 0% – 49% | **Integration Debt** | Dormant. Imprints buffer silently. No visible effect. |
| 50% – 74% | **Memory Bleed** | Audio echoes spill into traversal. Whispering Winds frequency spikes. Environment desaturates at edges. |
| 75% – 99% | **Runtime Noise** | Parry windows narrow by 15%. Companion pathfinding add +200ms response delay. HUD prompts flicker. |
| 100% | **Forced Collapse** | Immediate Mindscape entry with structural handicaps (reduced parry window, no Lens selection freedom). |

**How:**
- `UAshenOath_ImprintBufferComponent.AddImprint()` increments `IntegrationDebt` proportional to imprint weight
- Debt stage evaluated in `USoulConstellationSubsystem.GetDebtStage()` returning `EIntegrationDebtStage` enum
- `OnDebtStageChanged` delegate broadcasts when stage crosses threshold — subscribed by audio, post-process, and UI subsystems

### M67 — Memory Bleed Effects (50%–74%)
**What:** Physical sensation of avoidance without UI labels.  
**How:**
- `UAshenWhisperingWindSubsystem` subscribes to `OnDebtStageChanged`: at `MemoryBleed` stage, doubles whisper spawn frequency and increases spatial audio volume by +6dB
- `UAshenSanityPostProcessComponent` adds a secondary edge vignette at `Corruption = State.IntegrationDebt * 0.4f` during `MemoryBleed` (additive, not replacing sanity vignette)
- Serafina's `NPCReactivityComponent.bShowingFatigue = true` → triggers idle shiver anim state in her AnimBP

### M68 — Runtime Noise Degradation (75%–99%)
**What:** Mechanical degradation — not just visual feedback.  
**How:**
- `UAshenOath_HurtboxComponent` reads `USoulConstellationSubsystem.GetDebtStage()` in `ReceiveDamage()`: when `RuntimeNoise`, parry timing window shrinks by 15% (`ParryWindowSeconds *= 0.85f`)
- `UAshenOath_NPCReactivityComponent`: when `RuntimeNoise`, companion pathfinding adds a simulated response delay via a `0.2f`-second timer before executing navigation commands
- `UAshenUserWidget_HUD`: subscribes to debt stage; at `RuntimeNoise`, applies a randomized UV jitter animation to HUD resource bars every 3–5 seconds using a `UWidgetAnimation` timeline

### M69 — Forced Collapse (100%)
**What:** Catastrophic psychological collapse — involuntary Mindscape entry.  
**How:**
- `USoulConstellationSubsystem` monitors `IntegrationDebt` each compilation tick; when `>= 1.0f`, calls `InvokeIntegration()` with `bForcedCollapse = true`
- `bForcedCollapse = true` disables Lens Selection UI (no choice presented — the Lens that caused the most debt accumulation is auto-selected as the "unresolved dominant")
- Mindscape entry has structurally degraded parameters: parry window –25%, Memory Battle enemy has +30% HP

---

## PHASE III — `InvokeIntegration()`: Heartstone & Mindscape Loop
**Source: ENGINE-SPEC-001 (DEFINITIVE CANON), Section 4 — Diegetic/Runtime Abstraction Map**

### M70 — `InvokeIntegration()` — Full Heartstone Ritual Pipeline
**What:** The complete runtime pipeline called when Kaelen rests at a Sanctuary.  
**How:**
- `AAshenSanctuaryActor.Interact()` calls `USoulConstellationSubsystem.InvokeIntegration(bool bForced)`
- Execution order:
  1. `ExecuteMindscapeSimulation()` — triggers Mindscape level stream
  2. `ResolveMemoryImprint()` — spawns Memory Battle from heaviest imprint type
  3. `ApplyInterpretiveFilter()` — applies selected Lens weights to soul compilation
  4. `CompileIdentity()` — evaluates raw data into new `FSoulStateVector`
  5. `PublishStateVector()` — broadcasts `OnStateVectorInvalidated` with new state
  6. `InvalidateSubsystems()` — downstream subsystems re-query `ActiveProfile`
- `OnIntegrationComplete` delegate exposed for Blueprint cinematic hooks

### M71 — `ExecuteMindscapeSimulation()` — Mindscape Level Streaming
**What:** The interior world of Oathbringer — a level-streamed sub-environment.  
**How:**
- `USoulConstellationSubsystem` holds a `TSoftObjectPtr<UWorld>` to the Mindscape sub-level
- `ExecuteMindscapeSimulation()` calls `UGameplayStatics::OpenLevelAdditively()` for the Mindscape stream
- Exposes `OnMindscapeEntered` and `OnMindscapeExited` delegates for Blueprint sequence hooks

### M72 — `ResolveMemoryImprint()` — Memory Battle
**What:** The combat encounter inside the Mindscape that resolves the heaviest unresolved imprint.  
**How:**
- Reads heaviest `FPsychologicalImprint` from `UAshenOath_ImprintBufferComponent`
- Spawns `AAshenMemoryBattleEnemy` at Mindscape arena origin (enemy parameters scaled to imprint weight)
- On defeat: imprint resolved, buffer weight decremented, `Constellation_Harmony` delta logged
- On player death: imprint decays, buffer cleared, `IntegrationDebt` reduced by 0.2f (partial relief) — no permanent state change

### M73 — Mindscape Geometry Reactivity via Material Parameter Collection
**What:** The Mindscape's geometry responds to `FSoulStateVector.Resolve`.  
**How:**
- `AMindscapeReactivityActor` reads `Resolve` from Kernel on `OnStateVectorInvalidated`
- Sets `UMaterialParameterCollection` scalar `MPC_Resolve` driving pillar height offsets, light intensity, and floor crack density
- Per DEFINITIVE CANON Appendix: global MPC update happens once per compilation tick, not per-frame per-actor

---

## PHASE IV — Lenses: `ApplyInterpretiveFilter()` & Identity Compilation
**Source: ENGINE-SPEC-001 (DEFINITIVE CANON), Section 6 — Macro Loop Step 3**

### M74 — `EInterpretiveLens` Enum & Lens Application
**What:** The three philosophical interpretive filters — the meaning layer between raw experience and compiled identity.  
**How:**
```cpp
UENUM(BlueprintType)
enum class EInterpretiveLens : uint8 { Accountability, Grace, Utility };
```
- `ApplyInterpretiveFilter(EInterpretiveLens Lens)` in `USoulConstellationSubsystem`
- Biases compilation weights before `CompileIdentity()` runs:
  - **Accountability**: `GarrettTrust` accumulation rate +15%; Serafina becomes more reserved (Dialogue `Burned_Out` threshold shifts to 0.25f)
  - **Grace**: `SerafinaTrust` accumulation rate +15%; `Empathic` profile thresholds relax (support spells remain available until `Isolation > 0.8f`)
  - **Utility**: Tactical awareness buff — `ThreatPerceptionComponent` adds `+0.3f` to all threat scores for 60 seconds post-integration; dialogue truncates to terse tactical exchanges

### M75 — Lens Selection UI Widget
**What:** The in-Mindscape widget presented during `InvokeIntegration()`.  
**How:**
- `UW_LensSelectionWidget` shown after Memory Battle resolution
- Three selectable options with narrative flavor text, displaying current imprint composition as context
- On selection: stores choice in `USoulConstellationSubsystem`, calls `ApplyInterpretiveFilter()`, then proceeds to `CompileIdentity()`
- Suppressed entirely when `bForcedCollapse = true` (Debt at 100%)

### M76 — `CompileIdentity()` — Full Evaluation Pass
**What:** The synthesis function that converts raw floats + lens weights into a new `FSoulStateVector`.  
**How:**
- Reads `SanityComponent.GetSanityRatio()` → maps to `FSoulStateVector.Resolve`
- Reads `ManifestationComponent.GetInstabilityScore()` → maps to `Corruption`
- Reads `ImprintBuffer` dominant type distribution → maps to `Isolation`
- Reads companion trust records → maps to `GarrettTrust` / `SerafinaTrust`
- Evaluates `FBehavioralProfile` from thresholds (M62)
- Calls `PublishStateVector()` with compiled result

### M77 — Lens Persistence & Save Integration
**What:** Lens state must survive session restarts.  
**How:**
- `UAshenSaveGame` extended with `EInterpretiveLens SavedLens`
- `AshenSaveManager` serializes and deserializes lens and trust values
- `USoulConstellationSubsystem::Initialize()` reads save slot and restores `FSoulStateVector` fields + lens

---

## PHASE V — Companion System: Trust, Divergence & Fatigue
**Source: Pillar V Definitions — Companion Trust & Divergence, Companion Fatigue & Vulnerability, Resonance Anchoring**

### M78 — Companion Trust Accumulation Events
**What:** Granular trust delta events triggered by gameplay actions.  
**How:**
- `GameEventSubsystem.OnCompanionProtectiveAction` → `SerafinaTrust += 0.05f`
- `GameEventSubsystem.OnTacticalAbandonment` → `GarrettTrust -= 0.08f`
- `GameEventSubsystem.OnOathFulfilled` → both trusts `+= 0.03f`
- All deltas fed into `ImprintBuffer` as `Relationship Event` imprints before trust modifies StateVector directly — trust only compiles at `InvokeIntegration()`

### M79 — Companion Divergence: Pathfinding Offset Scaling
**What:** Physical spatial separation during traversal scales with `FBehavioralProfile.Tactical`.  
**How:**
- `NPCReactivityComponent` subscribes to `OnStateVectorInvalidated`
- `Tactical = Cynical_Isolated` → Garrett navigation offset expands to 800uu, stops proactive flanking
- `Empathic = Burned_Out` → Serafina navigation offset expands to 550uu, stops support spell casting unless forced
- Implemented via EQS context query offset parameters in companion StateTree

### M80 — Companion Fatigue — Tripartite Burn
**What:** Garrett (Control), Serafina (Emotional Poise), Kaelen (Transference) accumulate fatigue during `ENDURE` phase.  
**How:**
- `float FatigueAccumulator` in `NPCReactivityComponent`
- Increments per `OnCombatEventFired` (scaled by combat intensity)
- At `FatigueAccumulator > 0.7f`: companion enters `Vulnerable` state (reduced outgoing damage modifier, slowed movement)
- Recovers at 0.015f/second during `WITNESS` phase when no combat events fire for 45+ seconds

### M81 — Companion Vulnerability Window
**What:** Vulnerable companions are actionable targets and broadcast distress events.  
**How:**
- `Vulnerable` state gates Serafina's support ability activations (requires `Fatigue < 0.5f`)
- If companion health drops below 15% while `Vulnerable`: `GameEventSubsystem.OnCompanionNearDeath` fires → triggers Kaelen vocal reaction AnimNotify + `Relationship Event` imprint in buffer

### M82 — Resonance Anchoring & Companion Sync
**What:** When the trio is in emotional and tactical sync, a Resonance bonus fires.  
**How:**
- `USoulConstellationSubsystem` evaluates `ResonanceSync` condition each compilation tick: `|SerafinaTrust - GarrettTrust| < 0.15f` AND both `Fatigue < 0.4f` AND `Resolve > 0.5f`
- When `ResonanceSync = true`: `GameEventSubsystem.OnResonanceSyncAchieved` fires — 15% damage bonus granted via GAS `GameplayEffect` for 30 seconds; unique visual flourish on Oathbringer blade

---

## PHASE VI — World Corruption: Null Zones, Whispering Winds, Environmental Anchoring
**Source: Pillar II (Whispering Winds) + Pillar IV (Environmental Anchoring, Atmospheric Corruption)**

### M83 — `UAshenWhisperingWindSubsystem`
**What:** 3D-spatialized atmospheric corruption audio subsystem.  
**How:**
- Subscribes to `OnStateVectorInvalidated`: reads `State.Isolation` and `State.IntegrationDebt`
- Drives MetaSounds/audio bed parameter `WhisperIntensity = (Isolation * 0.5f) + (IntegrationDebt * 0.5f)`
- Spawns/kills looping Niagara atmospheric particle systems near Kaelen when `WhisperIntensity > 0.5f`

### M84 — `AAshenNullZoneVolume`
**What:** World-placed volumes that actively drive Integration Debt accumulation.  
**How:**
- `BoxComponent` trigger: on overlap begin, sets `FTimerHandle NullZoneTimer` calling `ImprintBuffer.AddImprint(Environmental, NullZoneDrainRate)` every 1.5 seconds
- `NullZoneDrainRate` configurable in `UAshenGameSettings`
- Sets global `UMaterialParameterCollection` scalar `MPC_NullZoneProximity` (0.0–1.0) based on `1.0 - (DistanceToEdge / NullZoneRadius)` — drives chromatic aberration in post-process material

### M85 — `AAshenMemoryFragmentActor`
**What:** World-placed psychic anchors emitting Memory Events on interaction.  
**How:**
- Extends `AAshenInteractableActor`
- On interaction: adds `Memory Event` imprint to buffer; plays 2D audio whisper bark + brief post-process desaturation pulse
- Consumed once per playthrough; state persisted in `UAshenSaveGame`
- `bRequiresLorekeeper` flag: if true, only interactable when `SerafinaTrust > 0.6f`

### M86 — Whispering Winds Vocal Bark System
**What:** World-ambient voices that escalate with `IntegrationDebt` and `Isolation`.  
**How:**
- `UAshenWhisperingWindSubsystem` schedules 3D audio bark events via `GetWorld()->GetTimerManager()`
- At `IntegrationDebt > 0.5f`: distant whispers
- At `IntegrationDebt > 0.75f`: Serafina and Garrett's voice assets used — familiar voices calling Kaelen's name

### M87 — Environmental Anchoring: Psychic Echo Residue
**What:** Enemies slain in specific locations leave psychic residue.  
**How:**
- On enemy death: `AAshenPsychicEchoActor` spawned at death location (60-second lifespan via auto-destroy timer)
- Within 300uu: passively increments Kaelen's `ManifestationComponent.InstabilityScore` at `0.5f/second`
- Creates environmental tension in heavily contested areas — Null Zones with many echos become significantly more hazardous

---

## PHASE VII — Memory System: Fragments, Battles & Lorekeeper
**Source: Pillar I (Memory Weaving, Inner Demons) + Pillar II (Fragmented Memories, Eldrin's Echo)**

### M88 — `FMemoryFragment` & Memory Archive Component
**What:** Data model for Kaelen's collectible psychological memories.  
**How:**
```cpp
USTRUCT(BlueprintType)
struct FMemoryFragment
{
    GENERATED_BODY()
    UPROPERTY() FText     NarrativeDescription;
    UPROPERTY() EImprintType Type;
    UPROPERTY() bool      bIntegrated = false;
    UPROPERTY() float     ResonanceWeight = 0.5f;
};
```
- `UMemoryArchiveComponent` on `AAshenCombatCharacter`: `TArray<FMemoryFragment>` serialized to `UAshenSaveGame`

### M89 — Memory Weaving Recombination Ritual
**What:** Pillar I — at Heartstone, two compatible fragments can be "woven" to unlock combat insights or lore.  
**How:**
- UI widget during Heartstone rest: fragments shown organized by type
- Weaving two compatible types (e.g., `Combat + Relationship`) calls `ResolveMemoryImprint()` and optionally calls `ASC->GiveAbility()` with a tagged passive
- Unlocked abilities tracked in `UAshenSaveGame`

### M90 — Eldrin's Echo Actor (Mentor's Shadow)
**What:** The ghost mentor who appears at Memory Fragments when sanity is sufficiently stable.  
**How:**
- `AEldrinEchoActor`: spawns near `AAshenMemoryFragmentActor` when `StateVector.Resolve > 0.6f`
- Plays voice lines interpreting the fragment's narrative description
- Dissolves (fade-out material opacity) if `Resolve` drops below `0.4f` while present

### M91 — Cycle of Despair Accumulator
**What:** Pillar II — repeated integration failures drive a global despair state.  
**How:**
- `float DespairAccumulator` in `USoulConstellationSubsystem`
- Increases when player dies before Heartstone (`+0.15f` per death)
- At `Despair > 0.7f`: `ManifestationComponent.HallucinationProbability *= 2.0f`; world gets a persistent desaturated-blue color grade via MPC scalar `MPC_Despair`
- Resets partially (`-0.3f`) on successful `InvokeIntegration()`

### M92 — Lorekeeper's Decoding Ritual (Serafina's Exclusive)
**What:** Sealed Memories only Serafina can decode when trust is high.  
**How:**
- `bRequiresLorekeeper = true` fragments filtered out unless `SerafinaTrust > 0.6f`
- Decoding triggers `GameEventSubsystem.OnLorекeeperDecoding`: plays shared animation montage for both characters
- Awards significant `Constellation_Harmony` delta (`+0.2f`) added to next `CompileIdentity()` pass

### M93 — Inner Demons System
**What:** Pillar I — persistent archetypal enemies spawned inside Mindscape from compiled `Corruption` and `Isolation` extremes.  
**How:**
- `AAshenMemoryBattleEnemy` subtypes: `EInnerDemonType { ShadowSelf, IsolationSpectre, CycleEcho }` driven by dominant imprint type composition
- `ShadowSelf` spawns when `Corruption > 0.7f` — mirrors Kaelen's attack animations
- `IsolationSpectre` spawns when `Isolation > 0.7f` and `GarrettTrust + SerafinaTrust < 0.6f` — uses crowd-control attacks

---

## PHASE VIII — Dialogue Engine: Lens-Gated Nodes & NPC Receptivity
**Source: ENGINE-SPEC-001 Section 7 (Dialogue Engine query) + Pillar III (Geopolitical Resonance, Cycle of Intertwined Fates)**

### M94 — `UAshenDialogueSubsystem`
**What:** `UGameInstanceSubsystem` managing conversation node availability gating.  
**How:**
- `GetAvailableNodes(FName ConversationID) → TArray<FDialogueNodeRecord>`
- `FDialogueNodeRecord`: `FText DisplayText`, `EInterpretiveLens RequiredLens`, `float MinTrustRequired`, `float MinResolveRequired`
- Subscribes to `OnStateVectorInvalidated` — re-evaluates node availability cache on each state publication

### M95 — Tone Filters by `ActiveProfile.Empathic`
**What:** Same dialogue node with different voice tone selected by Empathic Profile.  
**How:**
- `FDialogueNodeRecord` stores three `TSoftObjectPtr<USoundBase>`: `AccountabilityTone`, `GraceTone`, `UtilityTone`
- `PlayDialogue()` selects asset based on `ActiveProfile.Empathic` mapping to lens

### M96 — NPC Receptivity Matrix
**What:** World NPC receptivity shifts based on `Constellation_Harmony` and oath breach count.  
**How:**
- `TMap<FName FactionTag, float ReceptivityScore>` managed by `UAshenDialogueSubsystem`
- Oath breach events (`GameEventSubsystem.OnOathBroken`) reduce receptivity for NPCs within world-registered awareness radius
- `GetAvailableNodes()` filters nodes requiring receptivity thresholds

### M97 — Cycle of Intertwined Fates: Persistent Choice Flags
**What:** Key companion choice points that create ripple effects chapters later.  
**How:**
- `TMap<FName ChoiceTag, bool bChosen>` in `UAshenSaveGame.IntertwiningFates`
- `UAshenDialogueSubsystem` reads these flags to gate/unlock deep-history-aware NPC responses

---

## PHASE IX — Oath System: Living Oaths & Oathbringer Mindscape
**Source: ENGINE-SPEC-001 Section 1 (Oath Event Class) + Pillar III (Living Oaths, Oath Burn, Oath-Burden Mechanics)**

### M98 — `FOathRecord` & Oath Registry Component
**What:** Data container for sworn oaths tracked across the campaign.  
**How:**
```cpp
USTRUCT(BlueprintType)
struct FOathRecord
{
    GENERATED_BODY()
    UPROPERTY() FText  OathDescription;
    UPROPERTY() bool   bFulfilled = false;
    UPROPERTY() bool   bBroken    = false;
    UPROPERTY() float  TimeSinceSworn = 0.0f;
};
```
- `UAshenOath_OathRegistryComponent` on `AAshenCombatCharacter`: `TArray<FOathRecord>`
- `GameEventSubsystem.OnOathFulfilled` / `OnOathBroken` multicast delegates

### M99 — Oath Break Consequences
**What:** Broken oaths trigger cascading engine responses.  
**How:**
- `OnOathBroken` fires: `SanityComponent.SufferMentalDamage(25.0f)` + `ImprintBuffer.AddImprint(Oath, 0.35f)` + sets MPC `MPC_OathBreachCount` scalar (clamped 0.0–1.0 over max 5 breaches) → drives Oathbringer blade emissive dimming

### M100 — Oath Fulfillment Rewards
**What:** Kept oaths feed positive imprints and Oathbringer resonance.  
**How:**
- `OnOathFulfilled` fires: `SanityComponent.HealSanity(20.0f)` + positive `Identity Event` imprint + Oathbringer `PointLight.Intensity += 15.0f` pulse

### M101 — Oath Burn Meter
**What:** Pillar III — Oath-Burden accumulates with each oath sworn; eventually forces a reckoning.  
**How:**
- `float OathBurden` in `UAshenOath_OathRegistryComponent`: `+0.1f` per oath sworn
- At `OathBurden >= 1.0f`: "Oath Burn" state — Oathbringer actively drains Stamina when held (`-2.0f/second`); forces an Oath Resolution Mindscape event at next Heartstone (non-skippable)

### M102 — Mindscape Internal Geometry Updates from Oath State
**What:** The Mindscape's internal geometry reacts to the Oath Registry state.  
**How:**
- `AMindscapeReactivityActor` reads `OathRegistryComponent.GetBrokenOathCount()` via `DirectorSubsystem`
- Sets MPC scalar `MPC_OathCorruption` — drives visual darkness of Mindscape walls and floor crack density
- At `BrokenOathCount >= 3`: a corrupted mirror of Oathbringer appears as an additional Mindscape enemy

---

## PHASE X — Economy: Ember & Ash Currency
**Source: Pillar III — Ember and Ash Economy, Synarche Engagement System**

### M103 — `UAshenOath_CurrencyComponent`
**What:** Primary resource economy — Embers (session-volatile) and Ash (permanent).  
**How:**
- `UAshenOath_CurrencyComponent` on `AAshenCombatCharacter`
- `float Embers`: lost on death before Heartstone; restored at death echo retrieval
- `float Ash`: earned from `InvokeIntegration()` at rate `Ash += BaseAshGrant * StateVector.Resolve`; never lost on death
- Serialized in `UAshenSaveGame`

### M104 — Ember Echo Retrieval Actor
**What:** Soulslike soul-retrieval mechanic — lost Embers as a lootable corpse echo.  
**How:**
- On respawn: `AAshenEmberEchoActor` spawned at death location; interactable via `AshenInteractionComponent`
- If player dies again before retrieval: echo auto-destroys after 90 seconds, Embers permanently lost
- Echo emits a faint golden particle effect (`UVFXManager.SpawnEffect`) for visibility

### M105 — Ash Upgrade Stations
**What:** Permanent ability purchases using Ash currency at Heartstone Upgrade Stations.  
**How:**
- `AAshenUpgradeStationActor` at Sanctuary locations: displays `TArray<FAshenUpgradeRecord>` (each with `FGameplayTag GrantedAbilityTag`, `float AshCost`)
- On purchase: `ASC->GiveAbility()`, Ash deducted, saved; already-purchased items grayed out

### M106 — Geopolitical Resonance System
**What:** Pillar III — faction reputation driving world-state shifts.  
**How:**
- `UAshenGeopoliticalSubsystem` (GameInstance): `TMap<FName FactionTag, float ReputationScore>`
- Oath fulfillment with faction-tagged NPCs and Null Zone territory clearance modify reputation
- `UAshenDialogueSubsystem.GetAvailableNodes()` reads faction reputation to gate merchant inventory and NPC hostility

---

## PHASE XI — Visual & Audio Production
**Source: 3d-combat-model-pipeline.md + ENGINE-SPEC-001 Section 7 (Audio, Animation, Shader subsystem rows)**

### M107 — Global MPC Shader Architecture
**What:** Replace all per-MID `SetScalarParameterValue` calls with a unified `UMaterialParameterCollection` update pattern per Definitive Canon Appendix Engineering Note 3.  
**How:**
- Create `MPC_AshenOath` with parameters: `MPC_Corruption`, `MPC_Resolve`, `MPC_NullZoneProximity`, `MPC_OathBreachCount`, `MPC_Despair`, `MPC_IntegrationDebt`
- `USoulConstellationSubsystem.PublishStateVector()` updates all MPC scalars in one pass
- All materials (armor, Mindscape, Null Zone, post-process) reference MPC parameters instead of per-instance dynamics where possible

### M108 — Stance Blend Tree Wiring (Animation Engine)
**What:** `FBehavioralProfile.Stance` drives Kaelen's idle animation blend tree.  
**How:**
- AnimBP reads `GetSoulConstellation()->GetStateVector().ActiveProfile.Stance` via a Blueprint callable C++ getter
- `Hunched_Guarded` → blend weight 1.0 on hunched idle; `Upright_Grounded` → blend weight 1.0 on upright idle; linear interpolation between
- Sword drag weight adjusted via `AnimBP.SwordDragWeight` float parameter driven by `Resolve` inverse

### M109 — SOCKET VFX Anchoring System
**What:** Particle emitters attached to `AshenSocketNames.h` sockets in response to `OnStateVectorInvalidated`.  
**How:**
- `UVFXManager` extended with `SpawnAttachedEffect(FName SocketName, USkeletalMeshComponent* Mesh, UNiagaraSystem* System)`
- `Corruption > 0.7f` → crimson rim particle on `SOCKET_Eyes_L/R`; `Corruption > 0.9f` → ember trail on `SOCKET_BladeSeam`
- `SerafinaTrust > 0.7f` during support cast → golden light particle on `SOCKET_Locket`

### M110 — Dynamic Music State System
**What:** Musical key and intensity shifts from `FBehavioralProfile`.  
**How:**
- `UAshenAudioSubsystem` extended with `UpdateMusicState(const FAshenStateVector& State)`
- Subscribes to `OnStateVectorInvalidated`
- `ActiveProfile.Stance = Hunched_Guarded` → minor key, low-frequency drone up; `Shadow_Mark_Alpha > 0.7f` → dissonant brass stabs during Dark Mode

### M111 — Oathbringer Audio Pitch Modulation
**What:** Blade audio pitch shifts with `OathRegistryComponent.GetBrokenOathCount()`.  
**How:**
- `AAshenWeapon_Oathbringer` subscribes to `OnOathBroken`: applies `-50 cents` pitch offset per breach (max `-200 cents`) to swing audio assets

### M112 — Creature Archetype Material Assignment
**What:** `ECreatureArchetype` drives creature-specific shader configurations on possess.  
**How:**
- `AAshenAIController.OnPossess()` reads `ECreatureArchetype` from enemy and calls `VFXManager.AssignCreatureMaterial(ArchetypeTag, MeshComponent)`:
  - `BlightGhoul`: emissive green chest core pulsing
  - `AshenAbomination`: displacement-mapped cooled-ash + ember fractures
  - `AetherWeaver`: screen-space glitch distortion shader
  - `GeodeLurker`: anisotropic crystal + pulsing blue emissive

---

## PHASE XII — Endgame Systems
**Source: Pillar IV (Vigil System, Fugitive's Network, Prismatic Realm), Pillar IV (Remnant Chronicles)**

### M113 — The Vigil System
**What:** Long-arc challenge log — multi-stage oath/goal chains.  
**How:**
- `UAshenVigil_Registry` (GameInstance): `TArray<FVigilRecord>` with multi-stage objective chains
- Stage completion yields `Ash` and `Constellation_Harmony` delta at next `InvokeIntegration()`
- Serialized to save

### M114 — The Fugitive's Network
**What:** Hidden NPCs gated behind `Constellation_Harmony` and faction reputation thresholds.  
**How:**
- `AAshenFugitiveNPC`: visibility and dialogue gated behind `StateVector.Resolve > 0.55f` AND `GeopoliticalSubsystem.GetReputation(FactionTag) > 0.5f`
- `GameEventSubsystem.OnFugitiveDiscovered` fires on first interaction

### M115 — The Prismatic Realm & The Veil
**What:** Alternate dimensional layer accessible when `Corruption` peaks and a Vigil triggers.  
**How:**
- `DirectorSubsystem.EnterPrismaticRealm()`: async level stream of Veil sub-level
- Physics: `GetCharacterMovement()->GravityScale = -1.0f` inside the Veil
- Enemies: `AetherWeaver` archetypes with phased-out collision windows

### M116 — Remnant Chronicles System
**What:** Ghost projections of Kaelen's own past actions at key locations.  
**How:**
- `AAshenRemnantActor`: spawns at notable death/choice locations; replays simplified kinematic loop of archived action
- Interacting awards a `Memory Event` imprint
- Local replay data stored per world location in `UAshenSaveGame`

### M117 — Master Synthesis Audit (Pillar VI)
**What:** Final integration pass — verify all Pillar I–V systems map to compiled `FSoulStateVector` fields.  
**How:**
- Audit all Phase I–XII source files for `CMD_INSPECT_POINTER_SAFETY` compliance
- Run `CMD_COMPILER_DRY_RUN` full build validation
- End-to-end test: spawn Kaelen → enter Null Zone → accumulate Integration Debt to 50% → observe Memory Bleed effects → rest at Heartstone → complete Memory Battle → select Lens → verify `PublishStateVector()` fires and all downstream subsystems respond correctly

---

## Verification Plan

### Per Phase:
- **CMD_COMPILER_DRY_RUN**: Full `AshenOathEditor Win64 Development` UBT build must pass with 0 errors
- **CMD_INSPECT_POINTER_SAFETY**: No raw actor pointers without `UPROPERTY()`. No `new`/`delete`. Cyclical references use `TWeakObjectPtr`
- **`OnStateVectorInvalidated` chain test**: Trigger manual `PublishStateVector()` from editor PIE → verify Animation, Post-Process, Audio, AI, and Dialogue all respond within the same frame

### Manual Verification (User-Led):
- Confirm Integration Debt accumulates visibly during extended combat without resting
- Confirm Lens Selection widget appears at Heartstone and selection persists across save/load
- Confirm Serafina's spatial offset increases when `GarrettTrust` drops below `Cynical_Isolated` threshold
- Confirm Oathbringer pitch shifts after oath breaches
- Confirm Mindscape level-streams correctly and Memory Battle enemy spawns from imprint type

---

## Open Questions

> [!IMPORTANT]
> **Q1 — Mindscape Level**: Do you have a Mindscape sub-level in Greybox already, or does this need to be created from scratch? This determines the level-streaming scope of M71.

> [!IMPORTANT]
> **Q2 — Dialogue Middleware**: Custom C++ node graph, Blueprint-driven solution, or a Marketplace plugin (e.g., DialoguePlugin)? This shapes M94–M97 implementation depth significantly.

> [!IMPORTANT]
> **Q3 — Audio Middleware**: Unreal MetaSounds natively or Wwise/FMOD? This determines the exact API surface for M83, M105, M110–M111.

> [!NOTE]
> **Q4 — Art Pipeline**: Has `T_CorruptionMasks` (the RGBA channel-packed mask texture) and the modular skeletal mesh set been created in DCC yet, or should we build placeholder assignments and material stubs first?

> [!NOTE]
> **Q5 — Phase Priority**: Do you want strict Phase 0 → XII order, or is there a system from a later phase (e.g., Dialogue Engine, Audio) you want fast-tracked alongside the Kernel work for a vertical slice demo?
