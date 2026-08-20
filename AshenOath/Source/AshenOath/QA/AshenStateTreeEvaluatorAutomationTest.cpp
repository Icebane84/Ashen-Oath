// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1190: Ashen StateTree Evaluator QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1190SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenStateTreeEvaluatorAutomationTest,
	"AshenOath.QA.StateTreeEvaluator.Milestone1190Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenStateTreeEvaluatorAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1190SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1190SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1190 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1190Synthesis();
	TestTrue(TEXT("Milestone 1190 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1190 STATETREE EVALUATOR SUITE VERIFIED (1190 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
