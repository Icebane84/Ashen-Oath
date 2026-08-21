// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "Scenarios/AshenScenario4MissionSubsystem.h"
#include "Scenarios/AshenCompanionGroundingEvaluatorComponent.h"
#include "Scenarios/AshenSanityChromaticEvaluatorComponent.h"
#include "Scenarios/AshenScenario4HapticBridge.h"
#include "Core/AshenScenario4SaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch129AutomationTest,
	"AshenOath.Scenarios.MasterBatch129_Scenario4Whisperwood",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch129AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST COMPANION GROUNDING EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario4MissionSubsystem* MissionSubsystem = NewObject<UAshenScenario4MissionSubsystem>();
		UAshenCompanionGroundingEvaluatorComponent* GroundingEvaluator = NewObject<UAshenCompanionGroundingEvaluatorComponent>();

		// Case A: Companion has LOS and is targeting -> Verified Physical Threat
		FCompanionGroundingVerificationContext RealContext;
		RealContext.PerceivedThreatId = FName(TEXT("Ghoul_Stalker_1"));
		RealContext.ThreatLocation = FVector(500.0f, 0.0f, 0.0f);
		RealContext.bCompanionHasLineOfSight = true;
		RealContext.bCompanionIsTargetingThreat = true;

		const ECompanionGroundingState RealResult = MissionSubsystem->PerformGroundingCheck(RealContext);
		TestEqual(TEXT("Real threat is verified"), RealResult, ECompanionGroundingState::VerifiedPhysicalThreat);

		// Case B: Companion is not targeting -> Invalidated Hallucination
		FCompanionGroundingVerificationContext PhantomContext;
		PhantomContext.PerceivedThreatId = FName(TEXT("Phantom_Shadow_1"));
		PhantomContext.ThreatLocation = FVector(500.0f, 0.0f, 0.0f);
		PhantomContext.bCompanionHasLineOfSight = true;
		PhantomContext.bCompanionIsTargetingThreat = false;

		const ECompanionGroundingState PhantomResult = MissionSubsystem->PerformGroundingCheck(PhantomContext);
		TestEqual(TEXT("Phantom mirage is invalidated"), PhantomResult, ECompanionGroundingState::InvalidatedHallucination);

		// Test Gaze Angle Alignment
		const FVector CompanionLoc(0.0f, 0.0f, 0.0f);
		const FVector CompanionForward(1.0f, 0.0f, 0.0f);
		const FVector InConeThreat(100.0f, 20.0f, 0.0f);  // ~11.3 deg (< 35 deg)
		const FVector OutConeThreat(100.0f, 150.0f, 0.0f); // ~56.3 deg (> 35 deg)

		TestTrue(TEXT("In-cone threat aligns with companion gaze"), GroundingEvaluator->EvaluateCompanionGazeAlignment(CompanionLoc, CompanionForward, InConeThreat, 35.0f));
		TestFalse(TEXT("Out-cone threat fails companion gaze alignment"), GroundingEvaluator->EvaluateCompanionGazeAlignment(CompanionLoc, CompanionForward, OutConeThreat, 35.0f));
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST SANITY CHROMATIC ABERRATION SCALING
	// -----------------------------------------------------------------------------------
	{
		UAshenSanityChromaticEvaluatorComponent* ChromaticEvaluator = NewObject<UAshenSanityChromaticEvaluatorComponent>();

		// Full Sanity (1.0) -> 0.0 Aberration
		const float FullSanityAberration = ChromaticEvaluator->EvaluateChromaticAberration(1.0f);
		TestNearlyEqual(TEXT("Sanity 1.0 has 0.0 Chromatic Aberration"), FullSanityAberration, 0.0f, 0.01f);

		// Zero Sanity (0.0) -> 5.0 Aberration
		const float ZeroSanityAberration = ChromaticEvaluator->EvaluateChromaticAberration(0.0f);
		TestNearlyEqual(TEXT("Sanity 0.0 has 5.0 Chromatic Aberration"), ZeroSanityAberration, 5.0f, 0.01f);

		// Half Sanity (0.50) -> 2.50 Aberration
		const float HalfSanityAberration = ChromaticEvaluator->EvaluateChromaticAberration(0.50f);
		TestNearlyEqual(TEXT("Sanity 0.50 has 2.50 Chromatic Aberration"), HalfSanityAberration, 2.50f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST TOUCHPAD SOOT WIPING & COGNITIVE LOCI
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario4MissionSubsystem* MissionSubsystem = NewObject<UAshenScenario4MissionSubsystem>();

		// Initial Soot Opacity is 0.60
		TestNearlyEqual(TEXT("Initial soot opacity is 0.60"), MissionSubsystem->GetSootOpacity(), 0.60f, 0.01f);

		// Wipe 0.35 -> Remaining 0.25
		MissionSubsystem->WipeSoot(0.35f);
		TestNearlyEqual(TEXT("Remaining soot opacity is 0.25"), MissionSubsystem->GetSootOpacity(), 0.25f, 0.01f);

		// Discover Loci
		MissionSubsystem->DiscoverCognitiveLocus(FName(TEXT("Locus_BruisedSky")));
		TestEqual(TEXT("Discovered loci count is 1"), MissionSubsystem->GetDiscoveredLociCount(), 1);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE TOUCHPAD HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario4HapticBridge* HapticBridge = NewObject<UAshenScenario4HapticBridge>();

		const float Intensity = HapticBridge->EvaluateSootSwipeHapticIntensity(0.80f, 0.50f);
		// Base: 0.80 * 0.50 = 0.40, Grit: 0.50 * 0.40 = 0.20 -> Total = 0.60
		TestNearlyEqual(TEXT("Soot swipe haptic intensity is 0.60"), Intensity, 0.60f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario4SaveGameAdapter* SaveAdapter = NewObject<UAshenScenario4SaveGameAdapter>();

		SaveAdapter->PackageScenario4State(true, 3, 0.85f);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		bool bCleared = false;
		int32 LociCount = 0;
		float RestoredSanity = 0.0f;
		const bool bSuccess = SaveAdapter->RestoreScenario4State(bCleared, LociCount, RestoredSanity);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("bCleared is true"), bCleared);
		TestEqual(TEXT("Loci count is 3"), LociCount, 3);
		TestNearlyEqual(TEXT("Restored sanity is 0.85"), RestoredSanity, 0.85f, 0.01f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
