# PROMISE-SPEC-059: LONG-TERM CANONICAL PROMISE RESOLUTION & CAMPFIRE MARGINALIA INCURSIONS

**Canonical Document Identifier:** `PROMISE-SPEC-059`  
**Master Batch:** #118 (Builds 2356–2375)  
**Total Production Builds:** 2,375 Builds  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Behavior Trees  
**Architecture Domain:** Narrative / Companions / Combat / UI / Audio / AI / World / Core / Orchestration / QA  
**Authority Level:** Canonical Master Specification  
**V-Control:** 2026-08-20T18:15:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`PROMISE-SPEC-059` delivers the emotional bedrock of Ashen Oath's narrative architecture codified in Sophia's dialogue (#9, #11, #14):

1. **The Canonical Promise Ledger**:
   * Promises made during quiet campfire moments (e.g. *"I'll get you home"*, *"I won't let the fire consume you"*) are permanently recorded into an authoritative, persistent ledger (`UAshenPromiseLedgerComponent`).
   * When extreme crisis conditions occur, the **Semantic Context Matcher** reactivates dormant promises:
     * Companion callout: *"You promised!"*
     * Incurs high-stakes Trial of Will struggles or grants `UAshenSteadfastVowWillpowerSurgeGASAbility` (+40% Poise / +25% Willpower).
     * Breaking a promise triggers catastrophic Poise Crack (`UAshenPromiseBetrayalPoiseCrackGASAbility`) and permanent trust degradation.
2. **Unnotified Retroactive Marginalia Incursions**:
   * Companions secretly inscribe commentary onto **historical journal pages** (Garrett's charcoal, Serafina's golden ink).
   * No HUD notification or UI toast is shown; discoveries occur organically when the player flips back through the journal (*"She has been reading me"* / *"He looked afraid"*).

---

## 📐 2. The Promise & Marginalia Lifecycle

```
[ Sworn Vow at Campfire ] ──────► Registered in UAshenPromiseLedgerComponent (Status: Active)
                                                    │
                                                    ▼
[ Crisis Encounter (Cataclysm / Defeat) ] ──────► UAshenSemanticContextMatcherComponent
                                                    │
             ┌──────────────────────────────────────┴──────────────────────────────────────┐
             ▼                                                                             ▼
   [ Vow Upheld & Honored ]                                                      [ Vow Broken / Abandoned ]
   • Ability: Steadfast Vow Surge (+40% Poise)                                   • Ability: Betrayal Poise Crack (0 Poise)
   • Status: Fulfilled (+Grace, High Trust)                                      • Status: Betrayed (-Trust, +Wrath)
   • Audio: Vow Resonance Harmonic Chime                                         • Audio: Low Dissonance Distortion
   • Journal: Secret Retroactive Golden Inscription                              • Journal: Scratched Out Charcoal Trace
```

---

## 📦 3. Master Batch #118 Production Manifest (Builds 2356–2375)

### Phase 1: Data Contracts, Subsystems & Evaluators (Builds 2356–2360)
* **Build 2356 (`AshenCanonicalPromiseTypes.h`)**: Enums (3), Structs (2), Multicast Delegates (4).
* **Build 2357 (`UAshenCanonicalPromiseSubsystem`)**: Central world subsystem coordinating promise tracking, crisis context evaluations, and unnotified marginalia generation.
* **Build 2358 (`UAshenPromiseLedgerComponent`)**: Authoritative component storing and managing active/fulfilled/broken canonical promises.
* **Build 2359 (`UAshenSemanticContextMatcherComponent`)**: Evaluates real-time combat/world crisis events against active promises to trigger reactivations.
* **Build 2360 (`UAshenRetroactiveMarginaliaInscriberComponent`)**: Generates companion ink and charcoal inscriptions on historical journal pages.

### Phase 2: Gameplay Abilities (GAS) & Combat Finishers (Builds 2361–2365)
* **Build 2361 (`UAshenSteadfastVowWillpowerSurgeGASAbility`)**: Vow ability granting +40% Poise and +25% Willpower when upholding a promise in crisis.
* **Build 2362 (`UAshenSacredOathReckoningStrikeGASAbility`)**: High-damage holy strike empowered by remembered sacred vows (+20% Holy Damage).
* **Build 2363 (`UAshenPromiseBetrayalPoiseCrackGASAbility`)**: Debuff ability instantly shattering posture to 0.0 upon breaking a promise.
* **Build 2364 (`UAshenPromiseBondStealtheadAuraGASAbility`)**: Passive trio aura granting +15% damage mitigation when in mutual promise alignment.
* **Build 2365 (`UAshenCompanionPromiseGroundingGASAbility`)**: Companion ability invoking the sacred vow to pull Kaelen out of dark corruption frenzy.

### Phase 3: AI Behavior Trees, Ambient Audio & Journal Shaders (Builds 2366–2370)
* **Build 2366 (`UBTTask_AshenEvaluatePromiseContext`)**: Behavior Tree Task checking whether an active promise should be reactivated in combat.
* **Build 2367 (`UBTTask_AshenEnforcePromiseLoyalty`)**: Behavior Tree Task locking companion to Kaelen's side when a sacred promise is active.
* **Build 2368 (`UAshenPromiseVowAudioEmitterComponent`)**: Emits sacred chimes and sub-bass harmonic resonance when vows are activated.
* **Build 2369 (`UAshenUserWidget_JournalRetroactiveMarginaliaHUD`)**: UMG/Slate widget rendering secret companion annotations on journal pages.
* **Build 2370 (`AAshenPromiseVowAnchorActor`)**: 3D world landmark entity marking a sacred location where a canonical promise was sworn.

### Phase 4: SaveGame, Dialogue Bridge, Mesh Adapters & QA Suite (Builds 2371–2375)
* **Build 2371 (`UAshenPromiseSaveGameAdapter`)**: Serializes active/fulfilled/broken promises and retroactive marginalia entries.
* **Build 2372 (`UAshenPromiseReflectionDialogueBridge`)**: Injects active, fulfilled, or broken vows into campfire dialogue trees.
* **Build 2373 (`UAshenCompanionPromiseBondMeshAdapter`)**: Modulates companion posture blendspaces (resolute stance, hand-on-chest) during vows.
* **Build 2374 (`UAshenCanonicalPromiseMasterBridge`)**: Master orchestrator coordinating promise events, state registry updates, and audio/UI.
* **Build 2375 (`FAshenMasterBatch118AutomationTest`)**: Comprehensive QA automation test suite validating promise lifecycle, context matching, and marginalia inking.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Narrative.MasterBatch118_CanonicalPromises` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Promise Registration & Lifecycle** | Swear promise $\to$ Fulfill | Status shifts `Active` $\to$ `Fulfilled`; active count decrements | **PASSED** |
| **Semantic Context Matching** | Crisis event matches companion & tag | Context matches active promise $\implies \text{True}$ | **PASSED** |
| **Mismatched Companion Rejection** | Different companion present | Matches crisis context $\implies \text{False}$ | **PASSED** |
| **Retroactive Marginalia Inscription** | Serafina writes on Page 4 | Undiscovered annotation created with golden ink medium | **PASSED** |
| **SaveGame Serialization** | Active $= 3$, Fulfilled $= 5$, Marginalia $= 8$ | Exact count and struct restoration across serialization cycles | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,355 Builds (`MIND-SPEC-058`)
* **Current Milestone**: **2,375 Builds (`PROMISE-SPEC-059`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
