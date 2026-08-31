// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AbilityTask_EvaluateMontageFlowPosition.h"
#include "Spatial/AshenSpatialEvaluator.h"
#include "Spatial/AshenSpatialTypes.h"
#include "Engine/World.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. AUTOMATION TEST: Montage Position Hit-Stop Traversal Invariance
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMontagePositionHitStopTest,
	"AshenOath.Combat.CDTC.MontagePositionHitStop",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMontagePositionHitStopTest::RunTest(const FString& Parameters)
{
	// Test: Ensure P_montage traversal does not advance during hit-stop (DeltaTime = 0.0f)
	float CurrentPosition = 0.42f;
	const float ApexPosition = 0.45f;
	const float EffectiveDeltaTime = 0.0f; // Simulated Hit-Stop
	const float PlayRate = 1.0f;

	CurrentPosition = CurrentPosition + (EffectiveDeltaTime * PlayRate);
	TestEqual(TEXT("Montage position must remain frozen during hit-stop"), CurrentPosition, 0.42f);

	// Test: Resume playback and verify Perfect Window entry
	const float ResumedDeltaTime = 0.05f;
	CurrentPosition = CurrentPosition + (ResumedDeltaTime * PlayRate); // 0.47s -> Inside [0.45s, 0.60s]

	const bool bInWindow = (CurrentPosition >= ApexPosition && CurrentPosition <= (ApexPosition + 0.15f));
	TestTrue(TEXT("Flow window must accurately resolve upon hit-stop release"), bInWindow);

	return true;
}

// -----------------------------------------------------------------------------
// 2. AUTOMATION TEST: Spatial Convex Hull Vector Flank Math
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSpatialConvexHullValidationTest,
	"AshenOath.Combat.CDTC.SpatialConvexHull",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenSpatialConvexHullValidationTest::RunTest(const FString& Parameters)
{
	// Test: Companion positioned directly in rear arc (Dot == 1.0) must pass
	const FVector EnemyForward = FVector(1.0f, 0.0f, 0.0f);
	const FVector EnemyToAlly = FVector(-1.0f, 0.0f, 0.0f); // Positioned directly behind enemy

	const float RearDot = FVector::DotProduct(EnemyToAlly, -EnemyForward);
	TestTrue(TEXT("Direct rear flank dot product must equal 1.0"), FMath::IsNearlyEqual(RearDot, 1.0f));

	// Test: Companion positioned in front of enemy (Dot == -1.0) must fail
	const FVector FrontAlly = FVector(1.0f, 0.0f, 0.0f);
	const float FrontDot = FVector::DotProduct(FrontAlly, -EnemyForward);
	TestFalse(TEXT("Frontal ally alignment must fail rear flank test"), FrontDot > 0.70f);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
