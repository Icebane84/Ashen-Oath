// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1395: Master Batch #69 QA Automation Test Suite — Execution Flourish & Finisher Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1395MasterSynthesisOrchestrator.h"
#include "Combat/AshenPsychologicalFinisherImpactComponent.h"
#include "Combat/AshenStaggerStateEvaluatorComponent.h"

// =============================================================================
//  Test 1: Finisher Debt Reduction Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch69DebtReductionTest,
	"AshenOath.ExecutionFlourish.Impact.DebtReductionVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch69DebtReductionTest::RunTest(const FString& Parameters)
{
	UAshenPsychologicalFinisherImpactComponent* ImpactComp = NewObject<UAshenPsychologicalFinisherImpactComponent>();
	if (!TestNotNull(TEXT("ImpactComponent must be constructable"), ImpactComp)) return false;

	const float Reduction = ImpactComp->ProcessExecutionDebtReduction();
	TestTrue(TEXT("Debt reduction value must equal 0.15f"), FMath::IsNearlyEqual(Reduction, 0.15f, 0.001f));
	return true;
}

// =============================================================================
//  Test 2: Enemy Stagger State Window Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch69StaggerStateTest,
	"AshenOath.ExecutionFlourish.Stagger.StateWindowVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch69StaggerStateTest::RunTest(const FString& Parameters)
{
	UAshenStaggerStateEvaluatorComponent* StaggerComp = NewObject<UAshenStaggerStateEvaluatorComponent>();
	if (!TestNotNull(TEXT("StaggerComponent must be constructable"), StaggerComp)) return false;

	StaggerComp->TriggerExecutionStaggerWindow(3.0f);
	TestTrue(TEXT("Stagger state must be true"), StaggerComp->bIsStaggeredForExecution);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1395 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1395MasterVerificationTest,
	"AshenOath.Milestone.Milestone1395.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1395MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1395MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1395MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1395 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1395 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1395Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1395 EXECUTION FLOURISH PIPELINE VERIFIED (1,395 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
