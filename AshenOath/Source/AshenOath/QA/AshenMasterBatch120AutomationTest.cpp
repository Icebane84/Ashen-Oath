// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "Combat/AshenComboChainEvaluatorComponent.h"
#include "Combat/AshenDualSenseHapticResonanceComponent.h"
#include "Combat/AshenHarmonizedFinisherOrchestratorComponent.h"
#include "Core/AshenTripartiteSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch120AutomationTest,
	"AshenOath.Combat.MasterBatch120_TripartiteResonance",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch120AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST 3-STEP TRIPARTITE COMBO PROGRESSION
	// -----------------------------------------------------------------------------------
	{
		UAshenComboChainEvaluatorComponent* Evaluator = NewObject<UAshenComboChainEvaluatorComponent>();

		// Step 1: Start combo on heavy stagger
		const FTripartiteComboState State1 = Evaluator->StartCombo(2.5f);
		TestEqual(TEXT("Step 1 is Kaelen Cleave"), State1.CurrentPhase, ETripartiteComboPhase::Step1_KaelenCleave);
		TestNearlyEqual(TEXT("Remaining window is 2.5s"), State1.RemainingWindowSeconds, 2.5f, 0.01f);

		// Step 2: Garrett executes wire snare
		const FTripartiteComboState State2 = Evaluator->ProgressToStep2(true);
		TestEqual(TEXT("Step 2 is Garrett Snare"), State2.CurrentPhase, ETripartiteComboPhase::Step2_GarrettSnare);
		TestTrue(TEXT("Garrett is in proximity"), State2.bGarrettInProximity);

		// Step 3: Serafina executes holy burst -> Finisher Ready
		const FTripartiteComboState State3 = Evaluator->ProgressToStep3(true);
		TestEqual(TEXT("Step 3 advances to Finisher Ready"), State3.CurrentPhase, ETripartiteComboPhase::FinisherReady);
		TestTrue(TEXT("Serafina is in proximity"), State3.bSerafinaInProximity);
		TestEqual(TEXT("Tier is Radiant Catharsis"), State3.FinisherTier, EHarmonizedFinisherTier::RadiantCatharsis);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST 60 BPM DUALSENSE HAPTIC PROFILE EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenDualSenseHapticResonanceComponent* HapticComp = NewObject<UAshenDualSenseHapticResonanceComponent>();

		const FHapticResonanceProfile Profile = HapticComp->EvaluateHapticProfile(ETripartiteComboPhase::FinisherReady);
		TestNearlyEqual(TEXT("Pulse frequency is 1.0 Hz (60 BPM)"), Profile.PulseFrequencyHz, 1.0f, 0.01f);
		TestNearlyEqual(TEXT("Left trigger resistance is 1.0"), Profile.LeftTriggerResistance, 1.0f, 0.01f);
		TestNearlyEqual(TEXT("Vibration intensity is 1.0 (Full resonance)"), Profile.VibrationIntensity, 1.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST HARMONIZED FINISHER DAMAGE SCALING
	// -----------------------------------------------------------------------------------
	{
		UAshenHarmonizedFinisherOrchestratorComponent* Orchestrator = NewObject<UAshenHarmonizedFinisherOrchestratorComponent>();

		// Base damage = 1000.0, Radiant Catharsis = 3.5x -> 3500.0
		const float TotalDamage = Orchestrator->CalculateFinisherDamage(1000.0f, EHarmonizedFinisherTier::RadiantCatharsis);
		TestNearlyEqual(TEXT("Radiant Catharsis damage is 3500.0 (3.5x)"), TotalDamage, 3500.0f, 1.0f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST TRIPARTITE SAVEGAME ADAPTER
	// -----------------------------------------------------------------------------------
	{
		UAshenTripartiteSaveGameAdapter* SaveAdapter = NewObject<UAshenTripartiteSaveGameAdapter>();

		SaveAdapter->PackageTripartiteData(25, 7, 1450.0f);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		int32 RestoredFinishers = 0;
		int32 RestoredStreaks = 0;
		float RestoredCatharsis = 0.0f;
		const bool bSuccess = SaveAdapter->RestoreTripartiteData(RestoredFinishers, RestoredStreaks, RestoredCatharsis);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("Total finishers restored"), RestoredFinishers, 25);
		TestEqual(TEXT("Unbroken streaks restored"), RestoredStreaks, 7);
		TestNearlyEqual(TEXT("Catharsis score restored"), RestoredCatharsis, 1450.0f, 1.0f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
