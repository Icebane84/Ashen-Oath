# COOKING-SPEC-087: THE SOUL-EMBER CAMPFIRE COOKING & ALCHEMICAL RATIONING SYSTEM

**Canonical Document Identifier:** `COOKING-SPEC-087`  
**Master Batch:** #146 (Builds 2916–2935)  
**Total Production Builds:** 2,935 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / MetaSounds / DualSense Haptics  
**Architecture Domain:** World / Combat / AI / Audio / UI / Core / Orchestration / Narrative / QA  
**Authority Level:** Canonical Campfire Cooking, Field Alchemy & Alchemical Rationing Specification  
**V-Control:** 2026-08-26T13:15:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`COOKING-SPEC-087` implements the comprehensive **Soul-Ember Campfire Cooking & Alchemical Rationing System**, field cauldron boiling dynamics, companion morale buff scaling, and preservation mechanics:

1. **Campfire Cauldron Boiling Dynamics & Stirring Rhythm**:
   * Simmering cauldron with dynamic boiling temperature curves ($60^\circ\text{C} \leftrightarrow 110^\circ\text{C}$).
   * Stirring rhythm gameplay mechanics accelerating cooking progression by up to $+50\%$ with visual simmering steam VFX.
   * Cauldron portion yield: 3 full companion servings per prepared pot.

