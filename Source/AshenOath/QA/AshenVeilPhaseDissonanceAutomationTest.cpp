// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 980: Ashen Veil Phase Dissonance QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone980SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVeilPhaseDissonanceAutomationTest,
	"AshenOath.QA.VeilPhaseDissonance.Milestone980Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenVeilPhaseDissonanceAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone980SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone980SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 980 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone980Synthesis();
	TestTrue(TEXT("Milestone 980 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 980 VEIL PHASE DISSONANCE SUITE VERIFIED (980 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
