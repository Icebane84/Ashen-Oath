// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Scenarios/AshenScenario6Types.h"
#include "Scenarios/AshenScenario6MissionSubsystem.h"
#include "Scenarios/AshenBlizzardThermodynamicsEvaluator.h"
#include "Scenarios/AshenCompanionWarmingAuraComponent.h"
#include "Scenarios/AshenHearthBrazierIgnitionEvaluator.h"
#include "Scenarios/AshenScenario6HapticBridge.h"
#include "Core/AshenScenario6SaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch135AutomationTest,
	"AshenOath.Scenarios.MasterBatch135_SanctifiedHearthResolution",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch135AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST BLIZZARD THERMODYNAMICS & SPEED REDUCTION
	// -----------------------------------------------------------------------------------
	{
		UAshenBlizzardThermodynamicsEvaluator* ThermoEvaluator = NewObject<UAshenBlizzardThermodynamicsEvaluator>();

		// Severe Blizzard (-25°C), outside warmth -> Rate ~ 25/600 = 0.0416/s
		const float FrostbiteRate = ThermoEvaluator->EvaluateFrostbiteRatePerSecond(-25.0f, false);
		TestNearlyEqual(TEXT("Severe blizzard frostbite rate is ~0.041/s"), FrostbiteRate, 0.0416f, 0.005f);

		// Inside warmth -> Negative rate (recovery)
		const float RecoveryRate = ThermoEvaluator->EvaluateFrostbiteRatePerSecond(-25.0f, true);
		TestTrue(TEXT("Warmth zone reverses frostbite"), RecoveryRate < 0.0f);

		// 100% Frostbite -> 0.40x speed multiplier
		const float SlowSpeed = ThermoEvaluator->EvaluateMovementSpeedMultiplier(1.0f);
		TestNearlyEqual(TEXT("Max frostbite slows to 0.40x"), SlowSpeed, 0.40f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST COMPANION WARMING AURA PROXIMITY
	// -----------------------------------------------------------------------------------
	{
		UAshenCompanionWarmingAuraComponent* WarmingComp = NewObject<UAshenCompanionWarmingAuraComponent>();
		WarmingComp->WarmingRadiusUU = 350.0f;

		const FVector GarrettLoc(0.0f, 0.0f, 0.0f);
		const FVector KaelenClose(200.0f, 0.0f, 0.0f);
		const FVector KaelenFar(600.0f, 0.0f, 0.0f);

		TestTrue(TEXT("Kaelen within 200uu is warm"), WarmingComp->IsActorWithinWarmthRadius(GarrettLoc, KaelenClose));
		TestFalse(TEXT("Kaelen at 600uu is freezing"), WarmingComp->IsActorWithinWarmthRadius(GarrettLoc, KaelenFar));
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST HEARTH SANCTUARY RADIUS SCALING
	// -----------------------------------------------------------------------------------
	{
		UAshenHearthBrazierIgnitionEvaluator* HearthEvaluator = NewObject<UAshenHearthBrazierIgnitionEvaluator>();

		// 0% ignition -> 500uu radius
		TestNearlyEqual(TEXT("Unlit brazier radius is 500uu"), HearthEvaluator->EvaluateSanctuaryRadiusUU(0.0f), 500.0f, 1.0f);

		// 100% ignition -> 2500uu radius
		TestNearlyEqual(TEXT("Full sanctified brazier radius is 2500uu"), HearthEvaluator->EvaluateSanctuaryRadiusUU(1.0f), 2500.0f, 1.0f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS & SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario6HapticBridge* HapticBridge = NewObject<UAshenScenario6HapticBridge>();
		float LeftShiver = 0.0f;
		float RightWarmth = 0.0f;
		float TriggerResistance = 0.0f;

		// 80% Frostbite, outside warmth, 50% Hearth
		HapticBridge->EvaluateScenario6Haptics(0.80f, 0.50f, false, LeftShiver, RightWarmth, TriggerResistance);
		TestNearlyEqual(TEXT("Frost shiver is active (0.64)"), LeftShiver, 0.64f, 0.02f);
		TestNearlyEqual(TEXT("Hearth warmth is active (0.35)"), RightWarmth, 0.35f, 0.02f);
		TestNearlyEqual(TEXT("Frozen trigger resistance is 0.60"), TriggerResistance, 0.60f, 0.02f);

		// SaveGame Adapter
		UAshenScenario6SaveGameAdapter* SaveAdapter = NewObject<UAshenScenario6SaveGameAdapter>();
		SaveAdapter->PackageScenario6State(1.0f, 0.05f, -35.0f, true);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		float RestoredHearth = 0.0f;
		float RestoredFrostbite = 0.0f;
		float RestoredTemp = 0.0f;
		bool bRestoredComplete = false;
		const bool bSuccess = SaveAdapter->RestoreScenario6State(RestoredHearth, RestoredFrostbite, RestoredTemp, bRestoredComplete);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Restored hearth is 1.0"), RestoredHearth, 1.0f, 0.01f);
		TestNearlyEqual(TEXT("Restored frostbite is 0.05"), RestoredFrostbite, 0.05f, 0.01f);
		TestNearlyEqual(TEXT("Restored lowest temp is -35.0C"), RestoredTemp, -35.0f, 0.1f);
		TestTrue(TEXT("Restored sanctuary complete is true"), bRestoredComplete);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