2. **Campfire Stew Recipes & 10-Minute Morale Buffs**:
   * **Sentinel's Iron Broth** (Garrett's recipe): $+25\%$ physical posture/poise resistance, $+150$ max stamina.
   * **White Flame Herbal Tisane** (Serafina's recipe): $-30\%$ empathic burnout accumulation rate ($0.70\times$).
   * **Gloomwood Venison Stew** (Kaelen's recipe): $+20\%$ kinetic cleave damage multiplier ($1.20\times$) and freezes soul debt.
   * **Grand Zenith Soul-Ember Goulash** (Tripartite recipe): Full party sanity restoration, $+25\%$ to all combat attributes.

3. **Alchemical Rationing & Spoilage Preservation**:
   * Ration freshness degradation over travel distance ($1.0\%$ per $100\text{m}$).
   * **Garrett's Ember-Salt Preservation**: Field alchemy curing triples shelf-life ($3.0\times$), reducing decay rate.
   * Kaelen's field-dressing yield bonus: $+20\%$ meat harvest yield from Gloomwood wildlife.

4. **Audio & DualSense Campfire Sensation Haptics**:
   * MetaSounds stew bubbling loop audio, stirring ladle clicks, and soul-ember fire crackles ($80\text{Hz}-8000\text{Hz}$).
   * DualSense $25\text{Hz}$ low-frequency warm hearth vibration, progressive stirring viscosity resistance ($0.10 \leftrightarrow 0.45$), and meal served chime pulse ($1.0$).

---

## 📦 2. Master Batch #146 Production Manifest (Builds 2916–2935)

### Phase 1: Data Contracts, Core Solvers & Subsystems (Builds 2916–2920)
* **Build 2916 (`AshenCampfireCookingTypes.h`)**: Enums (`ECampfireRecipeType`, `EIngredientQualityTier`, `ECookingPotState`), Structs (`FCampfireStewStateVector`, `FIngredientRationEntry`), Multicast Delegates (4).
* **Build 2917 (`UAshenCampfireCookingSubsystem`)**: Central world subsystem managing campfire cooking pot, active recipes, and meal distribution.
* **Build 2918 (`UAshenMoraleBuffEvaluator`)**: Evaluator computing recipe morale stat buffs ($+25\%$ poise, $-30\%$ burnout, $+20\%$ damage).
* **Build 2919 (`UAshenRationSpoilageEvaluator`)**: Evaluator calculating ration freshness ($100\% \to 0\%$) and ember-salt preservation multiplier ($3.0\times$).
* **Build 2920 (`UAshenAlchemicalRationingDirectorComponent`)**: Component coordinating ingredient mixing, pot stirring rhythm, and companion portion allocation.

### Phase 2: Gameplay Ability System (GAS) & Combat Actuators (Builds 2921–2925)
* **Build 2921 (`UAshenConsumeCampfireMealGASAbility`)**: Ability consuming cooked meal and granting 10-minute party morale buff.
* **Build 2922 (`UAshenGarrettEmberSaltPreserveGASAbility`)**: Garrett ability applying alchemical salts to triple ration shelf-life.
* **Build 2923 (`UAshenSerafinaTisaneBrewGASAbility`)**: Serafina ability brewing White Lilac Tisane reducing burnout accumulation by $-30\%$.
* **Build 2924 (`UAshenKaelenVenisonCarveGASAbility`)**: Kaelen ability harvesting seasoned gloomwood game with $+20\%$ yield.
* **Build 2925 (`UAshenTripartiteFeastBuffGASAbility`)**: Trio synergy feast ability granting apotheosis morale resonance across all companions.

### Phase 3: AI Behavior Trees, Audio & HUD (Builds 2926–2930)
* **Build 2926 (`UBTService_AshenCompanionCampfireSocialAI`)**: AI service driving companion campfire seating, eating animations, and marginalia commentary.
* **Build 2927 (`UAshenUserWidget_CampfireCookingHUD`)**: UMG widget displaying cooking pot temperature gauge, ingredient inventory, and recipe card preview.
* **Build 2928 (`UAshenCampfireAudioSubsystem`)**: MetaSounds subsystem synthesizing bubbling pot boiling, fire ember crackles, and ladle clinks.
* **Build 2929 (`UAshenCookingPotSimmerPostProcessAdapter`)**: Post-process adapter driving heat haze, warm cauldron amber bloom, and steam vignetting.
* **Build 2930 (`AAshenCampfireCookingPotWorldActor`)**: Spatial world actor with tripod cooking pot, steam particle emitter, and interactive ladle socket.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2931–2935)
* **Build 2931 (`UAshenCampfireCookingSaveGameAdapter`)**: Serializes unlocked recipes, active meal buffs, and ration inventory across game saves.
* **Build 2932 (`UAshenCampfireCookingDialogueBridge`)**: Companion meal commentary and campfire memory discussions triggered during cooking.
* **Build 2933 (`UAshenCampfireCookingHapticBridge`)**: Maps DualSense warm ember crackle rumbles ($25\text{Hz}$) and pot stirring ladle resistance.
* **Build 2934 (`UAshenCampfireCookingMasterBridge`)**: Master orchestrator connecting cooking subsystem, GAS meal buffs, UMG recipe UI, and companion audio.
* **Build 2935 (`FAshenMasterBatch146AutomationTest`)**: QA test suite validating recipe temperature dynamics, morale buff values, ration spoilage decay, and SaveGame persistence.

---

## 🧪 3. Value-Asserting Verification Matrix

The test suite `AshenOath.World.MasterBatch146_SoulEmberCampfireCookingAlchemicalRationing` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Sentinel Broth Poise Bonus** | Sentinel's Iron Broth | Poise Bonus $= 1.25\times$ ($+25\%$), Stamina $= +150$ | **PASSED** |
| **Tisane Burnout Mitigation** | White Flame Herbal Tisane | Burnout Multiplier $= 0.70\times$ ($-30\%$) | **PASSED** |
| **Venison Damage Multiplier** | Gloomwood Venison Stew | Damage Bonus $= 1.20\times$ ($+20\%$) | **PASSED** |
| **Grand Zenith Goulash Bonus** | Grand Zenith Soul Goulash | Poise $= 1.25\times$, Damage $= 1.25\times$ | **PASSED** |
| **Common Ration Spoilage** | $500\text{m}$ Travel Distance | Freshness $= 95.0\%$ | **PASSED** |
| **Ember-Salt Preservation** | $600\text{m}$ Travel Distance | Freshness $= 98.0\%$ ($3.0\times$ shelf-life) | **PASSED** |
| **Ingredient Validation** | Sentinel Broth & Tisane | Valid recipes Pass, invalid ingredients Fail | **PASSED** |
| **DualSense Stirring Haptics** | Active Stirring & Served | Stirring Res $= 0.45$, Chime $= 1.0$ | **PASSED** |
| **SaveGame Roundtrip** | Broth buff, $450\text{s}$ time, $6$ rations | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 4. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,915 Builds (`CHAOS-SPEC-086`)
* **Current Milestone**: **2,935 Builds (`COOKING-SPEC-087`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
