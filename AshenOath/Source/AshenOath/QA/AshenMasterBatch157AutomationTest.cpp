// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "Combat/AshenRunicForgeConvergenceSubsystem.h"
#include "Combat/AshenSigilResonanceEvaluator.h"
#include "Combat/AshenBladeAscensionEvaluator.h"
#include "Combat/AshenRunicSeamGlyphDirectorComponent.h"
#include "Combat/AshenRunicForgeHapticBridge.h"
#include "Core/AshenRunicForgeSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch157AutomationTest,
	"AshenOath.Combat.MasterBatch157_RunicForgeConvergence",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch157AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST SIGIL RESONANCE EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenSigilResonanceEvaluator* ResonanceEvaluator = NewObject<UAshenSigilResonanceEvaluator>();

		// Shattered Colossus + Zephyr Gale -> 1.40x Hybrid Damage
		TestTrue(TEXT("Colossus + Zephyr triggers resonance"), ResonanceEvaluator->CanTriggerResonance(ESigilResonanceEffect::ShatteredColossus, ESigilResonanceEffect::ZephyrGale));
		TestNearlyEqual(TEXT("Hybrid finisher damage is 1.40x"), ResonanceEvaluator->EvaluateHybridFinisherDamage(ESigilResonanceEffect::ShatteredColossus, ESigilResonanceEffect::ZephyrGale), 1.40f, 0.01f);

		// None + Colossus -> No resonance
		TestFalse(TEXT("None + Colossus does not trigger resonance"), ResonanceEvaluator->CanTriggerResonance(ESigilResonanceEffect::None, ESigilResonanceEffect::ShatteredColossus));
		TestNearlyEqual(TEXT("Unconnected damage is 1.0x"), ResonanceEvaluator->EvaluateHybridFinisherDamage(ESigilResonanceEffect::None, ESigilResonanceEffect::ShatteredColossus), 1.00f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST BLADE ASCENSION EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenBladeAscensionEvaluator* AscensionEvaluator = NewObject<UAshenBladeAscensionEvaluator>();

		// Tier 1 -> Tier 2 requires 1 boss + 1 hearthstone
		TestTrue(TEXT("1 Boss + 1 Hearthstone eligible for Tier 2"), AscensionEvaluator->IsEligibleForAscension(EOathbringerAscensionTier::Tier1_DullNightsteel, 1, 1, 0));
		TestFalse(TEXT("0 Bosses not eligible for Tier 2"), AscensionEvaluator->IsEligibleForAscension(EOathbringerAscensionTier::Tier1_DullNightsteel, 0, 1, 0));

		// Tier 2 -> Tier 3 requires 2 bosses + 3 hearthstones + 1 forensic case
		TestTrue(TEXT("2 Bosses + 3 Hearthstones + 1 Case eligible for Tier 3"), AscensionEvaluator->IsEligibleForAscension(EOathbringerAscensionTier::Tier2_AwakenedFuller, 2, 3, 1));
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST RUNIC SEAM GLYPH DIRECTOR
	// -----------------------------------------------------------------------------------
	{
		UAshenRunicSeamGlyphDirectorComponent* GlyphDirector = NewObject<UAshenRunicSeamGlyphDirectorComponent>();

		const FLinearColor VomTagColor = GlyphDirector->EvaluateGlyphColor(ESigilResonanceEffect::ShatteredColossus);
		TestNearlyEqual(TEXT("Vom Tag glyph R is 0.95"), VomTagColor.R, 0.95f, 0.01f);

		const FLinearColor OchsColor = GlyphDirector->EvaluateGlyphColor(ESigilResonanceEffect::SunkenSun);
		TestNearlyEqual(TEXT("Ochs glyph R is 1.0"), OchsColor.R, 1.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE FORGE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenRunicForgeHapticBridge* HapticBridge = NewObject<UAshenRunicForgeHapticBridge>();
		float HeavyGain = 0.0f;
		float LightGain = 0.0f;

		// Anvil Strike: 0.85 heavy, 0.40 light
		HapticBridge->EvaluateForgeHaptics(true, false, HeavyGain, LightGain);
		TestNearlyEqual(TEXT("Anvil heavy strike gain is 0.85"), HeavyGain, 0.85f, 0.01f);
		TestNearlyEqual(TEXT("Anvil light strike gain is 0.40"), LightGain, 0.40f, 0.01f);

		// Flow Resonance Finisher: 0.95 heavy, 0.90 light
		HapticBridge->EvaluateForgeHaptics(false, true, HeavyGain, LightGain);
		TestNearlyEqual(TEXT("Resonance heavy gain is 0.95"), HeavyGain, 0.95f, 0.01f);
		TestNearlyEqual(TEXT("Resonance light gain is 0.90"), LightGain, 0.90f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenRunicForgeSaveGameAdapter* SaveAdapter = NewObject<UAshenRunicForgeSaveGameAdapter>();
		SaveAdapter->PackageForgeState(EOathbringerAscensionTier::Tier3_SunderedSovereign, ESigilResonanceEffect::ShatteredColossus, ESigilResonanceEffect::ZephyrGale);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		EOathbringerAscensionTier RestoredTier = EOathbringerAscensionTier::Tier1_DullNightsteel;
		ESigilResonanceEffect RestoredVomTag = ESigilResonanceEffect::None;
		ESigilResonanceEffect RestoredPflug = ESigilResonanceEffect::None;

		const bool bSuccess = SaveAdapter->RestoreForgeState(RestoredTier, RestoredVomTag, RestoredPflug);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("Restored tier is Tier 3"), RestoredTier == EOathbringerAscensionTier::Tier3_SunderedSovereign);
		TestTrue(TEXT("Restored Vom Tag is Shattered Colossus"), RestoredVomTag == ESigilResonanceEffect::ShatteredColossus);
		TestTrue(TEXT("Restored Pflug is Zephyr Gale"), RestoredPflug == ESigilResonanceEffect::ZephyrGale);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
