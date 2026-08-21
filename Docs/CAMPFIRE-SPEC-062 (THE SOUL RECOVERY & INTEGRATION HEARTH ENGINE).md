# CAMPFIRE-SPEC-062: THE SOUL RECOVERY & INTEGRATION HEARTH ENGINE

**Canonical Document Identifier:** `CAMPFIRE-SPEC-062`  
**Master Batch:** #121 (Builds 2416–2435)  
**Total Production Builds:** 2,435 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Behavior Trees  
**Architecture Domain:** Narrative / Companions / Audio / UI / AI / World / Core / Orchestration / QA  
**Authority Level:** Canonical Master Specification  
**V-Control:** 2026-08-21T06:26:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`CAMPFIRE-SPEC-062` implements the emotional, reflective heart of Ashen Oath—the **Soul Recovery & Integration Hearth Engine**. It unifies the psychological runtime kernel (`ENGINE-SPEC-001`), the living physicalized journal (`JOURNAL-SPEC-055`), and long-term promises (`PROMISE-SPEC-059`) into a diegetic rest and trauma transmutation loop:

1. **Diegetic Campfire Integration Loop**:
   * Transmutes accumulated combat `Integration Debt` and battle trauma into permanent character traits during rest.
   * **Three-Tier Psychological Synthesis**:
     * **Minor Debt ($<0.30$)**: Quick restful recovery (+5% Stamina Regen).
     * **Moderate Debt ($0.30\text{--}0.70$)**: Reflective Transmutation (converts trauma into permanent $+10\%$ Poise or $+10\%$ Faith passives).
     * **Severe Crisis ($>0.70$)**: Solemn Vigil (requires shared campfire catharsis dialogue with Garrett or Serafina to resolve somatic distress).
2. **Dynamic Proximity Seating ($250\text{uu} \leftrightarrow 800\text{uu}$)**:
   * Companion seating positions around the hearth dynamically reflect active trust and dysregulation:
     * High trust / Low dysregulation $\implies$ Intimate proximity ($250\text{uu}$, shared fire warmth).
     * High dysregulation / Boundary standoff $\implies$ Guarded distance ($650\text{--}800\text{uu}$, back against the tree/ruins).
3. **Living Journal Marginalia Reader**:
   * Interactive diegetic book viewer allowing players to flip through historical pages, inspect companion notes (Garrett's charcoal, Serafina's golden ink), and mark entries as discovered (+0.05 Lorekeeper insight).

---

## 📐 2. The Campfire Rest & Trauma Transmutation Flow

```
[ Combat Trauma & Integration Debt ] ───► Enter Hearth Warmth Radius (800uu)
                                                       │
                                                       ▼
[ Evaluate Rest Tier (UAshenSoulRecoveryEvaluator) ]
 ├── Minor Rest (<0.30 Debt)          ──► +5% Stamina Regen Buff
 ├── Reflective Transmute (0.30-0.70) ──► Forges Permanent +10% Trait (Poise/Faith)
 └── Solemn Vigil (>0.70 Debt)        ──► Cleanses 100% Dysregulation via Catharsis Dialogue
                                                       │
                                                       ▼
[ Dynamic Seating Staging ] ─────────────► High Trust = 250uu (Intimate) | Low Trust = 800uu (Guarded)
                                                       │
                                                       ▼
[ Living Journal Inspection ] ───────────► Interactive Reader (Page Turns, Magnifying Focus, +0.05 Lore)
```

---

## 📦 3. Master Batch #121 Production Manifest (Builds 2416–2435)

### Phase 1: Data Contracts, Subsystems & Evaluators (Builds 2416–2420)
* **Build 2416 (`AshenCampfireHearthTypes.h`)**: Enums (2), Structs (2), Multicast Delegates (4).
* **Build 2417 (`UAshenCampfireHearthSubsystem`)**: Central world subsystem coordinating rest sessions, trauma transmutations, and seating staging.
* **Build 2418 (`UAshenSoulRecoveryEvaluatorComponent`)**: Evaluates raw `Integration Debt` and health status to select the appropriate rest tier.
* **Build 2419 (`UAshenProximitySeatingStagingComponent`)**: Computes companion seating offsets and rotation angles based on trust and dysregulation.
* **Build 2420 (`UAshenTraumaTransmutationEngineComponent`)**: Converts processed trauma debt into permanent psychological trait passives.

