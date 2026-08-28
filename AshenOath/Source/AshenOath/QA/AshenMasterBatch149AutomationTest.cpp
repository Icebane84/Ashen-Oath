// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "Combat/AshenBladeSanityConductorConvergenceSubsystem.h"
#include "Combat/AshenBladeSanityFeedbackEvaluator.h"
#include "Combat/AshenQuartzDissonanceMixEvaluator.h"
#include "Combat/AshenFlowStateCatharsisDirectorComponent.h"
#include "Combat/AshenBladeSanityHapticBridge.h"
#include "Core/AshenBladeSanitySaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch149AutomationTest,
	"AshenOath.Combat.MasterBatch149_BladeSanityQuartzFlowConvergence",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch149AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST BLADE DAMAGE & PARRY/DODGE PENALTIES
	// -----------------------------------------------------------------------------------
	{
		UAshenBladeSanityFeedbackEvaluator* FeedbackEvaluator = NewObject<UAshenBladeSanityFeedbackEvaluator>();

		// Damage bonus: +45% at 100% hunger
		TestNearlyEqual(TEXT("Max hunger blade damage multiplier is 1.45x"), FeedbackEvaluator->EvaluateBladeDamageMultiplier(1.0f), 1.45f, 0.01f);
		TestNearlyEqual(TEXT("Zero hunger blade damage multiplier is 1.00x"), FeedbackEvaluator->EvaluateBladeDamageMultiplier(0.0f), 1.00f, 0.01f);

		// Parry window penalty: -35% at 0 sanity
		TestNearlyEqual(TEXT("Zero sanity parry window reduction is 35%"), FeedbackEvaluator->EvaluateParryWindowPenalty(0.0f), 0.35f, 0.01f);
		TestNearlyEqual(TEXT("Full sanity parry window reduction is 0%"), FeedbackEvaluator->EvaluateParryWindowPenalty(100.0f), 0.0f, 0.01f);

		// Dodge stamina multiplier: 1.50x at 0 sanity
		TestNearlyEqual(TEXT("Zero sanity dodge stamina multiplier is 1.50x"), FeedbackEvaluator->EvaluateDodgeStaminaMultiplier(0.0f), 1.50f, 0.01f);
		TestNearlyEqual(TEXT("Full sanity dodge stamina multiplier is 1.00x"), FeedbackEvaluator->EvaluateDodgeStaminaMultiplier(100.0f), 1.00f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST QUARTZ STEM 02 WHISPER GAIN & MELODIC DUCKING
	// -----------------------------------------------------------------------------------
	{
		UAshenQuartzDissonanceMixEvaluator* MixEvaluator = NewObject<UAshenQuartzDissonanceMixEvaluator>();

		// 0 Sanity: Stem 02 gain = 1.0, Melodic ducking = -18dB
		TestNearlyEqual(TEXT("Zero sanity Stem 02 gain is 1.0"), MixEvaluator->EvaluateStem02WhisperGain(0.0f, false), 1.0f, 0.01f);
		TestNearlyEqual(TEXT("Zero sanity melodic ducking is -18.0dB"), MixEvaluator->EvaluateMelodicDuckingDb(0.0f, false), -18.0f, 0.01f);

		// Flow State active: Stem 02 silenced (0.0), ducking = 0.0dB
		TestNearlyEqual(TEXT("Flow state silences Stem 02 whispers"), MixEvaluator->EvaluateStem02WhisperGain(0.0f, true), 0.0f, 0.01f);
		TestNearlyEqual(TEXT("Flow state clears melodic ducking"), MixEvaluator->EvaluateMelodicDuckingDb(0.0f, true), 0.0f, 0.01f);

		// Audio LPF cutoff: 300Hz at 0 sanity, 8000Hz at 100 sanity
		TestNearlyEqual(TEXT("Zero sanity LPF cutoff is 300Hz"), MixEvaluator->EvaluateAudioLpfCutoffHz(0.0f), 300.0f, 0.01f);
		TestNearlyEqual(TEXT("Full sanity LPF cutoff is 8000Hz"), MixEvaluator->EvaluateAudioLpfCutoffHz(100.0f), 8000.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST FLOW STATE CATHARSIS CONSTANTS
	// -----------------------------------------------------------------------------------
	{
		UAshenFlowStateCatharsisDirectorComponent* FlowDirector = NewObject<UAshenFlowStateCatharsisDirectorComponent>();

		TestNearlyEqual(TEXT("Flow state duration is 8.0s"), FlowDirector->GetFlowStateDurationSeconds(), 8.0f, 0.01f);
		TestNearlyEqual(TEXT("Flow stamina recovery multiplier is 2.0x"), FlowDirector->GetFlowStaminaRegenMultiplier(), 2.0f, 0.01f);
		TestNearlyEqual(TEXT("Flow instant sanity catharsis is +40.0"), FlowDirector->GetInstantSanityCatharsisAmount(), 40.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenBladeSanityHapticBridge* HapticBridge = NewObject<UAshenBladeSanityHapticBridge>();
		float BladeRumble = 0.0f;
		float SanityJitter = 0.0f;
		float FlowPurr = 0.0f;

		// 100% hunger at 0 sanity outside flow state
		HapticBridge->EvaluateConvergenceHaptics(1.0f, 0.0f, false, BladeRumble, SanityJitter, FlowPurr);
		TestNearlyEqual(TEXT("Max hunger blade rumble is 0.90"), BladeRumble, 0.90f, 0.01f);
		TestNearlyEqual(TEXT("Zero sanity distortion jitter is 0.80"), SanityJitter, 0.80f, 0.01f);
		TestNearlyEqual(TEXT("Flow purr is 0 outside flow state"), FlowPurr, 0.0f, 0.01f);

		// Inside flow state: smooth purr 0.85, 0 rumble/jitter
		HapticBridge->EvaluateConvergenceHaptics(1.0f, 0.0f, true, BladeRumble, SanityJitter, FlowPurr);
		TestNearlyEqual(TEXT("Flow state purr is 0.85"), FlowPurr, 0.85f, 0.01f);
		TestNearlyEqual(TEXT("Flow state silences blade rumble"), BladeRumble, 0.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenBladeSanitySaveGameAdapter* SaveAdapter = NewObject<UAshenBladeSanitySaveGameAdapter>();
		SaveAdapter->PackageConvergenceState(0.75f, 30.0f, ESanityDissonanceTier::ParanoidStatic);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		float RestoredHunger = 0.0f;
		float RestoredSanity = 0.0f;
		ESanityDissonanceTier RestoredTier = ESanityDissonanceTier::LucidHarmonic;

		const bool bSuccess = SaveAdapter->RestoreConvergenceState(RestoredHunger, RestoredSanity, RestoredTier);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Restored hunger is 0.75"), RestoredHunger, 0.75f, 0.01f);
		TestNearlyEqual(TEXT("Restored sanity is 30.0"), RestoredSanity, 30.0f, 0.01f);
		TestTrue(TEXT("Restored tier is ParanoidStatic"), RestoredTier == ESanityDissonanceTier::ParanoidStatic);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
