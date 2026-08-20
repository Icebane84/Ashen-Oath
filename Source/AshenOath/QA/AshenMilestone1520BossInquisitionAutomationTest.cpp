// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1520: Boss Inquisition Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1520SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1520BossInquisitionAutomationTest,
	"AshenOath.QA.BossInquisition.Milestone1520Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1520BossInquisitionAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1520SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1520SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1520 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1520 validation must return true"), Orchestrator->ValidateMilestone1520Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1520 BOSS INQUISITION SUITE VERIFIED ======"));
	return true;
}