### Phase 2: Gameplay Abilities (GAS) & Rest Communion (Builds 2421–2425)
* **Build 2421 (`UAshenSolemnVigilRestGASAbility`)**: High-level rest ability executing solemn vigil catharsis and resetting dysregulation.
* **Build 2422 (`UAshenTraumaTransmutationSurgeGASAbility`)**: Ability applying permanent trait buffs upon completing campfire reflection.
* **Build 2423 (`UAshenReflectiveResonanceCommunionGASAbility`)**: Party communion ability granting +15% Holy Resistance and +10% Poise for the next exploration leg.
* **Build 2424 (`UAshenHearthEmberGroundingGASAbility`)**: Passive hearth aura grounding companions and purging residual shadow strain.
* **Build 2425 (`UAshenDeepRestorativeRenewalGASAbility`)**: Full recovery ability restoring 100% Resolve and clearing all physical injuries.

### Phase 3: AI Behavior Trees, Hearth Audio & Journal Reader HUD (Builds 2426–2430)
* **Build 2426 (`UBTTask_AshenSelectCampfireSeat`)**: Behavior Tree Task ordering companion to pathfind to their dynamically staged seating spot.
* **Build 2427 (`UBTTask_AshenPerformCampfireIdle`)**: Behavior Tree Task managing companion idle actions (sharpening blade, inspecting locket).
* **Build 2428 (`UAshenCampfireAudioFilterComponent`)**: Audio component modulating acoustic warmth, crackling embers, and wind suppression during rest.
* **Build 2429 (`UAshenUserWidget_LivingJournalReaderHUD`)**: Interactive UMG widget rendering page turns, magnifying inspection, and companion marginalia.
* **Build 2430 (`AAshenCampfireHearthAnchorActor`)**: 3D world campfire landmark managing seating transforms and rest interaction triggers.

### Phase 4: SaveGame, Dialogue Bridge, Mesh Adapters & QA Suite (Builds 2431–2435)
* **Build 2431 (`UAshenCampfireSaveGameAdapter`)**: Serializes total campfires rested, transmuted traits unlocked, and journal pages inspected.
* **Build 2432 (`UAshenCampfireTraumaDialogueBridge`)**: Injects trauma integration history and companion seating reflections into dialogue trees.
* **Build 2433 (`UAshenCompanionSeatingPoseMeshAdapter`)**: Modulates companion sitting blendspaces (relaxed campfire sit vs. alert resting pose).
* **Build 2434 (`UAshenCampfireHearthMasterBridge`)**: Master orchestrator connecting campfire rest events, state registry updates, and audio/UI.
* **Build 2435 (`FAshenMasterBatch121AutomationTest`)**: Comprehensive QA automation test suite validating rest tier evaluation, seating distances, and trait transmutation.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Narrative.MasterBatch121_CampfireHearth` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Three-Tier Evaluation** | Debt $< 0.30$, $0.30\text{--}0.70$, $> 0.70$ | Evaluates `MinorRest`, `ReflectiveTransmute`, `SolemnVigil` | **PASSED** |
| **Proximity Seating** | Trust $= 0.80$, Dysregulation $= 0.20$ vs. $0.75$ | Returns $250.0\text{uu}$ (Intimate) vs. $800.0\text{uu}$ (Guarded) | **PASSED** |
| **Trait Transmutation** | Forge `UnbrokenResolve` trait with $+0.10$ scalar | Creates trait and increments unlocked traits count | **PASSED** |
| **SaveGame Serialization** | Rests $= 12$, Traits $= 4$, Notes $= 18$ | Exact data restoration across serialization cycles | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,415 Builds (`TRIO-SPEC-061`)
* **Current Milestone**: **2,435 Builds (`CAMPFIRE-SPEC-062`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
