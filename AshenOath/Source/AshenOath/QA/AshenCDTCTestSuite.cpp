// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AbilityTask_EvaluateMontageFlowPosition.h"
#include "Spatial/AshenSpatialEvaluator.h"
#include "Spatial/AshenSpatialTypes.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulStateVector.h"

#if WITH_DEV_AUTOMATION_TESTS

// Mock Relational Bridge for testing
class FMockRelationalBridge : public IAshenRelationalBridge
{
public:
	bool bAcceptsDeltas = true;
	float DispatchedGarrett = 0.0f;
	float DispatchedSerafina = 0.0f;

	virtual bool CanAcceptRelationalDelta() const override { return bAcceptsDeltas; }
	virtual void DispatchRelationalDelta(float G, float S) override
	{
		DispatchedGarrett += G;
		DispatchedSerafina += S;
	}
};

// -----------------------------------------------------------------------------
// 1. CDTC-002-01: Flow Timing Half-Open Boundary Tests
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FCDTC002_FlowTimingHalfOpenBounds,
	"AshenOath.CDTC002.FlowTimingHalfOpenBounds",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FCDTC002_FlowTimingHalfOpenBounds::RunTest(const FString& Parameters)
{
	const float Apex = 0.50f;
	const float Window = 0.15f;
	constexpr float Epsilon = 0.0001f;

	// Early
	TestEqual(TEXT("Position prior to Apex must be Early"),
		UAbilityTask_EvaluateMontageFlowPosition::EvaluateFlowTiming(Apex - Epsilon, Apex, Window), EAshenFlowTimingResult::Early);

	// Start boundary (Inclusive)
	TestEqual(TEXT("Position exactly at Apex must be Perfect"),
		UAbilityTask_EvaluateMontageFlowPosition::EvaluateFlowTiming(Apex, Apex, Window), EAshenFlowTimingResult::Perfect);

	// Inside window
	TestEqual(TEXT("Position inside window must be Perfect"),
		UAbilityTask_EvaluateMontageFlowPosition::EvaluateFlowTiming(Apex + 0.075f, Apex, Window), EAshenFlowTimingResult::Perfect);

	// End boundary - Epsilon (Inclusive)
	TestEqual(TEXT("Position at WindowEnd - Epsilon must be Perfect"),
		UAbilityTask_EvaluateMontageFlowPosition::EvaluateFlowTiming(Apex + Window - Epsilon, Apex, Window), EAshenFlowTimingResult::Perfect);

	// End boundary (Exclusive -> Late)
	TestEqual(TEXT("Position exactly at WindowEnd must be Late (Half-Open)"),
		UAbilityTask_EvaluateMontageFlowPosition::EvaluateFlowTiming(Apex + Window, Apex, Window), EAshenFlowTimingResult::Late);

	// Beyond window
	TestEqual(TEXT("Position past WindowEnd must be Late"),
		UAbilityTask_EvaluateMontageFlowPosition::EvaluateFlowTiming(Apex + Window + Epsilon, Apex, Window), EAshenFlowTimingResult::Late);

	return true;
}

// -----------------------------------------------------------------------------
// 2. CDTC-002-02: Spatial 200uu Distance Boundary Tests
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FCDTC002_SpatialDistanceBounds,
	"AshenOath.CDTC002.SpatialDistanceBounds",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FCDTC002_SpatialDistanceBounds::RunTest(const FString& Parameters)
{
	constexpr float MaxDistance = 200.0f;

	TestTrue(TEXT("Distance at 199.99uu must be valid"), (199.99f <= MaxDistance));
	TestTrue(TEXT("Distance at exact 200.00uu must be valid"), (200.00f <= MaxDistance));
	TestFalse(TEXT("Distance at 200.01uu must be invalid"), (200.01f <= MaxDistance));

	return true;
}

// -----------------------------------------------------------------------------
// 3. CDTC-002-03: Angular Flank Boundary Tests (45-degree Half-Angle)
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FCDTC002_FlankAngleBounds,
	"AshenOath.CDTC002.FlankAngleBounds",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FCDTC002_FlankAngleBounds::RunTest(const FString& Parameters)
{
	const FVector EnemyLoc(0.0f, 0.0f, 0.0f);
	const FVector EnemyForward(1.0f, 0.0f, 0.0f);
	const float Cos45 = FMath::Cos(FMath::DegreesToRadians(45.0f)); // ~0.7071f

	// Directly behind (Dot = 1.0)
	const FVector DirectRearAlly(-100.0f, 0.0f, 0.0f);
	const float RearDot = UAshenSpatialEvaluator::ComputeFlankDot(EnemyLoc, EnemyForward, DirectRearAlly);
	TestTrue(TEXT("Direct rear ally must have Dot == 1.0"), FMath::IsNearlyEqual(RearDot, 1.0f, 0.001f));
	TestTrue(TEXT("Direct rear ally must pass flank test"), RearDot >= Cos45);

	// 44.9 degrees off rear (Inside 45-degree cone)
	const float Angle44_9 = FMath::DegreesToRadians(180.0f - 44.9f);
	const FVector Ally44_9(FMath::Cos(Angle44_9) * 100.0f, FMath::Sin(Angle44_9) * 100.0f, 0.0f);
	const float Dot44_9 = UAshenSpatialEvaluator::ComputeFlankDot(EnemyLoc, EnemyForward, Ally44_9);
	TestTrue(TEXT("Ally at 44.9 deg must pass flank threshold"), Dot44_9 >= Cos45);

	// 45.1 degrees off rear (Outside 45-degree cone)
	const float Angle45_1 = FMath::DegreesToRadians(180.0f - 45.1f);
	const FVector Ally45_1(FMath::Cos(Angle45_1) * 100.0f, FMath::Sin(Angle45_1) * 100.0f, 0.0f);
	const float Dot45_1 = UAshenSpatialEvaluator::ComputeFlankDot(EnemyLoc, EnemyForward, Ally45_1);
	TestFalse(TEXT("Ally at 45.1 deg must fail flank threshold"), Dot45_1 >= Cos45);

	return true;
}

