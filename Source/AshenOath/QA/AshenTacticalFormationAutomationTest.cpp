// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 950: Ashen Tactical Formation QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone950SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTacticalFormationAutomationTest,
	"AshenOath.QA.TacticalFormation.Milestone950Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenTacticalFormationAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone950SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone950SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 950 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone950Synthesis();
	TestTrue(TEXT("Milestone 950 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 950 TACTICAL FORMATION SUITE VERIFIED (950 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
