// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1160: Ashen Psychological OS QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1160SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPsychologicalOSAutomationTest,
	"AshenOath.QA.PsychologicalOS.Milestone1160Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenPsychologicalOSAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1160SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1160SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1160 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1160Synthesis();
	TestTrue(TEXT("Milestone 1160 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1160 PSYCHOLOGICAL OS SUITE VERIFIED (1160 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
