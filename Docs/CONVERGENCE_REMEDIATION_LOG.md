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
[ PRIORITY 1: DUALITY ] [ PRIORITY 2: OATHS ] [ PRIORITY 3: TRIO ] [ PRIORITY 4: BARGAIN ] [ COMBAT SYNERGY ]
   ✅ 100% COMPLETE        ✅ 100% COMPLETE     ✅ 100% COMPLETE      ✅ 100% COMPLETE     ✅ 100% COMPLETE
   (Commit 1b510b2)        (Commit 1544729)     (Commit 1dd64e5)      (Commit 7edd69a)     (Commit daf6e7d)
```

| System Layer | Integration Point | Functional Output | Verification Suite | Status |
| :--- | :--- | :--- | :--- | :--- |
| **Duality Phase 2 Pulse** | HP threshold (50%) on Boss ASC / Player | Interpolates `UAshenDualityShaderShiftComponent` blend scalar to `1.0f` and grants transition immunity | `FAshenCoreCombatSynergyIntegrationTest` & `FAshenMasterEndToEndIntegrationAutomationTest` | **VERIFIED (0 Errors)** |
| **Sacred Sanctuary Field** | Dynamic spawn via `UAshenSerafinaSacredBarrierGASAbility` | `AAshenSanctuaryField` overlap applies `+250%` stamina acceleration ($3.5\times$) and AoE damage nullification; adds $+0.20$ Serafina fatigue | `FAshenCoreCombatSynergyIntegrationTest` | **VERIFIED (0 Errors)** |
| **Garrett Flank Assist** | Assist input tag (`E`) | Motion-warps to target rear transform; deals $1.8\times$ stagger multiplier against `State.Combat.Recovery`; adds $+0.25$ Garrett fatigue | `FAshenCoreCombatSynergyIntegrationTest` | **VERIFIED (0 Errors)** |
| **Oathbringer Riposte** | Contextual trigger during `State.Combat.Staggered` | Synchronizes transforms to front socket ($120\text{uu}$), triggers trauma shake, deals $450\text{ damage}$, and resets posture | `FAshenCoreCombatSynergyIntegrationTest` | **VERIFIED (0 Errors)** |
| **Living Oaths & Burn** | `UAshenOath_OathRegistryComponent` & `UAshenLivingOathRegistrySubsystem` | Tracks swearing, burden scaling, Oath Burn stamina drain debuff ($-15.0\text{ stamina/s}$), fulfillment & breach | `FAshenLivingOathIntegrationTest` | **VERIFIED (0 Errors)** |
| **Devil's Bargain Crisis** | HP $\le 25\%$ crisis window on `AAshenCombatCharacter` | $0.1\times$ slow motion, $+200\%$ attack speed surge ($3.0\times$), $-25\%$ companion trust atrophy penalty | `FAshenDevilsBargainIntegrationTest` | **VERIFIED (0 Errors)** |

---

## 🔬 Master Value-Asserting Automation Test Suites

1. [`FAshenCoreCombatSynergyIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenCoreCombatSynergyIntegrationTest.cpp) — Asserts all 4 Core Combat Synergy systems: Duality Phase 2 interpolation, Sanctuary Field $+250\%$ stamina acceleration, Garrett Flank motion-warp & $1.8\times$ stagger, and Oathbringer Riposte paired execution & posture reset.
2. [`FAshenMasterEndToEndIntegrationAutomationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenMasterEndToEndIntegrationAutomationTest.cpp) — Asserts Duality Transformation Ability, Soul State Vector compilation, World Shader Shift blend scalar, and Martial Stance flow.
3. [`FAshenLivingOathIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenLivingOathIntegrationTest.cpp) — Asserts Swearing Oaths ($0.10 \to 1.00$ burden), automatic Oath Burn debuff activation, stamina drain, and fulfillment/breach tracking.
4. [`FAshenCompanionTrioFatigueIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenCompanionTrioFatigueIntegrationTest.cpp) — Asserts Garrett Twin-Blade X-Lock and Serafina Prayer fatigue accumulation, vulnerability threshold ($\ge 0.70$), dynamic decay, and Campfire rest purge to `0.0`.
5. [`FAshenDevilsBargainIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenDevilsBargainIntegrationTest.cpp) — Asserts critical HP crisis dilation, $+200\%$ attack speed surge, and $-25\%$ companion trust penalty.
6. [`FAshenCombatHitSootAlchemicalIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenCombatHitSootAlchemicalIntegrationTest.cpp) — Asserts melee hit soot accumulation ($0.04/0.08$), Superheated Slag transition, alchemical coatings, and Thermal Shock poise shatter.
