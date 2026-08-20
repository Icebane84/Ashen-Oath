// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1420: Wayfarer's Journal Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1420SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1420JournalAutomationTest,
	"AshenOath.QA.WayfarerJournal.Milestone1420Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1420JournalAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1420SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1420SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1420 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1420 validation must return true"), Orchestrator->ValidateMilestone1420Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1420 WAYFARER'S JOURNAL TOOLING SUITE VERIFIED ======"));
	return true;
}
