// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Scenarios/AshenScenario8Types.h"
#include "Scenarios/AshenScenario8MissionSubsystem.h"
#include "Scenarios/AshenDarknessIlluminationEvaluator.h"
#include "Scenarios/AshenAcousticEcholocationEvaluator.h"
#include "Scenarios/AshenTorchEnduranceComponent.h"
#include "Scenarios/AshenScenario8HapticBridge.h"
#include "Core/AshenScenario8SaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch138AutomationTest,
	"AshenOath.Scenarios.MasterBatch138_SearingAbyssSubterraneanCatacombs",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch138AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST ILLUMINATION RADIUS & DARKNESS PENALTIES
	// -----------------------------------------------------------------------------------
	{
		UAshenDarknessIlluminationEvaluator* Evaluator = NewObject<UAshenDarknessIlluminationEvaluator>();

		// 100% fuel -> 800uu
		TestNearlyEqual(TEXT("100% fuel light radius is 800uu"), Evaluator->EvaluateLightRadius(1.0f), 800.0f, 1.0f);

		// 0% fuel -> 100uu
		TestNearlyEqual(TEXT("0% fuel light radius is 100uu"), Evaluator->EvaluateLightRadius(0.0f), 100.0f, 1.0f);

		// 50% fuel -> 450uu
		TestNearlyEqual(TEXT("50% fuel light radius is 450uu"), Evaluator->EvaluateLightRadius(0.5f), 450.0f, 1.0f);

		// Miss penalty in total darkness (100uu) -> 60%
		TestNearlyEqual(TEXT("100uu miss penalty is 0.60"), Evaluator->EvaluateDarknessMissPenalty(100.0f), 0.60f, 0.01f);

		// Fear debt in total darkness (100uu) -> 0.02/s
		TestNearlyEqual(TEXT("100uu fear debt is 0.02/s"), Evaluator->EvaluateFearDebtPerSecond(100.0f), 0.02f, 0.001f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST ACOUSTIC ECHOLOCATION PROPAGATION
	// -----------------------------------------------------------------------------------
	{
		UAshenAcousticEcholocationEvaluator* SonarEvaluator = NewObject<UAshenAcousticEcholocationEvaluator>();

		// Footstep -> 350uu
		TestNearlyEqual(TEXT("Footstep sonar radius is 350uu"), SonarEvaluator->EvaluateSonarPropagationRadius(EEcholocationPulseType::FootstepEcho), 350.0f, 1.0f);

		// Ground Slam -> 1800uu
		TestNearlyEqual(TEXT("Ground slam sonar radius is 1800uu"), SonarEvaluator->EvaluateSonarPropagationRadius(EEcholocationPulseType::GroundSlamSonar), 1800.0f, 1.0f);

		// Radiant Flare -> 1200uu
		TestNearlyEqual(TEXT("Radiant flare pulse radius is 1200uu"), SonarEvaluator->EvaluateSonarPropagationRadius(EEcholocationPulseType::RadiantFlarePulse), 1200.0f, 1.0f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST TORCH ENDURANCE COMPONENT
	// -----------------------------------------------------------------------------------
	{
		UAshenTorchEnduranceComponent* TorchComp = NewObject<UAshenTorchEnduranceComponent>();
		// Consume 60s -> fuel drops to 0.50
		const float Remaining = TorchComp->ConsumeTorchFuel(60.0f);
		TestNearlyEqual(TEXT("60s burn leaves 0.50 fuel"), Remaining, 0.50f, 0.02f);

		// Rekindle +0.30 -> fuel rises to 0.80
		TorchComp->RekindleTorch(0.30f);
		TestNearlyEqual(TEXT("Rekindled fuel is 0.80"), TorchComp->GetCurrentFuel01(), 0.80f, 0.02f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario8HapticBridge* HapticBridge = NewObject<UAshenScenario8HapticBridge>();
		float LurkerHeartbeat = 0.0f;
		float TriggerFear = 0.0f;
		float SonarTick = 0.0f;

		// Pitch black darkness at 200uu lurker proximity (Proximity = 1 - 200/800 = 0.75)
		HapticBridge->EvaluateAbyssHaptics(ELightEnvironmentState::PitchBlackDarkness, 1800.0f, 200.0f, LurkerHeartbeat, TriggerFear, SonarTick);
		TestNearlyEqual(TEXT("Lurker heartbeat is strong (0.63)"), LurkerHeartbeat, 0.6375f, 0.02f);
		TestNearlyEqual(TEXT("Pitch black trigger fear is 0.90"), TriggerFear, 0.90f, 0.01f);
		TestNearlyEqual(TEXT("Sonar tick is 1.00"), SonarTick, 1.00f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario8SaveGameAdapter* SaveAdapter = NewObject<UAshenScenario8SaveGameAdapter>();
		SaveAdapter->PackageScenario8State(0.65f, 555.0f, 5, 3);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		float RestoredFuel = 0.0f;
		float RestoredLight = 0.0f;
		int32 RestoredLurkers = 0;
		int32 RestoredChasms = 0;

		const bool bSuccess = SaveAdapter->RestoreScenario8State(RestoredFuel, RestoredLight, RestoredLurkers, RestoredChasms);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Restored fuel is 0.65"), RestoredFuel, 0.65f, 0.01f);
		TestNearlyEqual(TEXT("Restored light is 555uu"), RestoredLight, 555.0f, 0.5f);
		TestEqual(TEXT("Restored lurkers is 5"), RestoredLurkers, 5);
		TestEqual(TEXT("Restored chasms is 3"), RestoredChasms, 3);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
