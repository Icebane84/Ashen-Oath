# BURDEN-SPEC-057: THE EMPATHIC TRANSFERENCE & SHADOW BURNOUT MATRIX

**Canonical Document Identifier:** `BURDEN-SPEC-057`  
**Master Batch:** #116 (Builds 2316–2335)  
**Total Production Builds:** 2,335 Builds  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Behavior Trees  
**Architecture Domain:** Companions / Combat / AI / Audio / UI / Narrative / World / Core / Orchestration / QA  
**Authority Level:** Canonical Master Specification  
**V-Control:** 2026-08-20T15:15:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`BURDEN-SPEC-057` closes the loop on the **3 Core Combat Intent Axes** codified in `PRS-DOC-2026-0820-004`:

1. **Axis 1 (Formation Breaks)**: Implemented in `INTENT-SPEC-056`.
2. **Axis 2 (Empathic Transference & Physiological Burnout)**:
   * Healing is a physical burden transfer, not a free spell cooldown. When Serafina stabilizes Kaelen, she absorbs his somatic trauma, incurring progressive physical burnout:
     * `Nominal` ($<25$), `Strained` ($25\text{--}50$), `Exhausted` ($50\text{--}80$), `CriticalCollapse` ($>80$).
     * Scaled dodge/recovery animation delays ($+0.20\text{s}$ per tier up to $+0.60\text{s}$).
     * Voice pitch compression, labored breathing audio, and dimming light aura VFX.
     * Progressive hesitation and transference delay on future healing triage evaluations.
3. **Axis 3 (Mercy vs. Execution on Staggered Foes & Shadow Mark Overuse)**:
   * **Mercy vs. Execution**: Dual character ontologies (Garrett weighs tactical threat/pragmatism; Serafina weighs moral purity/grief). Sparing (`MercifulBinding`) awards +Grace and strengthens Serafina's moral resolve; executing (`RuthlessExecution`) awards +Wrath, approved pragmatically by Garrett on lethal foes while causing moral grief to Serafina.
   * **Shadow Mark Restraint**: Overusing dark corruption abilities in combat triggers companion verbal warnings ($>0.35$) and physical body-block grounding interventions ($>0.70$).

---

## 📐 2. The Transference & Moral Evaluation Flow

```
                                [ Incoming Trauma on Kaelen ]
                                              │
                                              ▼
                         [ Serafina Casts Empathic Transference ]
                                              │
                                              ▼
                        [ Trauma Absorbed -> Serafina Burnout ]
                                              │
         ┌────────────────────────────────────┼────────────────────────────────────┐
         ▼                                    ▼                                    ▼
[ Somatic Degradation ]             [ Audio & Visual Strain ]            [ AI Triage Delay ]
  • Recovery Delay +0.20s-0.60s       • Pitch Compression (0.80x)          • Progressive Hesitation
  • Shoulder Slump Mesh Weight        • Labored Breathing Mixed            • Refusal at Critical
  • Stamina Regen Penalty             • Dimming Light Aura (MPC)           • Campfire Reset Required
```

---

## 📦 3. Master Batch #116 Production Manifest (Builds 2316–2335)

### Phase 1: Core Data Contracts, Transference & Moral Evaluators (Builds 2316–2320)
* **Build 2316 (`AshenTransferenceBurnoutTypes.h`)**: Enums (3), Structs (2), Multicast Delegates (4).
* **Build 2317 (`UAshenEmpathicTransferenceSubsystem`)**: Central world subsystem coordinating transference costs, moral evaluations, and companion fatigue.
* **Build 2318 (`UAshenSerafinaBurnoutReceiverComponent`)**: Serafina's somatic component tracking absorbed trauma, recovery frame delays, and aura stability.
* **Build 2319 (`UAshenStaggerResolutionEvaluatorComponent`)**: Evaluates companion reactions to Kaelen sparing vs executing staggered foes.
* **Build 2320 (`UAshenShadowOveruseAuditorComponent`)**: Audits Kaelen's dark ability usage frequency and triggers companion confrontation interventions.

