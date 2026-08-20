// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1480: Unreliable Narrator Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1480SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1480UnreliableNarratorAutomationTest,
	"AshenOath.QA.UnreliableNarrator.Milestone1480Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1480UnreliableNarratorAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1480SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1480SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1480 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1480 validation must return true"), Orchestrator->ValidateMilestone1480Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1480 UNRELIABLE NARRATOR SUITE VERIFIED ======"));
	return true;
}
