// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Combat/AshenBladeSanityConductorConvergenceSubsystem.h"
#include "Combat/AshenBladeSanityFeedbackEvaluator.h"
#include "Combat/AshenBladeSanityBalanceDataAsset.h"
#include "Combat/AshenBladeSanityConductorTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBladeSanityConvergenceIntegrationTest,
	"AshenOath.Convergence.BladeSanity.HungerAndFlowCatharsis",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenBladeSanityConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & GAME INSTANCE
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("BladeSanityTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	GameInstance->Init();
	World->SetGameInstance(GameInstance);

	UAshenBladeSanityConductorConvergenceSubsystem* Subsystem = World->GetSubsystem<UAshenBladeSanityConductorConvergenceSubsystem>();
	TestNotNull(TEXT("UAshenBladeSanityConductorConvergenceSubsystem exists on World"), Subsystem);

	UAshenBladeSanityFeedbackEvaluator* Evaluator = NewObject<UAshenBladeSanityFeedbackEvaluator>(World);
	TestNotNull(TEXT("UAshenBladeSanityFeedbackEvaluator instantiated"), Evaluator);

	// -----------------------------------------------------------------------------------
	// 2. TEST BLADE HUNGER DAMAGE AMPLIFICATION
	// -----------------------------------------------------------------------------------
	if (Evaluator)
	{
		// 0% Hunger -> 1.0x damage
		const float Dmg0 = Evaluator->EvaluateBladeDamageMultiplier(0.0f);
		TestNearlyEqual(TEXT("0% Hunger yields 1.00x damage"), Dmg0, 1.00f, 0.01f);

		// 50% Hunger -> 1.225x damage
		const float Dmg50 = Evaluator->EvaluateBladeDamageMultiplier(0.50f);
		TestNearlyEqual(TEXT("50% Hunger yields 1.225x damage"), Dmg50, 1.225f, 0.01f);

		// 100% Hunger -> 1.45x damage (+45%)
		const float Dmg100 = Evaluator->EvaluateBladeDamageMultiplier(1.00f);
		TestNearlyEqual(TEXT("100% Hunger yields 1.45x damage"), Dmg100, 1.45f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SANITY PARRY & DODGE PENALTIES
	// -----------------------------------------------------------------------------------
	if (Evaluator)
	{
		// 100 Sanity -> 0.0 parry penalty, 1.0x dodge stamina
		const float ParryPenalty100 = Evaluator->EvaluateParryWindowPenalty(100.0f);
		const float DodgeCost100 = Evaluator->EvaluateDodgeStaminaMultiplier(100.0f);
		TestNearlyEqual(TEXT("100 Sanity yields 0.0 parry penalty"), ParryPenalty100, 0.0f, 0.01f);
		TestNearlyEqual(TEXT("100 Sanity yields 1.00x dodge cost"), DodgeCost100, 1.00f, 0.01f);

		// 0 Sanity -> 0.35 parry penalty (-35%), 1.50x dodge stamina (+50%)
		const float ParryPenalty0 = Evaluator->EvaluateParryWindowPenalty(0.0f);
		const float DodgeCost0 = Evaluator->EvaluateDodgeStaminaMultiplier(0.0f);
		TestNearlyEqual(TEXT("0 Sanity yields 0.35 parry penalty"), ParryPenalty0, 0.35f, 0.01f);
		TestNearlyEqual(TEXT("0 Sanity yields 1.50x dodge cost"), DodgeCost0, 1.50f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST QUARTZ STEM 02 WHISPER GAIN & MELODIC DUCKING
	// -----------------------------------------------------------------------------------
	if (Subsystem)
	{
		// Update convergence at 100% Hunger for 50s (Drains 100 -> 25)
		Subsystem->UpdateConvergenceState(50.0f, 1.00f, false);
		FBladeSanityHarmonicVector State = Subsystem->GetHarmonicState();

		TestNearlyEqual(TEXT("Sanity drained to 25.0"), State.CurrentSanity, 25.0f, 0.1f);
		TestTrue(TEXT("Dissonance Tier is ParanoidStatic at 25 Sanity"), State.DissonanceTier == ESanityDissonanceTier::ParanoidStatic);
		TestNearlyEqual(TEXT("Stem 02 whisper gain is 0.75"), State.Stem02WhisperGain, 0.75f, 0.02f);
		TestNearlyEqual(TEXT("Melodic ducking is -13.5dB"), State.MelodicDuckingDb, -13.5f, 0.2f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST FLOW STATE CATHARSIS PURGE (+40 SANITY, MUTED WHISPERS)
	// -----------------------------------------------------------------------------------
	if (Subsystem)
	{
		Subsystem->TriggerFlowCatharsisPurge();
		FBladeSanityHarmonicVector State = Subsystem->GetHarmonicState();

		// Sanity healed +40 (25 -> 65)
		TestNearlyEqual(TEXT("Sanity catharsis healed to 65.0"), State.CurrentSanity, 65.0f, 0.1f);
		TestTrue(TEXT("Flow state is active"), State.bFlowStateActive);
		TestNearlyEqual(TEXT("Stem 02 whispers completely muted (0.0)"), State.Stem02WhisperGain, 0.0f, 0.01f);
		TestNearlyEqual(TEXT("Melodic ducking cleared (0.0dB)"), State.MelodicDuckingDb, 0.0f, 0.01f);
		TestTrue(TEXT("Dissonance Tier is AnxiousEchoes after catharsis (65 Sanity)"), State.DissonanceTier == ESanityDissonanceTier::AnxiousEchoes);
	}

	// -----------------------------------------------------------------------------------
	// 6. TEST DATA ASSET LIVE OVERRIDE
	// -----------------------------------------------------------------------------------
	if (Evaluator && Subsystem)
	{
		UAshenBladeSanityBalanceDataAsset* BalanceAsset = NewObject<UAshenBladeSanityBalanceDataAsset>(World);
		BalanceAsset->BladeHungerParams.MaxDamageMultiplier = 1.80f;
		BalanceAsset->FlowCatharsisParams.InstantSanityHeal = 60.0f;

		Evaluator->BalanceDataAsset = BalanceAsset;
		Subsystem->BalanceDataAsset = BalanceAsset;

		const float CustomDmg100 = Evaluator->EvaluateBladeDamageMultiplier(1.00f);
		TestNearlyEqual(TEXT("DataAsset live override sets max damage to 1.80x"), CustomDmg100, 1.80f, 0.01f);
	}

	// Cleanup
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
