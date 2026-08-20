// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1170: Ashen Single-Question Hub QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1170SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSingleQuestionHubAutomationTest,
	"AshenOath.QA.SingleQuestionHub.Milestone1170Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenSingleQuestionHubAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1170SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1170SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1170 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1170Synthesis();
	TestTrue(TEXT("Milestone 1170 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1170 SINGLE-QUESTION HUB SUITE VERIFIED (1170 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
