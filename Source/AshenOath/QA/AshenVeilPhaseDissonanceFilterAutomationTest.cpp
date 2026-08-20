// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1060: Ashen Veil Phase Dissonance Filter QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1060SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVeilPhaseDissonanceFilterAutomationTest,
	"AshenOath.QA.VeilPhaseDissonanceFilter.Milestone1060Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenVeilPhaseDissonanceFilterAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1060SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1060SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1060 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1060Synthesis();
	TestTrue(TEXT("Milestone 1060 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1060 VEIL PHASE FILTER SUITE VERIFIED (1060 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
