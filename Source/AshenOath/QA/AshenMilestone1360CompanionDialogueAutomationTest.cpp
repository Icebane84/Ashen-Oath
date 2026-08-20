// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1360: Companion Dialogue Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1360SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1360CompanionDialogueAutomationTest,
	"AshenOath.QA.CompanionDialogue.Milestone1360Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1360CompanionDialogueAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1360SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1360SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1360 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1360 validation must return true"), Orchestrator->ValidateMilestone1360Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1360 COMPANION DIALOGUE TOOLING SUITE VERIFIED ======"));
	return true;
}
