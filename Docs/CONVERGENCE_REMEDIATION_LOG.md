# Ashen Oath — Causal Convergence & Mechanics Wiring Remediation Log

**Governing Directives:**
* Sentinel Audit: [`Ashen_Oath_Theater_Pattern_Audit.md`](file:///C:/Users/Chris/Where%20Light%20Fades/Ashen%20Oath/Design%20and%20Technical/Ashen_Oath_Theater_Pattern_Audit.md)
* Remediation Guide: [`Ashen_Oath_Wiring_Remediation_Guide.md`](file:///C:/Users/Chris/Where%20Light%20Fades/Ashen%20Oath/Design%20and%20Technical/Ashen_Oath_Wiring_Remediation_Guide.md)
* **6-Step Causal Wiring Law & Anti-Theater Rule** embedded directly into `SKILL.md`
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
   [100% COMPLETE]         [100% COMPLETE]      [100% COMPLETE]     [READY TO TRIAGE]
```

| Priority Layer | Target Domain | Key Components & Subsystems | Verification Suite | Status |
| :--- | :--- | :--- | :--- | :--- |
| **Priority 1: Duality Pipeline** | `Soul/`, `World/`, `Combat/` | `UAshenSovereignDualityTransformationAbility`, `UAshenDualityStateVectorCompiler`, `UAshenDualityShaderShiftComponent`, `UAshenDualityEngineShaderModulator`, `UAshenDualityMaterialInstanceAdapterComponent`, `UAshenDualityPostProcessVolumeAdapter`, `AAshenDualityTransformationLocusActor` | `FAshenMasterEndToEndIntegrationAutomationTest` (Asserts live `CompiledDualityStateScalar`, `CurrentDualityBlendRatio`, material parameters) | **COMPLETED & VERIFIED** (Commit `1b510b2`) |
| **Priority 2: Living Oaths & Oath Burn** | `Combat/`, `Soul/`, `Core/` | `UAshenOath_OathRegistryComponent`, `UAshenLivingOathRegistrySubsystem`, `UAshenLivingOathGASAbility`, `UAshenOathBurnStaminaDrainGASAbility` | `FAshenLivingOathIntegrationTest` (Asserts swearing oaths, burden accumulation, burn state activation, fulfillment/breach) | **COMPLETED & VERIFIED** (Commit `1544729`) |
| **Priority 3: Sanctuary & Companion Trio** | `Companions/`, `World/`, `UI/` | `UAshenCompanionFatigueSubsystem`, `UAshenTrioPartySpawnerComponent`, `UAshenSanctuarySurvivalConvergenceSubsystem`, `UAshenCampfireRestSubsystem` | `FAshenCompanionTrioFatigueIntegrationTest` (Asserts fatigue decay, tactical assists, campfire rest reset) | **COMPLETED & VERIFIED** (Commit `eacf843`) |
| **Priority 4: Scaffolding Triage & Purge** | `Tooling/`, `Orchestration/` | Triage the 129 `SynthesisOrchestrator` classes and 0%-wired legacy pillars; keep core spine lean and 100% causal | `run_all_checks.py` & UBT 5.8 Clean Suite | **IN QUEUE (Next)** |

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

### ✅ Priority 2: Living Oaths & Oath Burn Pipeline (100% Complete — Commit `1544729`)
1. **Authoritative Source of Truth:** `UAshenOath_OathRegistryComponent` on `AAshenCombatCharacter` and `UAshenLivingOathRegistrySubsystem` in `World`.
2. **Material & Mesh Hooking:** Listens to `OnOathSworn`, `OnOathFulfilled`, `OnOathBroken` to drive dynamic material parameters:
   - `OathBurdenAmount` ($0.0 \to 1.0$)
   - `OathBurnActive` ($1.0$ if burden $\ge 1.0$ or on breach)
   - `OathResonanceGlow` ($1.0$ on fulfillment, $0.0$ on breach)
3. **GAS Execution Payloads:**
   - [`UAshenLivingOathGASAbility`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Combat/AshenLivingOathGASAbility.cpp): Unleashes radial resonance damage scaled by Kaelen's current `ActiveOathBurden`.
   - [`UAshenOathBurnStaminaDrainGASAbility`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Combat/AshenOathBurnStaminaDrainGASAbility.cpp): Drains $-15.0\text{ Stamina}$ and drives glowing crack shaders when burden exceeds threshold.
4. **Automation Suite:** Verified via [`FAshenLivingOathIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenLivingOathIntegrationTest.cpp).

### ✅ Priority 3: Sanctuary & Companion Trio Fatigue Loop (100% Complete — Commit `eacf843`)
1. **Authoritative Fatigue Subsystem:** `UAshenCompanionFatigueSubsystem` managing Tripartite Fatigue (Garrett Control via Twin-Blade X-Lock & Alchemical Flasks, Serafina Poise via Healing Prayers, Kaelen Transference).
2. **Sanctuary / Campfire Rest Integration:** Added `ResetAllFatigue()` to purge companion fatigue upon resting at campfire havens or consuming hot meals.
3. **Vulnerability State Enforcement:** Enforces vulnerability threshold ($\ge 0.70\text{ Fatigue}$) increasing assist cooldowns and lowering defense.
4. **Automation Suite:** Verified via [`FAshenCompanionTrioFatigueIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenCompanionTrioFatigueIntegrationTest.cpp).
