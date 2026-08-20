// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1390: Execution Flourish Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1390SynthesisOrchestrator.h"
#include "Combat/AshenPsychologicalFinisherImpactComponent.h"
#include "Combat/AshenStaggerStateEvaluatorComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1390ExecutionAutomationTest,
	"AshenOath.QA.ExecutionFlourish.Milestone1390Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1390ExecutionAutomationTest::RunTest(const FString& Parameters)
{
	UAshenPsychologicalFinisherImpactComponent* ImpactComp = NewObject<UAshenPsychologicalFinisherImpactComponent>();
	if (!TestNotNull(TEXT("ImpactComponent must be constructable"), ImpactComp)) return false;

	const float DebtRed = ImpactComp->ProcessExecutionDebtReduction();
	TestTrue(TEXT("Debt reduction must equal 0.15f"), FMath::IsNearlyEqual(DebtRed, 0.15f, 0.001f));

	UAshenStaggerStateEvaluatorComponent* StaggerComp = NewObject<UAshenStaggerStateEvaluatorComponent>();
	if (!TestNotNull(TEXT("StaggerComponent must be constructable"), StaggerComp)) return false;

	StaggerComp->TriggerExecutionStaggerWindow(3.0f);
	TestTrue(TEXT("Enemy must be staggered for execution"), StaggerComp->bIsStaggeredForExecution);

	UAshenMilestone1390SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1390SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1390 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1390 validation must return true"), Orchestrator->ValidateMilestone1390Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1390 EXECUTION FLOURISH SUITE VERIFIED ======"));
	return true;
}
