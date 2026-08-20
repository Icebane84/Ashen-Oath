# ECOL-SPEC-053: THE ECOLOGY OF FELLOWSHIP & REMEMBERED REPAIR MATRIX

**Canonical Document Identifier:** `ECOL-SPEC-053`  
**Master Batch:** #112 (Builds 2236–2255)  
**Total Production Builds:** 2,255 Builds  
**Target Engine:** Unreal Engine 5.8 C++  
**Architecture Domain:** Companions / Relational Ecology / Soul / Memory / Combat / Audio / UI / AI / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Master Specification  
**V-Control:** 2026-08-20T09:40:00Z  

---

## 🏛️ 1. Executive Summary & Creative Thesis

`ECOL-SPEC-053` codifies the **Ecology of Fellowship** runtime engine for *Ashen Oath*. It formally replaces superficial "affinity meters" and transactional "+5 Approval" vending-machine dialogue choices with a **living, asymmetric relational ecosystem** governed by:

1. **Pattern Continuity**: Relationships are defined by witnessed action under lethal pressure, not abstract verbal agreement.
2. **Love as Costly Presence**: Companions express loyalty through physical sacrifice—sliding into the mud to parry lethal blows or taking grey soot onto their wrists.
3. **Faith as Action Under Uncertainty**: Companions override biological self-preservation instincts when historical repair memories outweigh immediate tactical terror.
4. **Friendship as Remembered Repair**: Ruptures are healed through sustained kinetic actions and campfire processing across hours, culminating in wordless combat reconciliation.
5. **The Multi-Author Living Journal**: Three subjective vantage points (Kaelen's prose, Garrett's charcoal diagrams, and Serafina's silverleaf pressings) continuously record their shared survival.

---

## 📐 2. The Deterministic Faith Equation & Mathematical Contracts

### 2.1 The Deterministic Faith Equation
$$\text{FaithThreshold} = \text{Clamp}\Big( 0.50 \cdot \text{ImmediateThreat} - 0.40 \cdot \text{ActiveRepairVelocity}, \,\, 0.15, \,\, 0.85 \Big)$$

$$\text{ShouldExecuteCostlyPresence} = \Big(\text{CompanionTrust} \ge \text{FaithThreshold}\Big)$$

### 2.2 Active Repair Velocity & Synarchy Ratio
$$\text{SynarchyRatio} = \frac{\text{SyncFinishersExecuted} + \text{CompanionRescues}}{\text{TotalRelevantEvents}}$$

$$\text{ActiveRepairVelocity} = \text{SynarchyRatio} \times \text{Clamp}\left(\frac{\text{ConsecutiveCohesionBeats}}{10.0}, \,\, 0.0, \,\, 1.0\right)$$

### 2.3 Asymmetric Companion Relational Axes
* **Garrett's Axis (*Predictability & Terror of Helplessness*)**:
  $$\text{Offset}_{\text{Garrett}} = \text{Lerp}\Big(250.0\,\text{uu}, \,\, 800.0\,\text{uu}, \,\, \text{Clamp}\big(0.50 \cdot \Phi_{\text{internal}} + 0.35 \cdot (1.0 - \text{Trust}_{\text{Garrett}}) + 0.15 \cdot \text{Fatigue}_{\text{Garrett}}, \,\, 0.0, \,\, 1.0\big)\Big)$$
* **Serafina's Axis (*Radical Empathy & Spiritual Boundaries*)**:
  $$\text{CrisisSanctuaryCondition} = \Big(\Phi_{\text{internal}} \ge 0.70\Big) \land \Big(\text{Trust}_{\text{Serafina}} \ge 0.40\Big) \land \Big(\text{ActiveRepairVelocity} \ge 0.25\Big)$$

---

## 📦 3. Master Batch #112 Production Manifest (Builds 2236–2255)

### Phase 1: Core Relational Ecology Subsystem & Mathematical Evaluators (Builds 2236–2240)
* **Build 2236 (`AshenRelationalEcologyTypes.h`)**: Enums (`ECompanionInterventionType`, `ERelationalRuptureState`, `EAuthorIdentity`), Structs (`FAshenRepairMatrix`, `FAshenCostlyPresenceIntent`, `FAshenMultiAuthorMarginEntry`), and 6 master lifecycle multicast delegates.
* **Build 2237 (`UAshenRelationalEcologySubsystem`)**: Central world subsystem evaluating `ActiveRepairVelocity`, dynamic faith thresholds, and asymmetric companion axes.
* **Build 2238 (`UAshenPatternContinuityComponent`)**: Evaluates historical memory imprint graph nodes for rupture and repair streaks.
* **Build 2239 (`UAshenGarrettTacticalPredictabilityComponent`)**: Modulates Garrett's dynamic follow-distance ($250\,\text{uu} \leftrightarrow 800\,\text{uu}$) based on Kaelen's internal friction and trust.
* **Build 2240 (`UAshenSerafinaEmpathicBoundaryComponent`)**: Governs Serafina's empathic transference threshold and crisis sanctuary wards based on historical repair weight.

### Phase 2: Dynamic AI Intercepts & Costly Presence GAS Abilities (Builds 2241–2245)
* **Build 2241 (`UAshenCostlyPresenceInterventionGASAbility`)**: Executes companion physical sacrifice/interception when Kaelen is staggered under lethal threat ($1.45\times$ sprint).
* **Build 2242 (`UAshenWordlessReconciliationGASAbility`)**: Unlocks and executes high-risk synchronized flank strikes (1500 Poise DMG) following sustained repair streaks.
* **Build 2243 (`UAshenEmpathicTransferenceSootGASAbility`)**: Serafina absorbs Kaelen's internal dysregulation, transferring physical soot onto her wrists.
* **Build 2244 (`AAshenConsecratedSanctuaryAltarActor`)**: 3D world altar where companions process relational debt and reflect on witnessed choices.
* **Build 2245 (`AAshenRuptureScarAnchorActor`)**: 3D world spatial anchor marking historical rupture and reconciliation sites with dynamic acoustic timbre.

### Phase 3: AI Behavior Tree Tasks, Diegetic Audio & Living Journal Shaders (Builds 2246–2250)
* **Build 2246 (`UBTTask_AshenRelationalIntercept`)**: Behavior tree task forcing companion AI to sprint across the battlefield at $1.45\times$ speed to shield staggered Kaelen.
* **Build 2247 (`UAshenFellowshipDiegeticAudioComponent`)**: Modulates companion breathing, blade sharpening, and campfire silence based on relational resonance.
* **Build 2248 (`UAshenUserWidget_LivingJournalMultiAuthorHUD`)**: UMG Widget displaying Kaelen's prose, Garrett's charcoal diagrams, and Serafina's silver leaf notes.
* **Build 2249 (`UAshenUserWidget_CostlyPresencePromptHUD`)**: Subtle diegetic visual prompt when companion executes an unprompted sacrificial intercept.
* **Build 2250 (`UAshenRelationalPostProcessAdapter`)**: Dynamically adjusts warm hearthfire ambient glow vs cold estrangement desaturation based on TrioResonance.

### Phase 4: Adapters, Master Bridge, SaveGame & Value-Asserting QA (Builds 2251–2255)
* **Build 2251 (`UAshenCompanionMeshSootAdapter`)**: Drives procedural soot creep on Serafina's wrists and mud/dent shaders on Garrett's armor.
* **Build 2252 (`UAshenRelationalEcologySaveGameAdapter`)**: Serializes `FAshenRepairMatrix`, rupture states, and multi-author journal marginalia.
* **Build 2253 (`UAshenFellowshipDialogueAdapter`)**: Governs subtle wordless glances, hesitated barks, and posture shifts.
* **Build 2254 (`UAshenRelationalEcologyMasterBridge`)**: Master orchestrator binding the Pattern Continuity Engine to GAS, AI, and the Canonical State Registry.
* **Build 2255 (`FAshenMasterBatch112AutomationTest`)**: Deep QA automation test verifying the Faith Equation, repair velocity, intercept gating, and asymmetric companion axes.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Ecology.MasterBatch112_FellowshipAndRepair` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Faith Threshold: Low Threat** | Threat = 0.20, Repair = 0.0 | $\text{FaithThreshold} = 0.15$ (Min Clamp) | **PASSED** |
| **Faith Threshold: Repaired Crisis** | Threat = 0.90, Repair = 0.80 | $\text{FaithThreshold} = 0.15$ (Min Clamp) | **PASSED** |
| **Faith Threshold: Unrepaired Crisis** | Threat = 0.90, Repair = 0.0 | $\text{FaithThreshold} = 0.45$ | **PASSED** |
| **Repair Matrix: Synarchy Streak** | 3 Sync Finishers | $\text{Consecutive} = 3, \, \text{Ratio} = 1.0, \, \text{Velocity} = 0.30$ | **PASSED** |
| **Costly Presence Gating** | Trust = 0.50, Threat = 0.60 | $\text{Approved} = \text{TRUE}$ | **PASSED** |
| **Rupture Reset** | Companion Conflict added | $\text{Consecutive} = 0, \, \text{State} = \text{ActiveRupture}$ | **PASSED** |
| **Garrett Tactical Spacing** | Friction = 0.0, Trust = 1.0 $\to$ Friction = 1.0, Trust = 0.0 | $250.0\,\text{uu} \longrightarrow 800.0\,\text{uu}$ | **PASSED** |
| **Serafina Transference Soot** | Absorbed Dysregulation = 0.40 | $\text{ResidualSoot} = 0.30$ | **PASSED** |
| **Crisis Sanctuary Ward** | Friction = 0.85, Trust = 0.50, Repair = 0.35 | $\text{CastSanctuary} = \text{TRUE}$ | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,235 Builds (`ORCH-SPEC-052`)
* **Current Milestone**: **2,255 Builds (`ECOL-SPEC-053`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
