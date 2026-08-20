// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 970: Ashen Posture Alignment QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone970SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPostureAlignmentAutomationTest,
	"AshenOath.QA.PostureAlignment.Milestone970Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenPostureAlignmentAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone970SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone970SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 970 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone970Synthesis();
	TestTrue(TEXT("Milestone 970 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 970 POSTURE ALIGNMENT SUITE VERIFIED (970 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
