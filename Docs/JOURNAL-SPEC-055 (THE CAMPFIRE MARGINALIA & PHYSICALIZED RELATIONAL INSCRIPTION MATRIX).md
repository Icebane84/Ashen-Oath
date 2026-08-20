# JOURNAL-SPEC-055: THE CAMPFIRE MARGINALIA & PHYSICALIZED RELATIONAL INSCRIPTION MATRIX (CMM-001)

**Canonical Document Identifier:** `JOURNAL-SPEC-055`  
**Master Batch:** #114 (Builds 2276–2295)  
**Total Production Builds:** 2,295 Builds  
**Target Engine:** Unreal Engine 5.8 C++  
**Architecture Domain:** Companions / UI / Soul / Memory / Core Architecture / Audio / AI / Narrative / Orchestration / QA  
**Authority Level:** Canonical Master Specification  
**V-Control:** 2026-08-20T10:00:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`JOURNAL-SPEC-055` codifies the **Campfire Marginalia Subsystem (CMM-001)** for *Ashen Oath*.

In conventional tactical RPGs, the journal is a sterile, omniscient quest log with static UI checkboxes. In *Ashen Oath*, the journal is an **immutable, living relational battlefield** where Garrett, Serafina, and Kaelen converse, cross out each other's plans, and express unresolved tension through physical penmanship, ink degradation, and botanical pressings during campfire and Heartstone rests.

```
[ Heartstone Rest / Campfire Trigger ]
                  │
                  ▼
[ Snapshot: FCanonicalSoulStateVector + Imprint Buffer ]
                  │
                  ▼
[ Companion Marginalia Evaluator Component (C++) ]
  ├── Garrett Evaluator (Tactical / Survival Focus)
  └── Serafina Evaluator (Empathic / Moral Focus)
                  │
                  ▼
[ Zero-Hallucination Provenance Check & Tag Registry ]
                  │
                  ▼
[ Spatial Layout Engine (90/140 Char Anti-Collision Clamping) ]
                  │
                  ▼
[ Living Journal Page Spread (Slate / UMG Actuator) ]
  • Penmanship Dynamics (Jitter, Ink Bleed, Pressure)
  • Margin Layout Slots (Left/Right Margins, Footer, Crossout Overlays)
```

---

## 📐 2. The Spatial Envelope & Anti-Collision Anchor Architecture

To prevent dynamic companion text from overlapping into unreadable UI mush, the `UAshenMarginaliaSpatialLayoutEngine` enforces strict character-count budgets and spatial slot allocation:

```
┌───────────────────────────────────────────────────────────┐
│ [LeftMargin_Upper]                   [RightMargin_Upper]  │
│ Max: 90 chars (Serafina)             Max: 90 chars (Garrett)│
│                                                           │
│ ┌───────────────────────────────────────────────────────┐ │
│ │  [PARAGRAPH CORE: Kaelen's Lens-Derived Prose]         │ │
│ │  Dynamic Ink Bleed & Vertex Jitter Shader Pass        │ │
│ └───────────────────────────────────────────────────────┘ │
│                                                           │
│ [LeftMargin_Lower]                   [RightMargin_Lower]  │
│ Max: 90 chars                        Max: 90 chars        │
│ ───────────────────────────────────────────────────────── │
│ [FOOTER ANCHOR: Cross-out Overwrites / Botanical Pressing] │
│ Max: 140 chars                                            │
└───────────────────────────────────────────────────────────┘
```

* **Slot Clamping**: Text exceeding 90 characters in margin slots or 140 characters in footer slots is clamped cleanly with trailing ellipsis.
* **Collision Avoidance**: If multiple annotations target the same slot, secondary entries are dynamically shifted to the nearest open margin slot.

---

## 📦 3. Master Batch #114 Production Manifest (Builds 2276–2295)

### Phase 1: Core Data Contracts, Layout Anchors & Spatial Budgets (Builds 2276–2280)
* **Build 2276 (`AshenCampfireMarginaliaTypes.h`)**: Enums (`EMarginaliaAuthor`, `EMarginAnchorSlot`, `EInkDensityState`), Structs (`FMarginaliaVisualParams`, `FMarginaliaEntry`, `FAshenMarginaliaIngestPacket`), and 4 master multicast delegates.
* **Build 2277 (`UAshenCompanionMarginaliaEvaluatorComponent`)**: Evaluates soul state, trust vectors, and recent memory imprints to generate multi-author companion annotations.
* **Build 2278 (`UAshenMarginaliaSpatialLayoutEngine`)**: Spatial envelope manager enforcing 90/140 char budgets and resolving slot collisions.
* **Build 2279 (`UAshenDeterministicMarginaliaFallbackProvider`)**: Pre-authored character-authentic annotations keyed to memory tokens and trust tiers.
* **Build 2280 (`UAshenMarginaliaProvenanceValidator`)**: Cross-references target memory IDs against active imprint buffers to discard unearned citations.

