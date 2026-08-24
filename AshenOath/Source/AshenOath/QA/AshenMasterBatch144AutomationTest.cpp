// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "Combat/AshenShroudKnightBossSubsystem.h"
#include "Combat/AshenCreepingParanoiaEvaluator.h"
#include "Combat/AshenPhaseShiftDitherEvaluator.h"
#include "Combat/AshenTrinityStrikeCoordinatorComponent.h"
#include "Combat/AshenShroudKnightHapticBridge.h"
#include "Core/AshenShroudKnightSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch144AutomationTest,
	"AshenOath.Combat.MasterBatch144_ShroudKnightBossCreepingParanoiaTrinityStrike",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch144AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST SHROUD-KNIGHT PHASE-SHIFT DITHERING & COLLISION
	// -----------------------------------------------------------------------------------
	{
		UAshenPhaseShiftDitherEvaluator* DitherEvaluator = NewObject<UAshenPhaseShiftDitherEvaluator>();

		// Physical Solid state
		TestNearlyEqual(TEXT("Physical solid opacity is 1.0"), DitherEvaluator->EvaluateDitherOpacity(EShroudKnightPhaseState::PhysicalSolid), 1.0f, 0.01f);
		TestTrue(TEXT("Physical solid collision is enabled"), DitherEvaluator->IsCollisionEnabled(EShroudKnightPhaseState::PhysicalSolid));

		// Spectral Phasing state
		TestNearlyEqual(TEXT("Spectral phasing opacity is 0.15"), DitherEvaluator->EvaluateDitherOpacity(EShroudKnightPhaseState::SpectralPhasing), 0.15f, 0.01f);
		TestFalse(TEXT("Spectral phasing collision is disabled"), DitherEvaluator->IsCollisionEnabled(EShroudKnightPhaseState::SpectralPhasing));
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST CREEPING PARANOIA PERIPHERAL VISION & CHROMATIC JITTER
	// -----------------------------------------------------------------------------------
	{
		UAshenCreepingParanoiaEvaluator* ParanoiaEvaluator = NewObject<UAshenCreepingParanoiaEvaluator>();

		// Peripheral visibility (>= 45 deg) vs Centered camera (< 35 deg)
		TestTrue(TEXT("Phantom visible at 50 deg periphery"), ParanoiaEvaluator->IsPeripheralPhantomVisible(50.0f));
		TestFalse(TEXT("Phantom vanishes when looked directly at (20 deg)"), ParanoiaEvaluator->IsPeripheralPhantomVisible(20.0f));

		// Chromatic jitter at 100% infection -> 4.5
		TestNearlyEqual(TEXT("100% infection chromatic jitter is 4.5"), ParanoiaEvaluator->EvaluateChromaticJitter(1.0f), 4.5f, 0.01f);

		// Companion eye contact grounding decay rate (-0.15/s)
		TestNearlyEqual(TEXT("Companion eye contact grounding is -0.15/s"), ParanoiaEvaluator->EvaluateGroundingDecayRate(true), -0.15f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST 3-STEP TRINITY STRIKE SEQUENCE & DAMAGE
	// -----------------------------------------------------------------------------------
	{
		UAshenTrinityStrikeCoordinatorComponent* TrinityComp = NewObject<UAshenTrinityStrikeCoordinatorComponent>();

		// Step validation sequence: None -> GuardBreak -> ThreadLock -> PurgeBeam
		TestTrue(TEXT("None -> GuardBreak is valid"), TrinityComp->IsStepValid(ETrinityStrikeStep::None, ETrinityStrikeStep::KaelenGuardBreak));
		TestTrue(TEXT("GuardBreak -> ThreadLock is valid"), TrinityComp->IsStepValid(ETrinityStrikeStep::KaelenGuardBreak, ETrinityStrikeStep::GarrettThreadLock));
		TestTrue(TEXT("ThreadLock -> PurgeBeam is valid"), TrinityComp->IsStepValid(ETrinityStrikeStep::GarrettThreadLock, ETrinityStrikeStep::SerafinaPurgeBeam));
		TestFalse(TEXT("None -> PurgeBeam is INVALID"), TrinityComp->IsStepValid(ETrinityStrikeStep::None, ETrinityStrikeStep::SerafinaPurgeBeam));

		// Serafina Purge Beam Finisher Multiplier is 3.5x
		TestNearlyEqual(TEXT("Purge Beam finisher multiplier is 3.5x"), TrinityComp->EvaluateTrinityDamageMultiplier(ETrinityStrikeStep::SerafinaPurgeBeam), 3.50f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenShroudKnightHapticBridge* HapticBridge = NewObject<UAshenShroudKnightHapticBridge>();
		float TriggerRes = 0.0f;
		float JitterRumble = 0.0f;
		float FinisherImpact = 0.0f;

		// Phasing slack trigger
		HapticBridge->EvaluateBossHaptics(EShroudKnightPhaseState::SpectralPhasing, 0.20f, ETrinityStrikeStep::None, TriggerRes, JitterRumble, FinisherImpact);
		TestNearlyEqual(TEXT("Phasing trigger resistance is 0.05 (slack)"), TriggerRes, 0.05f, 0.01f);

		// Finisher impact
		HapticBridge->EvaluateBossHaptics(EShroudKnightPhaseState::TrinityVulnerable, 0.50f, ETrinityStrikeStep::SerafinaPurgeBeam, TriggerRes, JitterRumble, FinisherImpact);
		TestNearlyEqual(TEXT("Finisher impact gain is 1.0"), FinisherImpact, 1.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenShroudKnightSaveGameAdapter* SaveAdapter = NewObject<UAshenShroudKnightSaveGameAdapter>();
		SaveAdapter->PackageBossMetrics(true, 0.0f, 0.65f, 2);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		bool bDefeated = false;
		float FinalHealth = 1.0f;
		float MaxParanoia = 0.0f;
		int32 TrinityStrikes = 0;

		const bool bSuccess = SaveAdapter->RestoreBossMetrics(bDefeated, FinalHealth, MaxParanoia, TrinityStrikes);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("Boss defeated is true"), bDefeated);
		TestNearlyEqual(TEXT("Final health is 0.0"), FinalHealth, 0.0f, 0.01f);
		TestNearlyEqual(TEXT("Max paranoia is 0.65"), MaxParanoia, 0.65f, 0.01f);
		TestEqual(TEXT("Trinity strikes landed is 2"), TrinityStrikes, 2);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
