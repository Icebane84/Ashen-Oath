// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1580: Elite Inquisition Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1580SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1580EliteInquisitionAutomationTest,
	"AshenOath.QA.EliteInquisition.Milestone1580Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1580EliteInquisitionAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1580SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1580SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1580 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1580 validation must return true"), Orchestrator->ValidateMilestone1580Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1580 ELITE INQUISITION SUITE VERIFIED ======"));
	return true;
}
