// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "Scenarios/AshenScenario5MissionSubsystem.h"
#include "Scenarios/AshenUnchainedCombatEvaluatorComponent.h"
#include "Scenarios/AshenMireHazardEvaluatorComponent.h"
#include "Scenarios/AshenHeartPalpitationEvaluatorComponent.h"
#include "Scenarios/AshenScenario5HapticBridge.h"
#include "Core/AshenScenario5SaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch130AutomationTest,
	"AshenOath.Scenarios.MasterBatch130_Scenario5WeepingMire",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch130AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST UNCHAINED MODE DAMAGE & LUNGE SCALING
	// -----------------------------------------------------------------------------------
	{
		UAshenUnchainedCombatEvaluatorComponent* CombatEvaluator = NewObject<UAshenUnchainedCombatEvaluatorComponent>();

		// Frenzy -> 1.50x damage (+50%), 1.80x lunge velocity
		TestNearlyEqual(TEXT("Unchained Frenzy damage is 1.50x"), CombatEvaluator->EvaluateDamageMultiplier(EUnchainedVesselPhase::UnchainedFrenzy), 1.50f, 0.01f);
		TestNearlyEqual(TEXT("Unchained Frenzy lunge is 1.80x"), CombatEvaluator->EvaluateLungeVelocityMultiplier(EUnchainedVesselPhase::UnchainedFrenzy), 1.80f, 0.01f);

		// Exhausted -> 0.70x damage (-30%)
		TestNearlyEqual(TEXT("Exhausted damage is 0.70x"), CombatEvaluator->EvaluateDamageMultiplier(EUnchainedVesselPhase::ExhaustedVulnerable), 0.70f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST MUD LOCOMOTION & GAS POCKET DETONATIONS
	// -----------------------------------------------------------------------------------
	{
		UAshenMireHazardEvaluatorComponent* HazardEvaluator = NewObject<UAshenMireHazardEvaluatorComponent>();

		// Normal mud speed -> 0.50x
		TestNearlyEqual(TEXT("Standard mud speed is 0.50x"), HazardEvaluator->EvaluateMudSpeedMultiplier(true, false), 0.50f, 0.01f);

		// Unchained mud speed -> 0.85x
		TestNearlyEqual(TEXT("Unchained mud speed is 0.85x"), HazardEvaluator->EvaluateMudSpeedMultiplier(true, true), 0.85f, 0.01f);

		// Gas blast falloff: 250 base at 225cm (half of 450cm) -> 125 damage
		const float BlastHalf = HazardEvaluator->EvaluateGasBlastDamage(250.0f, 225.0f, 450.0f);
		TestNearlyEqual(TEXT("Blast damage at midpoint is 125"), BlastHalf, 125.0f, 0.01f);

		// Gas blast at 500cm (>450cm) -> 0 damage
		const float BlastOut = HazardEvaluator->EvaluateGasBlastDamage(250.0f, 500.0f, 450.0f);
		TestNearlyEqual(TEXT("Blast damage out of range is 0"), BlastOut, 0.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST HEART PALPITATION BPM & DUALSENSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenHeartPalpitationEvaluatorComponent* HeartEvaluator = NewObject<UAshenHeartPalpitationEvaluatorComponent>();
		UAshenScenario5HapticBridge* HapticBridge = NewObject<UAshenScenario5HapticBridge>();

		// Frenzy with 0.50 stress -> 130 + (0.50 * 40) = 150 BPM
		const float FrenzyBPM = HeartEvaluator->EvaluateHeartRateBPM(EUnchainedVesselPhase::UnchainedFrenzy, 0.50f);
		TestNearlyEqual(TEXT("Frenzy heart rate is 150 BPM"), FrenzyBPM, 150.0f, 0.01f);

		float TriggerRes = 0.0f;
		float PulseInt = 0.0f;
		HapticBridge->EvaluateMireHaptics(EUnchainedVesselPhase::UnchainedFrenzy, true, TriggerRes, PulseInt);
		TestNearlyEqual(TEXT("Mud trigger resistance is 0.75"), TriggerRes, 0.75f, 0.01f);
		TestNearlyEqual(TEXT("Frenzy pulse intensity is 0.95"), PulseInt, 0.95f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario5SaveGameAdapter* SaveAdapter = NewObject<UAshenScenario5SaveGameAdapter>();

		SaveAdapter->PackageScenario5State(true, 4, true);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		bool bCleared = false;
		int32 Detonations = 0;
		bool bZeroDowned = false;
		const bool bSuccess = SaveAdapter->RestoreScenario5State(bCleared, Detonations, bZeroDowned);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("bCleared is true"), bCleared);
		TestEqual(TEXT("Gas detonations count is 4"), Detonations, 4);
		TestTrue(TEXT("bZeroDowned is true"), bZeroDowned);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
