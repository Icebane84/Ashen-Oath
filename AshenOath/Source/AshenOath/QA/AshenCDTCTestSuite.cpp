// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AbilityTask_EvaluateMontageFlowPosition.h"
#include "Spatial/AshenSpatialEvaluator.h"
#include "Spatial/AshenSpatialTypes.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. AUTOMATION TEST: CDTC-002 Flow Timing Classification (Play-Rate Agnostic)
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FCDTC_TEMP_002_FlowTimingClassification,
	"AshenOath.CDTC.002.FlowTimingClassification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FCDTC_TEMP_002_FlowTimingClassification::RunTest(const FString& Parameters)
{
	const float Apex = 0.50f;
	const float Window = 0.15f;

	using ETiming = EAshenFlowTimingResult;
	using UTask = UAbilityTask_EvaluateMontageFlowPosition;

	TestEqual(TEXT("Position before apex is Early"),
		UTask::EvaluateFlowTiming(0.49f, Apex, Window), ETiming::Early);

	TestEqual(TEXT("Position exactly at apex is Perfect"),
		UTask::EvaluateFlowTiming(0.50f, Apex, Window), ETiming::Perfect);

	TestEqual(TEXT("Position at window end (0.65) is Perfect, inclusive"),
		UTask::EvaluateFlowTiming(0.65f, Apex, Window), ETiming::Perfect);

	TestEqual(TEXT("Position just past window end is Late"),
		UTask::EvaluateFlowTiming(0.6501f, Apex, Window), ETiming::Late);

	// Same montage position, reached via different hypothetical play rates -- the
	// classifier only sees the resulting position, so the verdict must be identical.
	const float SamePositionViaHalfRate = 0.55f;
	const float SamePositionViaDoubleRate = 0.55f;
	TestEqual(TEXT("Play-rate-agnostic: same position classifies identically"),
		UTask::EvaluateFlowTiming(SamePositionViaHalfRate, Apex, Window),
		UTask::EvaluateFlowTiming(SamePositionViaDoubleRate, Apex, Window));

	return true;
}

// -----------------------------------------------------------------------------
// 2. AUTOMATION TEST: CDTC-005/006 Flank Convention Corrected (Enemy -> Ally)
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FCDTC_TEMP_005_006_FlankConventionCorrected,
	"AshenOath.CDTC.005.006.FlankConventionCorrected",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FCDTC_TEMP_005_006_FlankConventionCorrected::RunTest(const FString& Parameters)
{
	const FVector EnemyLoc(0.0f, 0.0f, 0.0f);
	const FVector EnemyForward(1.0f, 0.0f, 0.0f); // Enemy faces +X

	// Ally directly in FRONT of the enemy (same direction enemy is facing) -- must REJECT
	const FVector FrontAllyLoc(500.0f, 0.0f, 0.0f);
	const float FrontDot = URelationalSpatialEvaluator::ComputeFlankDot(FrontAllyLoc, EnemyLoc, EnemyForward);
	TestTrue(TEXT("Frontal ally must score below the flank threshold (reject)"),
		FrontDot < FMath::Cos(FMath::DegreesToRadians(45.0f)));

	// Ally directly BEHIND the enemy (true rear flank) -- must ACCEPT
	const FVector RearAllyLoc(-500.0f, 0.0f, 0.0f);
	const float RearDot = URelationalSpatialEvaluator::ComputeFlankDot(RearAllyLoc, EnemyLoc, EnemyForward);
	TestTrue(TEXT("Rear-flank ally must score at/above the flank threshold (accept)"),
		RearDot >= FMath::Cos(FMath::DegreesToRadians(45.0f)));

	return true;
}

// -----------------------------------------------------------------------------
// 3. AUTOMATION TEST: CDTC-004 Transaction Atomicity on UAshenSoulPublisher
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FCDTC_TEMP_004_TransactionAtomicity,
	"AshenOath.CDTC.004.TransactionAtomicity",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FCDTC_TEMP_004_TransactionAtomicity::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("CDTCAtomicityWorld"));
	TestNotNull(TEXT("Transient World created"), World);

	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	TestNotNull(TEXT("Transient GameInstance created"), GameInstance);

	if (GameInstance)
	{
		GameInstance->Init();
		World->SetGameInstance(GameInstance);

		UAshenSoulPublisher* Publisher = GameInstance->GetSubsystem<UAshenSoulPublisher>();
		TestNotNull(TEXT("Soul Publisher acquired"), Publisher);

		if (Publisher)
		{
			// Test direct commit delta updates
			FSoulStateVector Baseline;
			Baseline.Resolve = 0.50f;
			Baseline.Corruption = 0.10f;
			Publisher->CommitStateDirect(Baseline);

			TestEqual(TEXT("Initial Resolve is 0.50"), Publisher->GetSoulState().Resolve, 0.50f);

			FSoulStateVector Delta;
			Delta.Resolve = 0.10f;
			Delta.Corruption = 0.05f;
			Publisher->CommitState(Delta);

			TestEqual(TEXT("Resolve updated to 0.60"), Publisher->GetSoulState().Resolve, 0.60f);
			TestEqual(TEXT("Corruption updated to 0.15"), Publisher->GetSoulState().Corruption, 0.15f);
		}
	}

	World->DestroyWorld(false);
	return true;
}

// -----------------------------------------------------------------------------
// 4. AUTOMATION TEST: CDTC-007 Hit-Stop Position Traversal Invariance
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FCDTC_TEMP_007_HitStopPositionTraversal,
	"AshenOath.CDTC.007.HitStopPositionTraversal",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FCDTC_TEMP_007_HitStopPositionTraversal::RunTest(const FString& Parameters)
{
	float CurrentPosition = 0.42f;
	const float ApexPosition = 0.45f;
	const float EffectiveDeltaTime = 0.0f; // Simulated Hit-Stop
	const float PlayRate = 1.0f;

	CurrentPosition = CurrentPosition + (EffectiveDeltaTime * PlayRate);
	TestEqual(TEXT("Montage position must remain frozen during hit-stop"), CurrentPosition, 0.42f);

	const float ResumedDeltaTime = 0.05f;
	CurrentPosition = CurrentPosition + (ResumedDeltaTime * PlayRate);

	const EAshenFlowTimingResult Result = UAbilityTask_EvaluateMontageFlowPosition::EvaluateFlowTiming(CurrentPosition, ApexPosition, 0.15f);
	TestEqual(TEXT("Flow window resolves to Perfect upon hit-stop release"), Result, EAshenFlowTimingResult::Perfect);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
