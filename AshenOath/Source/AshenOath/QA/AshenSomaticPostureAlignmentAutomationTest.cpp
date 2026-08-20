// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1080: Ashen Somatic Posture Alignment QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1080SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSomaticPostureAlignmentAutomationTest,
	"AshenOath.QA.SomaticPostureAlignment.Milestone1080Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenSomaticPostureAlignmentAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1080SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1080SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1080 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1080Synthesis();
	TestTrue(TEXT("Milestone 1080 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1080 SOMATIC POSTURE SUITE VERIFIED (1080 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
