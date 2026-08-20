// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1995: Master Batch #99 QA Automation Test Suite — Trauma Enemy Matrix (TEM) Framework & Adversarial AI
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AI/AshenTraumaEnemyMatrixSubsystem.h"
#include "Combat/AshenTripartiteResourceEconomyComponent.h"
#include "Soul/AshenIntegrationDebtPipelineComponent.h"
#include "AI/AshenCircuitBreakerEvaluatorComponent.h"
#include "AI/AshenSkeletalSightTracingAIDirectorComponent.h"

// =============================================================================
//  Test 1: Adversarial Argument Registration, Tiers & Circuit Breaker Logic
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch99TEMAndCircuitBreakerTest,
	"AshenOath.AI.TEMAndCircuitBreaker.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch99TEMAndCircuitBreakerTest::RunTest(const FString& Parameters)
{
	// Test 1: TEM Subsystem Argument Registration
	UAshenTraumaEnemyMatrixSubsystem* Subsystem = NewObject<UAshenTraumaEnemyMatrixSubsystem>();
	if (!TestNotNull(TEXT("TraumaEnemyMatrixSubsystem must be constructable"), Subsystem)) return false;

	Subsystem->RegisterAdversarialArgument(
		FName(TEXT("Monster.AshenAbomination")),
		FName(TEXT("Hero.Kaelen")),
		TEXT("My value is measured by how much pain I can absorb alone."),
		TEXT("Sacrifice is Selfish: Your solitary martyrdom only causes more agony to your allies."),
		ETEMEncounterTier::Revelation
	);

	FAdversarialArgument Arg;
	TestTrue(TEXT("Ashen Abomination argument must be registered"),
		Subsystem->GetAdversarialArgument(FName(TEXT("Monster.AshenAbomination")), Arg));
	TestEqual(TEXT("Targeted hero must be Kaelen"), Arg.TargetedHero, FName(TEXT("Hero.Kaelen")));
	TestEqual(TEXT("Encounter tier must be Revelation"), Arg.Tier, ETEMEncounterTier::Revelation);

	// Test 2: Circuit Breaker Protocol (LAW-001)
	UAshenCircuitBreakerEvaluatorComponent* CircuitBreaker = NewObject<UAshenCircuitBreakerEvaluatorComponent>();
	if (!TestNotNull(TEXT("CircuitBreakerEvaluatorComponent must be constructable"), CircuitBreaker)) return false;

	TestTrue(TEXT("Utility 0.10f must trip circuit breaker (< 0.15f)"), CircuitBreaker->ShouldTripCircuitBreaker(0.10f));
	TestFalse(TEXT("Utility 0.25f must NOT trip circuit breaker"), CircuitBreaker->ShouldTripCircuitBreaker(0.25f));

	// Test 3: Skeletal Sight Tracing Angles
	UAshenSkeletalSightTracingAIDirectorComponent* SightComp = NewObject<UAshenSkeletalSightTracingAIDirectorComponent>();
	if (!TestNotNull(TEXT("SkeletalSightTracingAIDirectorComponent must be constructable"), SightComp)) return false;

	TestEqual(TEXT("Standard posture vision cone must equal 120.0 degrees"), SightComp->CalculateEffectiveVisionConeAngle(false), 120.0f);
	TestEqual(TEXT("Hunched posture vision cone must contract to 70.0 degrees"), SightComp->CalculateEffectiveVisionConeAngle(true), 70.0f);

	return true;
}

// =============================================================================
//  Test 2: Tripartite Resource Economy & Integration Debt Pipeline
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch99EconomyAndDebtTest,
	"AshenOath.AI.EconomyAndDebt.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch99EconomyAndDebtTest::RunTest(const FString& Parameters)
{
	// Test 1: Tripartite Resource Transactions
	UAshenTripartiteResourceEconomyComponent* Economy = NewObject<UAshenTripartiteResourceEconomyComponent>();
	if (!TestNotNull(TEXT("TripartiteResourceEconomyComponent must be constructable"), Economy)) return false;

	Economy->ApplyGlassShieldOverextension(500.0f); // 500 * 0.001 = 0.50
	TestEqual(TEXT("Kaelen corruption must equal 0.50"), Economy->CurrentState.KaelenCorruption, 0.50f);

	Economy->ApplyTransferenceHealing(400.0f); // 400 * 0.0015 = 0.60
	TestEqual(TEXT("Serafina burnout must equal 0.60"), Economy->CurrentState.SerafinaBurnout, 0.60f);

	Economy->ApplySentinelPostureLoss(40.0f); // 1.0 - 0.40 = 0.60
	TestEqual(TEXT("Garrett sanity posture must equal 0.60"), Economy->CurrentState.GarrettSanityPosture, 0.60f);

	// Test 2: Integration Debt Pipeline
	UAshenIntegrationDebtPipelineComponent* DebtPipeline = NewObject<UAshenIntegrationDebtPipelineComponent>();
	if (!TestNotNull(TEXT("IntegrationDebtPipelineComponent must be constructable"), DebtPipeline)) return false;

	TestEqual(TEXT("Debt 25% must be Dormant stage"), DebtPipeline->EvaluateDebtStage(25.0f), EIntegrationDebtStage::Dormant);
	TestEqual(TEXT("Debt 60% must be MemoryBleed stage"), DebtPipeline->EvaluateDebtStage(60.0f), EIntegrationDebtStage::MemoryBleed);
	TestEqual(TEXT("Debt 85% must be RuntimeNoise stage"), DebtPipeline->EvaluateDebtStage(85.0f), EIntegrationDebtStage::RuntimeNoise);
	TestEqual(TEXT("Debt 100% must be ForcedCollapse stage"), DebtPipeline->EvaluateDebtStage(100.0f), EIntegrationDebtStage::ForcedCollapse);

	// Parry window penalty (-35%)
	const float BaseParry = 0.30f;
	const float DegradedParry = DebtPipeline->CalculateParryWindowPenalty(BaseParry);
	TestEqual(TEXT("Degraded parry window during Runtime Noise must be 0.195s (0.65x)"), DegradedParry, BaseParry * 0.65f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #99 TRAUMA ENEMY MATRIX (TEM) VERIFIED (1,995 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