### Phase 2: Slate/UMG Actuator Widgets & Dynamic Shaders (Builds 2281–2285)
* **Build 2281 (`UAshenUserWidget_LivingJournalSpreadPageHUD`)**: Multi-layer UMG/Slate widget for physical parchment, Kaelen's core text, and companion margin slots.
* **Build 2282 (`UAshenUserWidget_MarginaliaAnnotationSlotHUD`)**: Individual margin anchor slot with scratch-out overlays and handwriting font styling.
* **Build 2283 (`UAshenParchmentDynamicMaterialAdapter`)**: Drives dynamic vertex jitter (`JitterOffset = Sin(Time * 20.0) * JitterIntensity`) and ink bleed runtime texture masks.
* **Build 2284 (`AAshenCampfireJournalCommunionActor`)**: 3D world campfire interaction point triggering page updates and party reflection.
* **Build 2285 (`UAshenMarginaliaPenmanshipGASAbility`)**: GAS ability triggering dynamic penmanship updates upon memory crystallization.

### Phase 3: AI Behavior Query, Diegetic Audio & Environmental Shaders (Builds 2286–2290)
* **Build 2286 (`UBTTask_AshenCampfireJournalAudit`)**: Companion AI behavior tree task triggering writing/sketching animations at camp.
* **Build 2287 (`UAshenPenmanshipDiegeticAudioComponent`)**: Charcoal scratching, quill scratching, and page turning audio routing.
* **Build 2288 (`UAshenUserWidget_MarginaliaCrossoutOverlayHUD`)**: Animated violent strike-through lines and heavy charcoal scratches.
* **Build 2289 (`UAshenBotanicalPressingAdapter`)**: Renders Serafina's pressed silverleaf herbs in the margin canvas.
* **Build 2290 (`UAshenJournalPageTurnPostProcessAdapter`)**: Atmospheric camera Depth-Of-Field focus when opening the journal at camp.

### Phase 4: SaveGame Serialization, Master Bridge & Value-Asserting QA (Builds 2291–2295)
* **Build 2291 (`UAshenCampfireMarginaliaSaveGameAdapter`)**: Serializes historical margin entries, cross-outs, and slot bindings.
* **Build 2292 (`UAshenMarginaliaDialogueBridge`)**: Injects margin corrections into next-day campfire conversation choices.
* **Build 2293 (`UAshenMarginaliaMeshAdapter`)**: Dynamic skeletal prop mesh for the physical leather journal in Kaelen's hands.
* **Build 2294 (`UAshenCampfireMarginaliaMasterBridge`)**: Master orchestrator connecting IVC, State Registry, and Slate UI.
* **Build 2295 (`FAshenMasterBatch114AutomationTest`)**: Deep QA automation test verifying slot budget clamping, collision resolution, provenance rejection, and jitter math.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Companions.MasterBatch114_CampfireMarginalia` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Character Budget Clamping** | Margin text length = 145 chars | $\text{ClampedLen} \le 90, \, \text{EndsWith} = \text{"..."}$ | **PASSED** |
| **Spatial Collision Resolution** | 2 entries targeting `RightMargin_Lower` | $\text{Entry1} = \text{RightMargin\_Lower}, \, \text{Entry2} \neq \text{RightMargin\_Lower}$ | **PASSED** |
| **Provenance Audit Validation** | Target Memory = `mem_unvisited_999` | Discarded; only `mem_sanctuary_001` retained | **PASSED** |
| **Deterministic Fallback** | Soul State: `Grace`, Dysreg: 0.20 | Generates 2 annotations (Garrett & Serafina) | **PASSED** |
| **Vertex Jitter Math** | Integration Debt = 1.0, $t = 0.0$ | $\text{JitterIntensity} = 0.15, \, \text{Offset}(0) = 0.0$ | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,275 Builds (`VOICE-SPEC-054`)
* **Current Milestone**: **2,295 Builds (`JOURNAL-SPEC-055`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
