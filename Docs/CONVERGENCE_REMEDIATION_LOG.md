# Ashen Oath — Causal Convergence & Mechanics Wiring Remediation Log

**Governing Directives:**
* Sentinel Audit: [`Ashen_Oath_Theater_Pattern_Audit.md`](file:///C:/Users/Chris/Where%20Light%20Fades/Ashen%20Oath/Design%20and%20Technical/Ashen_Oath_Theater_Pattern_Audit.md)
* Remediation Guide: [`Ashen_Oath_Wiring_Remediation_Guide.md`](file:///C:/Users/Chris/Where%20Light%20Fades/Ashen%20Oath/Design%20and%20Technical/Ashen_Oath_Wiring_Remediation_Guide.md)
* Zero Entropy & Value-Asserting Test Mandate (AES $\ge 8$)

---

## 📊 Remediation Roadmap Status

```
┌─────────────────────────────────────────────────────────────────────────────────────────────┐
│                            CONVERGENCE & REMEDIATION PROGRESS MATRIX                        │
└─────────────────────────────────────────────────────────────────────────────────────────────┘
                                               │
       ┌───────────────────┬───────────────────┼───────────────────┐
       ▼                   ▼                   ▼                   ▼
[ PRIORITY 1: DUALITY ] [ PRIORITY 2: OATHS ] [ PRIORITY 3: TRIO ] [ PRIORITY 4: TRIAGE ]
   [100% COMPLETE]         [READY TO WIRE]      [READY TO WIRE]     [READY TO PURGE]
```

| Priority Layer | Target Domain | Key Components & Subsystems | Verification Suite | Status |
| :--- | :--- | :--- | :--- | :--- |
| **Priority 1: Duality Pipeline** | `Soul/`, `World/`, `Combat/` | `UAshenSovereignDualityTransformationAbility`, `UAshenDualityStateVectorCompiler`, `UAshenDualityShaderShiftComponent`, `UAshenDualityEngineShaderModulator`, `UAshenDualityMaterialInstanceAdapterComponent`, `UAshenDualityPostProcessVolumeAdapter`, `AAshenDualityTransformationLocusActor` | `FAshenMasterEndToEndIntegrationAutomationTest` (Asserts live `CompiledDualityStateScalar`, `CurrentDualityBlendRatio`, material parameters) | **COMPLETED & VERIFIED** (Commit `1b510b2`) |
| **Priority 2: Living Oaths & Oath Burn** | `Combat/`, `Soul/`, `Core/` | `UAshenOath_OathRegistryComponent`, `UAshenLivingOathSubsystem`, `UAshenOathBurnCostEvaluator`, `UAshenOathBurdenStateEnforcer` | `FAshenLivingOathIntegrationTest` (Asserts Flow/Ember spend transitions, Oath breach penalties) | **IN QUEUE (Next)** |
| **Priority 3: Sanctuary & Companion Trio** | `Companions/`, `World/`, `UI/` | `UAshenCompanionFatigueSubsystem`, `UAshenTrioPartySpawnerComponent`, `UAshenSanctuarySurvivalConvergenceSubsystem`, `UAshenCampfireRestSubsystem` | `FAshenCompanionTrioFatigueIntegrationTest` (Asserts fatigue decay, tactical assists, campfire rest reset) | **PENDING** |
| **Priority 4: Scaffolding Deprecation** | `Tooling/`, `Orchestration/` | Deprecate 129 hardcoded `SynthesisOrchestrator` `return true;` tautologies in favor of deep value-asserting QA test suites | `run_all_checks.py` & UBT 5.8 Clean Suite | **PENDING** |

---

## 🔬 Milestone Detail Log

### ✅ Priority 1: Duality Transformation Pipeline (100% Complete — Commit `1b510b2`)
1. **Authoritative Source of Truth:** `UAshenDualityStateVectorCompiler` instantiated on `AAshenCombatCharacter` and compiled via `CompileDualityStateVector(TargetCorruption)`.
2. **5-Way World Adapter Fan-Out:**
   - `UAshenDualityShaderShiftComponent::SetDualityBlendRatio()`
   - `UAshenDualityEngineShaderModulator::UpdateDualityShaderParameters()`
   - `UAshenDualityMaterialInstanceAdapterComponent::UpdateMaterialInstanceParameters()`
   - `UAshenDualityPostProcessVolumeAdapter::AdjustPostProcessForRealmShift()`
   - `AAshenDualityTransformationLocusActor::TriggerDualityTransformationAuraPulse()`
3. **Dynamic Material Modulation:** Pushes `CorruptionAmount`, `ArmorSootR`, `SeamGrimeG`, `TabardRaggednessB`, `EyeBladeEmissiveA`, and `DualityBlendRatio` across skeletal mesh materials in real-time.
4. **Automation Suite:** Verified via [`FAshenMasterEndToEndIntegrationAutomationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenMasterEndToEndIntegrationAutomationTest.cpp).
