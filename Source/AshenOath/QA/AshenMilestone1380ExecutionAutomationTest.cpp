// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1380: Execution Flourish Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1380SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1380ExecutionAutomationTest,
	"AshenOath.QA.ExecutionFlourish.Milestone1380Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1380ExecutionAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1380SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1380SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1380 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1380 validation must return true"), Orchestrator->ValidateMilestone1380Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1380 EXECUTION FLOURISH TOOLING SUITE VERIFIED ======"));
	return true;
}
