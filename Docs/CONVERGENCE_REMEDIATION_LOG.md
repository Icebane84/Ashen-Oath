# Ashen Oath — Causal Convergence & Mechanics Wiring Remediation Log

**Governing Directives:**
* Sentinel Audit: [`Ashen_Oath_Theater_Pattern_Audit.md`](file:///C:/Where%20Light%20Fades/Ashen%20Oath/Design%20and%20Technical/Ashen_Oath_Theater_Pattern_Audit.md)
* Remediation Guide: [`Ashen_Oath_Wiring_Remediation_Guide.md`](file:///C:/Where%20Light%20Fades/Ashen%20Oath/Design%20and%20Technical/Ashen_Oath_Wiring_Remediation_Guide.md)
* **6-Step Causal Wiring Law & Anti-Theater Rule** embedded directly into `SKILL.md`
* Zero Entropy & Value-Asserting Test Mandate (AES $\ge 8$)

---

## 📊 Remediation Roadmap Status

```
┌─────────────────────────────────────────────────────────────────────────────────────────────┐
│                            CONVERGENCE & REMEDIATION PROGRESS MATRIX                        │
└─────────────────────────────────────────────────────────────────────────────────────────────┘
                                               │
       ┌───────────────────┬───────────────────┼───────────────────┬───────────────────┐
       ▼                   ▼                   ▼                   ▼                   ▼
[ PRIORITY 1: DUALITY ] [ PRIORITY 2: OATHS ] [ PRIORITY 3: TRIO ] [ PRIORITY 4: BARGAIN ] [ CORE PILLARS ]
   ✅ 100% COMPLETE        ✅ 100% COMPLETE     ✅ 100% COMPLETE      ✅ 100% COMPLETE     ✅ 100% COMPLETE
   (Commit 1b510b2)        (Commit 1544729)     (Commit 1dd64e5)      (Commit 7edd69a)     (Commit 101812d)
```

| System Layer | Integration Point | Functional Output | Verification Suite | Status |
| :--- | :--- | :--- | :--- | :--- |
| **Focus Mode Sensory Dilation** | `UAshenFocusModeInvestigationComponent::ToggleFocusMode` | Scales global time dilation to $0.35\times$, drains $4.0\text{ Sanity/s}$, auto-collapses on sanity exhaustion, modulates cyan pulse | `FAshenFocusAndMartyrTitheConvergenceIntegrationTest` | **VERIFIED (0 Errors)** |
| **Martyr's Tithe Sacrifice** | `UAshenMartyrsTitheComponent::PerformMartyrSacrifice` | Permanently reduces Max Health ($\ge 50\text{ HP}$ clamp), awards $+25\%$ party combat buff per $100\text{ HP}$, restores $+15\%$ Companion Trust | `FAshenFocusAndMartyrTitheConvergenceIntegrationTest` | **VERIFIED (0 Errors)** |
| **White Flame Resolution** | `UAshenInvokeWhiteFlameGASAbility::InvokeWhiteFlame` | Checks Resolve $\ge 0.90$ & Burnout $\ge 0.65$; eradicates $100\%$ Integration Debt, relieves $50\%$ Serafina Burnout, heals $+50.0\text{ Sanity}$, and activates White Pyre emissives for $12.0\text{s}$ | `FAshenWhiteFlameConvergenceIntegrationTest` | **VERIFIED (0 Errors)** |
| **Memory Palace Anchor & Duel** | `AAshenMemoryPalaceNodeAnchorActor::InteractWithAnchor` | Interacting unseals Dormant nodes immediately ($+10\text{ Sanity}$) or initiates in-situ Memory Battle for Traumatic nodes | `FAshenMemoryPalaceConvergenceIntegrationTest` | **VERIFIED (0 Errors)** |
| **Memory Battle Catharsis** | `UAshenMemoryBattleSubsystem::ConcludeMemoryBattle(true)` | Unseals target node in `UAshenMemoryPalaceGraphSubsystem`, heals $+25.0\text{ Sanity}$, and restores $+5.0\%$ companion trust | `FAshenMemoryPalaceConvergenceIntegrationTest` | **VERIFIED (0 Errors)** |
| **Memory Defeat & Debt** | `UAshenMemoryBattleSubsystem::ConcludeMemoryBattle(false)` | Node remains sealed/fractured, inflicts $-30.0\text{ Sanity}$ mental damage, and adds $+20\%$ Integration Debt pressure | `FAshenMemoryPalaceConvergenceIntegrationTest` | **VERIFIED (0 Errors)** |
| **Duality Phase 2 Pulse** | HP threshold (50%) on Boss ASC / Player | Interpolates `UAshenDualityShaderShiftComponent` blend scalar to `1.0f` and grants transition immunity | `FAshenCoreCombatSynergyIntegrationTest` & `FAshenMasterEndToEndIntegrationAutomationTest` | **VERIFIED (0 Errors)** |
| **Sacred Sanctuary Field** | Dynamic spawn via `UAshenSerafinaSacredBarrierGASAbility` | `AAshenSanctuaryField` overlap applies `+250%` stamina acceleration ($3.5\times$) and AoE damage nullification; adds $+0.20$ Serafina fatigue | `FAshenCoreCombatSynergyIntegrationTest` | **VERIFIED (0 Errors)** |
| **Garrett Flank Assist** | Assist input tag (`E`) | Motion-warps to target rear transform; deals $1.8\times$ stagger multiplier against `State.Combat.Recovery`; adds $+0.25$ Garrett fatigue | `FAshenCoreCombatSynergyIntegrationTest` | **VERIFIED (0 Errors)** |
| **Oathbringer Riposte** | Contextual trigger during `State.Combat.Staggered` | Synchronizes transforms to front socket ($120\text{uu}$), triggers trauma shake, deals $450\text{ damage}$, and resets posture | `FAshenCoreCombatSynergyIntegrationTest` | **VERIFIED (0 Errors)** |
| **Living Oaths & Burn** | `UAshenOath_OathRegistryComponent` & `UAshenLivingOathRegistrySubsystem` | Tracks swearing, burden scaling, Oath Burn stamina drain debuff ($-15.0\text{ stamina/s}$), fulfillment & breach | `FAshenLivingOathIntegrationTest` | **VERIFIED (0 Errors)** |
| **Devil's Bargain Crisis** | HP $\le 25\%$ crisis window on `AAshenCombatCharacter` | $0.1\times$ slow motion, $+200\%$ attack speed surge ($3.0\times$), $-25\%$ companion trust atrophy penalty | `FAshenDevilsBargainIntegrationTest` | **VERIFIED (0 Errors)** |
| **Data-Driven Stance Tuning** | `UAshenMartialStanceBalanceDataAsset` & `UAshenOathbringerStanceFlowConvergenceSubsystem` | Live editor sliders for Vom Tag, Pflug, Ochs, Mordhau with boundary safety clamps | `FAshenMasterEndToEndIntegrationAutomationTest` | **VERIFIED (0 Errors)** |

---

## 🔬 Master Value-Asserting Automation Test Suites

1. [`FAshenFocusAndMartyrTitheConvergenceIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenFocusAndMartyrTitheConvergenceIntegrationTest.cpp) — Asserts Focus Mode $0.35\times$ dilation, $4.0\text{ Sanity/s}$ drain, auto-collapse on exhaustion, permanent $-100\text{ Max HP}$ Martyr Tithe sacrifice, $+25\%$ companion buff multiplier ($1.25\times$), and $+15\%$ trust restoration ($70\% \to 85\%$).
2. [`FAshenWhiteFlameConvergenceIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenWhiteFlameConvergenceIntegrationTest.cpp) — Asserts priming condition checks ($R \ge 0.90, B \ge 0.65$), $100\%$ debt eradication ($0.85 \to 0.00$), $50\%$ Serafina burnout relief ($0.80 \to 0.40$), $+50.0\text{ Sanity}$ healing ($40.0 \to 90.0$), and $12.0\text{s}$ active duration.
3. [`FAshenMemoryPalaceConvergenceIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenMemoryPalaceConvergenceIntegrationTest.cpp) — Asserts Dormant anchor instant unsealing ($+10\text{ Sanity}$), Traumatic memory battle victory (node unseal, $+25\text{ Sanity}$, $+5\%$ Trust), and battle defeat ($-30\text{ Sanity}$, $+20\%$ Integration Debt).
4. [`FAshenCoreCombatSynergyIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenCoreCombatSynergyIntegrationTest.cpp) — Asserts Duality Phase 2 interpolation, Sanctuary Field $+250\%$ stamina acceleration, Garrett Flank motion-warp & $1.8\times$ stagger, and Oathbringer Riposte paired execution & posture reset.
5. [`FAshenMasterEndToEndIntegrationAutomationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenMasterEndToEndIntegrationAutomationTest.cpp) — Asserts Duality Transformation Ability, Soul State Vector compilation, World Shader Shift blend scalar, and live DataAsset Stance Tuning.
6. [`FAshenLivingOathIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenLivingOathIntegrationTest.cpp) — Asserts Swearing Oaths ($0.10 \to 1.00$ burden), automatic Oath Burn debuff activation, stamina drain, and fulfillment/breach tracking.
7. [`FAshenCompanionTrioFatigueIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenCompanionTrioFatigueIntegrationTest.cpp) — Asserts Garrett Twin-Blade X-Lock and Serafina Prayer fatigue accumulation, vulnerability threshold ($\ge 0.70$), dynamic decay, and Campfire rest purge to `0.0`.
8. [`FAshenDevilsBargainIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenDevilsBargainIntegrationTest.cpp) — Asserts critical HP crisis dilation, $+200\%$ attack speed surge, and $-25\%$ companion trust penalty.
9. [`FAshenCombatHitSootAlchemicalIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenCombatHitSootAlchemicalIntegrationTest.cpp) — Asserts melee hit soot accumulation ($0.04/0.08$), Superheated Slag transition, alchemical coatings, and Thermal Shock poise shatter.
