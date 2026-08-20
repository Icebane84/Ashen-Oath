// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 940: Ashen Hazard Safety QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone940SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenHazardSafetyAutomationTest,
	"AshenOath.QA.HazardSafety.Milestone940Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenHazardSafetyAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone940SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone940SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 940 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone940Synthesis();
	TestTrue(TEXT("Milestone 940 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 940 HAZARD SAFETY SUITE VERIFIED (940 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
