// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Scenarios/AshenScenario7Types.h"
#include "Scenarios/AshenScenario7MissionSubsystem.h"
#include "Scenarios/AshenCalderaThermodynamicsEvaluator.h"
#include "Scenarios/AshenMoltenTemperingEvaluator.h"
#include "Scenarios/AshenMagmaSurgeHazardDirectorComponent.h"
#include "Scenarios/AshenScenario7HapticBridge.h"
#include "Core/AshenScenario7SaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch137AutomationTest,
	"AshenOath.Scenarios.MasterBatch137_AshenCrucibleVolcanicCaldera",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch137AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST CALDERA THERMODYNAMICS & HEAT EXHAUSTION
	// -----------------------------------------------------------------------------------
	{
		UAshenCalderaThermodynamicsEvaluator* Evaluator = NewObject<UAshenCalderaThermodynamicsEvaluator>();

		// 75°C Caldera -> (75 - 35)/400 = 0.10 heat/s
		const float HeatRate = Evaluator->EvaluateHeatExhaustionRate(75.0f, false);
		TestNearlyEqual(TEXT("75C heat rate is 0.10/s"), HeatRate, 0.10f, 0.005f);

		// Inside Cryo Mist -> -0.05/s recovery
		const float RecoveryRate = Evaluator->EvaluateHeatExhaustionRate(75.0f, true);
		TestNearlyEqual(TEXT("Cryo mist recovery is -0.05/s"), RecoveryRate, -0.05f, 0.001f);

		// Stamina Drain at 0.50 heat -> 1.50x
		TestNearlyEqual(TEXT("Stamina drain at 0.50 heat is 1.50x"), Evaluator->EvaluateStaminaDrainMultiplier(0.50f), 1.50f, 0.01f);

		// Thermal damage at 1.00 heat -> 30.0 dmg/s
		TestNearlyEqual(TEXT("Thermal damage at 1.00 heat is 30 dmg/s"), Evaluator->EvaluateThermalDamagePerSecond(1.00f), 30.0f, 0.1f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST MOLTEN WEAPON TEMPERING
	// -----------------------------------------------------------------------------------
	{
		UAshenMoltenTemperingEvaluator* TemperingEvaluator = NewObject<UAshenMoltenTemperingEvaluator>();

		// 800°C blade -> 40% fire damage bonus
		const float DamageBonus = TemperingEvaluator->EvaluateFireDamageBonus(800.0f);
		TestNearlyEqual(TEXT("800C blade fire bonus is 0.40"), DamageBonus, 0.40f, 0.01f);

		// State classification
		TestTrue(TEXT("800C is MoltenHeated"), TemperingEvaluator->ClassifyBladeState(800.0f) == ETemperedBladeState::MoltenHeated);
		TestTrue(TEXT("950C is Overheated"), TemperingEvaluator->ClassifyBladeState(950.0f) == ETemperedBladeState::Overheated);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST MAGMA SURGE HAZARD CYCLES
	// -----------------------------------------------------------------------------------
	{
		UAshenMagmaSurgeHazardDirectorComponent* SurgeDirector = NewObject<UAshenMagmaSurgeHazardDirectorComponent>();

		// 5s -> Dormant
		TestTrue(TEXT("5s is DormantCalm"), SurgeDirector->EvaluateSurgePhaseFromTime(5.0f) == ECalderaSurgePhase::DormantCalm);

		// 11s -> Telegraph Warning
		TestTrue(TEXT("11s is TelegraphWarning"), SurgeDirector->EvaluateSurgePhaseFromTime(11.0f) == ECalderaSurgePhase::TelegraphWarning);

		// 14s -> Active Eruption
		TestTrue(TEXT("14s is ActiveEruption"), SurgeDirector->EvaluateSurgePhaseFromTime(14.0f) == ECalderaSurgePhase::ActiveEruption);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario7HapticBridge* HapticBridge = NewObject<UAshenScenario7HapticBridge>();
		float ThermalPulse = 0.0f;
		float TriggerResistance = 0.0f;
		float MagmaRumble = 0.0f;

		HapticBridge->EvaluateCalderaHaptics(0.80f, 800.0f, ECalderaSurgePhase::ActiveEruption, ThermalPulse, TriggerResistance, MagmaRumble);
		TestTrue(TEXT("Thermal pulse is intense (>0.70)"), ThermalPulse >= 0.70f);
		TestNearlyEqual(TEXT("Trigger resistance is 0.85"), TriggerResistance, 0.85f, 0.02f);
		TestNearlyEqual(TEXT("Magma explosion rumble is 0.95"), MagmaRumble, 0.95f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario7SaveGameAdapter* SaveAdapter = NewObject<UAshenScenario7SaveGameAdapter>();
		SaveAdapter->PackageScenario7State(92.0f, 0.25f, 800.0f, ETemperedBladeState::MoltenHeated);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		float RestoredTemp = 0.0f;
		float RestoredHeat = 0.0f;
		float RestoredBladeTemp = 0.0f;
		ETemperedBladeState RestoredBladeState = ETemperedBladeState::ColdSteel;

		const bool bSuccess = SaveAdapter->RestoreScenario7State(RestoredTemp, RestoredHeat, RestoredBladeTemp, RestoredBladeState);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Restored max temp is 92C"), RestoredTemp, 92.0f, 0.1f);
		TestNearlyEqual(TEXT("Restored blade temp is 800C"), RestoredBladeTemp, 800.0f, 0.1f);
		TestTrue(TEXT("Restored blade state is MoltenHeated"), RestoredBladeState == ETemperedBladeState::MoltenHeated);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