### Phase 2: Gameplay Abilities (GAS) & Combat Finishers (Builds 2321–2325)
* **Build 2321 (`UAshenEmpathicTransferenceGASAbility`)**: Serafina's sacrificial heal ability absorbing Kaelen's trauma at physiological cost.
* **Build 2322 (`UAshenSomaticBurnoutDebuffGASAbility`)**: Passive GAS ability applying recovery delays and stamina penalties based on burnout tier.
* **Build 2323 (`UAshenMercyBindingGASAbility`)**: Kaelen's non-lethal binding ability sparing a staggered foe (+Grace, +Serafina Trust).
* **Build 2324 (`UAshenRuthlessExecutionGASAbility`)**: Kaelen's brutal execution finisher (+Wrath, +Garrett Pragmatic Approval, -Serafina Grief).
* **Build 2325 (`UAshenShadowRestraintGroundingGASAbility`)**: Companion ability physically grounding Kaelen when Shadow Mark corruption spikes dangerously.

### Phase 3: AI Behavior Trees, Diegetic Audio & UI Shaders (Builds 2326–2330)
* **Build 2326 (`UBTTask_AshenEvaluateStaggerChoice`)**: Behavior Tree Task evaluating whether companion encourages mercy or execution.
* **Build 2327 (`UBTTask_AshenSerafinaTransferenceTriage`)**: Behavior Tree Task evaluating if Serafina's current burnout allows another heal without fatal collapse.
* **Build 2328 (`UAshenBurnoutAudioStrainComponent`)**: Dynamically filters companion voice pitch and mixes heavy somatic breathing as burnout escalates.
* **Build 2329 (`UAshenUserWidget_TransferenceAuraOverlayHUD`)**: UMG/Slate overlay rendering golden transference tethers and soot creep.
* **Build 2330 (`AAshenStaggeredEliteAnchorActor`)**: 3D world encounter entity representing a staggered enemy awaiting Mercy or Execution.

### Phase 4: SaveGame, Narrative Bridge, Mesh Fatigue & QA Suite (Builds 2331–2335)
* **Build 2331 (`UAshenTransferenceSaveGameAdapter`)**: Serializes cumulative burnout levels, mercy counts, and execution imprints.
* **Build 2332 (`UAshenTransferenceDialogueBridge`)**: Injects fatigue and execution history into campfire dialogues and living journal notes.
* **Build 2333 (`UAshenCompanionFatigueMeshAdapter`)**: Modulates skeletal blendspaces, adding shoulder slump and slower recovery anims.
* **Build 2334 (`UAshenTransferenceMasterBridge`)**: Macro-systemic bridge coordinating Transference Subsystem, Soul State Registry, and Audio/UI.
* **Build 2335 (`FAshenMasterBatch116AutomationTest`)**: Deep QA automation test suite validating all transference and moral evaluation pathways.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Companions.MasterBatch116_TransferenceBurnout` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Serafina Burnout Tiers** | Trauma $= 30.0, 60.0$ | $\text{Tiers} = \text{Strained}, \text{Exhausted}; \, \text{Penalties} = 0.20\text{s}, 0.40\text{s}$ | **PASSED** |
| **Campfire Burnout Reset** | Reset invoked | $\text{CumulativeBurnout} = 0.0, \, \text{Tier} = \text{Nominal}$ | **PASSED** |
| **Mercy Binding Evaluation** | Target spared | $\Delta \text{SerafinaMoral} > 0, \, \text{Dialogue} = \text{"cleanses"}$ | **PASSED** |
| **Ruthless Execution Evaluation** | High-threat elite executed | $\Delta \text{GarrettPragmatic} > 0, \, \Delta \text{SerafinaMoral} < 0$ | **PASSED** |
| **Shadow Overuse Auditor** | Corruption $= 0.45, 0.80$ | $\text{Responses} = \text{VerbalCaution}, \text{PhysicalIntervention}$ | **PASSED** |
| **SaveGame Serialization** | Burnout $= 45.5$, Mercy $= 7$, Exec $= 2$ | Exact restoration of floats and integers | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,315 Builds (`INTENT-SPEC-056`)
* **Current Milestone**: **2,335 Builds (`BURDEN-SPEC-057`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