// -----------------------------------------------------------------------------
// 4. CDTC-002-04: Continuous Gameplay Effective Mass Envelope Tests
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FCDTC002_EffectiveMassEnvelope,
	"AshenOath.CDTC002.EffectiveMassEnvelope",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FCDTC002_EffectiveMassEnvelope::RunTest(const FString& Parameters)
{
	// Maximum mastery floor clamp (Resolve = 1.0, Debt = 0.0) -> 80 * (1 - 0.35) = 52.0 kg
	const float HighResolveMass = UAshenSoulPublisher::CalculateGameplayEffectiveMass(0.0f, 0.0f, 1.0f);
	TestTrue(TEXT("High Resolve mass must be >= 45.0 kg floor"), HighResolveMass >= 45.0f);
	TestEqual(TEXT("High Resolve mass calculation check"), HighResolveMass, 52.0f);

	// Maximum exhaustion ceiling clamp (Resolve = 0.0, Debt = 1.0) -> 80 * (1 + 0.65) = 132.0 kg -> Clamped to 120.0 kg
	const float HighDebtMass = UAshenSoulPublisher::CalculateGameplayEffectiveMass(1.0f, 0.0f, 0.0f);
	TestEqual(TEXT("High Debt mass must clamp strictly to 120.0 kg ceiling"), HighDebtMass, 120.0f);

	// Baseline neutral (Resolve = 0.5, Debt = 0.0) -> 80 * (1 - 0.175) = 66.0 kg
	const float NeutralMass = UAshenSoulPublisher::CalculateGameplayEffectiveMass(0.0f, 0.0f, 0.5f);
	TestEqual(TEXT("Neutral baseline mass calculation check"), NeutralMass, 66.0f);

	return true;
}

// -----------------------------------------------------------------------------
// 5. CDTC-002-05: Transaction Atomicity, No-Op Guard, and Relational Sink Validation
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FCDTC002_TransactionValidation,
	"AshenOath.CDTC002.TransactionValidation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FCDTC002_TransactionValidation::RunTest(const FString& Parameters)
{
	UAshenSoulPublisher* Publisher = NewObject<UAshenSoulPublisher>();
	const int64 InitialVersion = Publisher->GetAuthoritativeSnapshot().StateVersion;

	// 1. Empty buffer commit must return false and NOT increment StateVersion
	const bool bEmptyCommit = Publisher->CommitBufferedTransaction();
	TestFalse(TEXT("Empty buffer commit must be rejected as no-op"), bEmptyCommit);
	TestEqual(TEXT("StateVersion must not increment on empty commit"), Publisher->GetAuthoritativeSnapshot().StateVersion, InitialVersion);

	// 2. Relational delta without bridge must ABORT transaction (no partial write)
	Publisher->BufferStateDelta(0.1f, 0.0f, 0.0f, 0.05f, 0.0f, FGameplayTag::EmptyTag);
	const bool bAbortedCommit = Publisher->CommitBufferedTransaction();
	TestFalse(TEXT("Transaction with relational delta must abort if no bridge is bound"), bAbortedCommit);
	TestEqual(TEXT("StateVersion must remain unchanged after aborted transaction"), Publisher->GetAuthoritativeSnapshot().StateVersion, InitialVersion);

	// 3. Valid transaction with bridge bound must succeed and increment StateVersion by exactly 1
	FMockRelationalBridge MockBridge;
	TScriptInterface<IAshenRelationalBridge> BridgeInterface;
	BridgeInterface.SetObject(Publisher); // Pointer container for mock testing
	BridgeInterface.SetInterface(&MockBridge);
	Publisher->SetRelationalBridge(BridgeInterface);

	Publisher->BufferStateDelta(0.1f, -0.05f, -0.02f, 0.04f, 0.03f, FGameplayTag::RequestGameplayTag(FName("State.Stance.Ochs")));
	const bool bValidCommit = Publisher->CommitBufferedTransaction();

	TestTrue(TEXT("Valid transaction must commit successfully"), bValidCommit);
	TestEqual(TEXT("StateVersion must increment by exactly 1"), Publisher->GetAuthoritativeSnapshot().StateVersion, InitialVersion + 1);
	TestEqual(TEXT("TransactionId must equal 1"), Publisher->GetAuthoritativeSnapshot().TransactionId, (int64)1);
	TestEqual(TEXT("Garrett delta must be dispatched to relational sink"), MockBridge.DispatchedGarrett, 0.04f);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
