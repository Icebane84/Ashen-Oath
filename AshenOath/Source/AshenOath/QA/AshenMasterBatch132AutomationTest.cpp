// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "Scenarios/AshenBleedingWaystationSubsystem.h"
#include "Scenarios/AshenCompanionFormationSpacingEvaluator.h"
#include "Scenarios/AshenStateTreeReactionDelayEvaluator.h"
#include "Scenarios/AshenAvoidantMercyDiagnosisEvaluator.h"
#include "Scenarios/AshenWaystationHapticBridge.h"
#include "Core/AshenWaystationSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch132AutomationTest,
	"AshenOath.Scenarios.MasterBatch132_BleedingWaystationCrucible",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch132AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST 4-RUN FORMATION SPACING EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenCompanionFormationSpacingEvaluator* SpacingEvaluator = NewObject<UAshenCompanionFormationSpacingEvaluator>();

		// Run B (Grace) -> 300 uu (Tight Wedge)
		TestNearlyEqual(TEXT("Run B Serafina distance is 300 uu"), SpacingEvaluator->EvaluateSerafinaFormationDistance(EWaystationRunMode::RunB_PureGrace), 300.0f, 0.1f);
		TestNearlyEqual(TEXT("Run B Garrett distance is 350 uu"), SpacingEvaluator->EvaluateGarrettFormationDistance(EWaystationRunMode::RunB_PureGrace), 350.0f, 0.1f);

		// Run A (Harvest) -> 1000 uu (Distant)
		TestNearlyEqual(TEXT("Run A Serafina distance is 1000 uu"), SpacingEvaluator->EvaluateSerafinaFormationDistance(EWaystationRunMode::RunA_ShadowHarvest), 1000.0f, 0.1f);

		// Run C (Spiral) -> 1200 uu (Terrified Perimeter)
		TestNearlyEqual(TEXT("Run C Serafina distance is 1200 uu"), SpacingEvaluator->EvaluateSerafinaFormationDistance(EWaystationRunMode::RunC_TheSpiral), 1200.0f, 0.1f);

		// Run D (Avoidant Mercy) -> 750 uu (Guarded Hesitation)
		TestNearlyEqual(TEXT("Run D Serafina distance is 750 uu"), SpacingEvaluator->EvaluateSerafinaFormationDistance(EWaystationRunMode::RunD_AvoidantMercy), 750.0f, 0.1f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST STATETREE HESITATION LATENCY EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenStateTreeReactionDelayEvaluator* DelayEvaluator = NewObject<UAshenStateTreeReactionDelayEvaluator>();

		// Run B -> 0 ms (Instant)
		TestNearlyEqual(TEXT("Run B delay is 0 ms"), DelayEvaluator->EvaluateHesitationLatencyMS(EWaystationRunMode::RunB_PureGrace), 0.0f, 0.1f);

		// Run A -> 300 ms (Hesitation)
		TestNearlyEqual(TEXT("Run A delay is 300 ms"), DelayEvaluator->EvaluateHesitationLatencyMS(EWaystationRunMode::RunA_ShadowHarvest), 300.0f, 0.1f);

		// Run C -> 600 ms (Panic Lock)
		TestNearlyEqual(TEXT("Run C delay is 600 ms"), DelayEvaluator->EvaluateHesitationLatencyMS(EWaystationRunMode::RunC_TheSpiral), 600.0f, 0.1f);

		// Run D -> 150 ms (Uncertainty)
		TestNearlyEqual(TEXT("Run D delay is 150 ms"), DelayEvaluator->EvaluateHesitationLatencyMS(EWaystationRunMode::RunD_AvoidantMercy), 150.0f, 0.1f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST RUN D INVARIANT (AVOIDANT MERCY DIAGNOSIS)
	// -----------------------------------------------------------------------------------
	{
		UAshenAvoidantMercyDiagnosisEvaluator* DiagnosisEvaluator = NewObject<UAshenAvoidantMercyDiagnosisEvaluator>();

		// Sparing with low debt (0.20) -> Diagnosed as Pure Grace (Run B)
		const EWaystationRunMode LowDebtMode = DiagnosisEvaluator->DiagnoseSparingAction(0.20f);
		TestTrue(TEXT("Low debt sparing is Run B Pure Grace"), LowDebtMode == EWaystationRunMode::RunB_PureGrace);

		// Sparing with high debt (0.85 >= 0.75) -> Diagnosed as Avoidant Mercy (Run D)
		const EWaystationRunMode HighDebtMode = DiagnosisEvaluator->DiagnoseSparingAction(0.85f);
		TestTrue(TEXT("High debt sparing is Run D Avoidant Mercy"), HighDebtMode == EWaystationRunMode::RunD_AvoidantMercy);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS & SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenWaystationHapticBridge* HapticBridge = NewObject<UAshenWaystationHapticBridge>();
		float TriggerRes = 0.0f;
		float Tremor = 0.0f;

		// Run B -> Strong X-Lock torque (0.85), Calm tremor (0.05)
		HapticBridge->EvaluateWaystationHaptics(EWaystationRunMode::RunB_PureGrace, TriggerRes, Tremor);
		TestNearlyEqual(TEXT("Run B X-lock resistance is 0.85"), TriggerRes, 0.85f, 0.01f);
		TestNearlyEqual(TEXT("Run B tremor is 0.05"), Tremor, 0.05f, 0.01f);

		// SaveGame
		UAshenWaystationSaveGameAdapter* SaveAdapter = NewObject<UAshenWaystationSaveGameAdapter>();
		SaveAdapter->PackageWaystationState(EWaystationRunMode::RunB_PureGrace, EScoutCatalystDecision::MercifulCleanDeath, 300.0f, 0.0f);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		EWaystationRunMode RestoredMode;
		EScoutCatalystDecision RestoredDecision;
		float RestoredDist = 0.0f;
		float RestoredDelay = 0.0f;
		const bool bSuccess = SaveAdapter->RestoreWaystationState(RestoredMode, RestoredDecision, RestoredDist, RestoredDelay);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("Restored mode is Run B"), RestoredMode == EWaystationRunMode::RunB_PureGrace);
		TestEqual(TEXT("Restored distance is 300 uu"), RestoredDist, 300.0f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
