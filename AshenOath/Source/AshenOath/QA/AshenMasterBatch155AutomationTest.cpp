// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "World/AshenSanctuarySurvivalConvergenceSubsystem.h"
#include "World/AshenMealHazardImmunityEvaluator.h"
#include "World/AshenShelterThermodynamicsEvaluator.h"
#include "World/AshenSanctuaryBeaconJournalRegistrarComponent.h"
#include "Combat/AshenSanctuarySurvivalHapticBridge.h"
#include "Core/AshenSanctuarySurvivalSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch155AutomationTest,
	"AshenOath.World.MasterBatch155_SanctuarySurvivalConvergence",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch155AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST MEAL HAZARD IMMUNITY EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenMealHazardImmunityEvaluator* MealEvaluator = NewObject<UAshenMealHazardImmunityEvaluator>();

		// Glacial Heart Stew: 100% Blizzard Immunity
		TestTrue(TEXT("Glacial Stew grants Blizzard immunity"), MealEvaluator->IsImmuneToHazard(ECookedMealBuffType::GlacialHeartStew, true, false, false));
		TestNearlyEqual(TEXT("Glacial Stew damage reduction is 100%"), MealEvaluator->EvaluateHazardDamageReduction(ECookedMealBuffType::GlacialHeartStew, true, false, false), 1.00f, 0.01f);

		// Vitriol Purge Broth: 100% Acid Rain Immunity
		TestTrue(TEXT("Vitriol Broth grants Acid Rain immunity"), MealEvaluator->IsImmuneToHazard(ECookedMealBuffType::VitriolPurgeBroth, false, true, false));

		// Cinder Ash Cake: 100% Ash Storm Immunity
		TestTrue(TEXT("Cinder Ash Cake grants Ash Storm immunity"), MealEvaluator->IsImmuneToHazard(ECookedMealBuffType::CinderAshCake, false, false, true));

		// Unmatched meal: 0% reduction
		TestFalse(TEXT("Glacial Stew does not grant Acid Rain immunity"), MealEvaluator->IsImmuneToHazard(ECookedMealBuffType::GlacialHeartStew, false, true, false));
		TestNearlyEqual(TEXT("Unmatched meal damage reduction is 0%"), MealEvaluator->EvaluateHazardDamageReduction(ECookedMealBuffType::GlacialHeartStew, false, true, false), 0.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST SHELTER THERMODYNAMICS EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenShelterThermodynamicsEvaluator* ShelterEvaluator = NewObject<UAshenShelterThermodynamicsEvaluator>();

		// Open wilderness: -2.5 HP/s in blizzard, 1.0x cooking
		TestNearlyEqual(TEXT("Wilderness blizzard HP loss is -2.5"), ShelterEvaluator->EvaluateHypothermiaHPLoss(EThermalShelterTier::OpenWilderness, true), -2.50f, 0.01f);
		TestNearlyEqual(TEXT("Wilderness cooking speed is 1.0x"), ShelterEvaluator->EvaluateCookingSpeedMultiplier(EThermalShelterTier::OpenWilderness), 1.00f, 0.01f);

		// Cavern: 0.0 HP loss, 2.0x cooking
		TestNearlyEqual(TEXT("Cavern blizzard HP loss is 0.0"), ShelterEvaluator->EvaluateHypothermiaHPLoss(EThermalShelterTier::NaturalCavern, true), 0.0f, 0.01f);
		TestNearlyEqual(TEXT("Cavern cooking speed is 2.0x"), ShelterEvaluator->EvaluateCookingSpeedMultiplier(EThermalShelterTier::NaturalCavern), 2.00f, 0.01f);

		// Sanctuary Hearth: 0.0 sanity decay
		TestNearlyEqual(TEXT("Sanctuary sanity decay scale is 0.0"), ShelterEvaluator->EvaluateSanityDecayScale(EThermalShelterTier::SanctuaryHearthRadius), 0.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SANCTUARY BEACON JOURNAL REGISTRAR
	// -----------------------------------------------------------------------------------
	{
		UAshenSanctuaryBeaconJournalRegistrarComponent* JournalRegistrar = NewObject<UAshenSanctuaryBeaconJournalRegistrarComponent>();
		const FText Entry = JournalRegistrar->FormatBeaconJournalEntry(TEXT("Beacon_Gloomwood_01"), TEXT("Gloomwood Spires"));

		JournalRegistrar->RecordEntry(Entry);
		TestEqual(TEXT("Journal entries count is 1"), JournalRegistrar->GetRecordedJournalCount(), 1);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE SURVIVAL HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenSanctuarySurvivalHapticBridge* HapticBridge = NewObject<UAshenSanctuarySurvivalHapticBridge>();
		float HeavyGain = 0.0f;
		float LightGain = 0.0f;

		// Hypothermia (<35.0C): Shivering 0.85 light jitter
		HapticBridge->EvaluateSurvivalHaptics(EThermalShelterTier::OpenWilderness, 32.0f, HeavyGain, LightGain);
		TestNearlyEqual(TEXT("Hypothermia light shivering gain is 0.85"), LightGain, 0.85f, 0.01f);

		// Sanctuary Hearth: Gentle 0.40 warm pulse
		HapticBridge->EvaluateSurvivalHaptics(EThermalShelterTier::SanctuaryHearthRadius, 37.0f, HeavyGain, LightGain);
		TestNearlyEqual(TEXT("Sanctuary warm hearth gain is 0.40"), LightGain, 0.40f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenSanctuarySurvivalSaveGameAdapter* SaveAdapter = NewObject<UAshenSanctuarySurvivalSaveGameAdapter>();
		SaveAdapter->PackageSurvivalState(ECookedMealBuffType::GlacialHeartStew, 600.0f, 3);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		ECookedMealBuffType RestoredMeal = ECookedMealBuffType::None;
		float RestoredDuration = 0.0f;
		int32 RestoredIgnited = 0;

		const bool bSuccess = SaveAdapter->RestoreSurvivalState(RestoredMeal, RestoredDuration, RestoredIgnited);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("Restored meal is Glacial Stew"), RestoredMeal == ECookedMealBuffType::GlacialHeartStew);
		TestNearlyEqual(TEXT("Restored duration is 600"), RestoredDuration, 600.0f, 0.01f);
		TestEqual(TEXT("Restored ignited beacons is 3"), RestoredIgnited, 3);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
