// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "Combat/AshenOathbringerStanceFlowConvergenceSubsystem.h"
#include "Combat/AshenStanceKinematicsEvaluator.h"
#include "Combat/AshenFlowChainingTimingEvaluator.h"
#include "Combat/AshenOathbringerRunicSeamDirectorComponent.h"
#include "Combat/AshenOathbringerStanceHapticBridge.h"
#include "Core/AshenOathbringerStanceSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch153AutomationTest,
	"AshenOath.Combat.MasterBatch153_OathbringerStanceFlowConvergence",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch153AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST 4-GUARD STANCE KINEMATICS EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenStanceKinematicsEvaluator* Evaluator = NewObject<UAshenStanceKinematicsEvaluator>();

		// Vom Tag: 1.40x damage, 1.40x poise damage, 0.08s parry, 20% armor penetration
		TestNearlyEqual(TEXT("Vom Tag damage multiplier is 1.40x"), Evaluator->EvaluateDamageMultiplier(EOathbringerMartialStance::VomTag_HighWrath), 1.40f, 0.01f);
		TestNearlyEqual(TEXT("Vom Tag poise multiplier is 1.40x"), Evaluator->EvaluatePoiseDamageMultiplier(EOathbringerMartialStance::VomTag_HighWrath), 1.40f, 0.01f);

		// Pflug: 1.0x damage, 0.90x poise damage, 0.10s parry, 35% armor penetration
		TestNearlyEqual(TEXT("Pflug damage multiplier is 1.00x"), Evaluator->EvaluateDamageMultiplier(EOathbringerMartialStance::Pflug_LowPlow), 1.00f, 0.01f);

		// Ochs: 1.10x damage, 0.22s parry window (+0.12s leniency)
		TestNearlyEqual(TEXT("Ochs parry window is 0.22s"), Evaluator->EvaluateParryWindowSeconds(EOathbringerMartialStance::Ochs_CrownGuard), 0.22f, 0.01f);

		// Mordhau: 1.25x damage, 1.75x poise damage (+75% shield shatter), 100% armor penetration
		TestNearlyEqual(TEXT("Mordhau poise damage is 1.75x"), Evaluator->EvaluatePoiseDamageMultiplier(EOathbringerMartialStance::Mordhau_HalfSword), 1.75f, 0.01f);
		TestNearlyEqual(TEXT("Mordhau armor penetration is 100%"), Evaluator->EvaluateArmorPenetration(EOathbringerMartialStance::Mordhau_HalfSword), 1.00f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST FLOW-CHAINING TIMING EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenFlowChainingTimingEvaluator* FlowEvaluator = NewObject<UAshenFlowChainingTimingEvaluator>();

		// Window from 0.40s to 0.55s
		TestTrue(TEXT("0.45s is within flow glint window"), FlowEvaluator->IsWithinFlowGlintWindow(0.45f, 0.40f, 0.15f));
		TestFalse(TEXT("0.60s is outside flow glint window"), FlowEvaluator->IsWithinFlowGlintWindow(0.60f, 0.40f, 0.15f));

		// Stamina cost: 0 on clean flow, 15 on missed
		TestNearlyEqual(TEXT("Clean flow transition stamina cost is 0"), FlowEvaluator->EvaluateTransitionStaminaCost(EFlowChainingTimingQuality::FlowGlintClean), 0.0f, 0.01f);
		TestNearlyEqual(TEXT("Missed timing transition stamina cost is 15"), FlowEvaluator->EvaluateTransitionStaminaCost(EFlowChainingTimingQuality::MissedTiming), 15.0f, 0.01f);

		// Momentum bonus: +25% on clean flow
		TestNearlyEqual(TEXT("Clean flow momentum bonus is +25%"), FlowEvaluator->EvaluateMomentumDamageBonus(EFlowChainingTimingQuality::FlowGlintClean), 0.25f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST RUNIC SEAM COLOR DIRECTOR
	// -----------------------------------------------------------------------------------
	{
		UAshenOathbringerRunicSeamDirectorComponent* SeamDirector = NewObject<UAshenOathbringerRunicSeamDirectorComponent>();

		const FLinearColor Crimson = SeamDirector->GetSeamColorForStance(EOathbringerMartialStance::VomTag_HighWrath);
		TestNearlyEqual(TEXT("Vom Tag red channel is 1.0"), Crimson.R, 1.0f, 0.01f);
		TestNearlyEqual(TEXT("Vom Tag emissive intensity is 4.5"), SeamDirector->GetEmissiveIntensityForStance(EOathbringerMartialStance::VomTag_HighWrath), 4.50f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE STANCE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenOathbringerStanceHapticBridge* HapticBridge = NewObject<UAshenOathbringerStanceHapticBridge>();
		float HeavyGain = 0.0f;
		float LightGain = 0.0f;

		// Clean flow cancel: 0.50 heavy, 0.95 light ping
		HapticBridge->EvaluateStanceHaptics(EOathbringerMartialStance::VomTag_HighWrath, true, HeavyGain, LightGain);
		TestNearlyEqual(TEXT("Clean flow light ping is 0.95"), LightGain, 0.95f, 0.01f);

		// Vom Tag strike: 0.90 heavy thud
		HapticBridge->EvaluateStanceHaptics(EOathbringerMartialStance::VomTag_HighWrath, false, HeavyGain, LightGain);
		TestNearlyEqual(TEXT("Vom Tag heavy thud is 0.90"), HeavyGain, 0.90f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenOathbringerStanceSaveGameAdapter* SaveAdapter = NewObject<UAshenOathbringerStanceSaveGameAdapter>();
		SaveAdapter->PackageStanceState(EOathbringerMartialStance::Mordhau_HalfSword, 45.0f, 4);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		EOathbringerMartialStance RestoredStance = EOathbringerMartialStance::VomTag_HighWrath;
		float RestoredFlowCharge = 0.0f;
		int32 RestoredMastered = 0;

		const bool bSuccess = SaveAdapter->RestoreStanceState(RestoredStance, RestoredFlowCharge, RestoredMastered);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("Restored stance is Mordhau"), RestoredStance == EOathbringerMartialStance::Mordhau_HalfSword);
		TestNearlyEqual(TEXT("Restored flow charge is 45"), RestoredFlowCharge, 45.0f, 0.01f);
		TestEqual(TEXT("Restored mastered count is 4"), RestoredMastered, 4);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
