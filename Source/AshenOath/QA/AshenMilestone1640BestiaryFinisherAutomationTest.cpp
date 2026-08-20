// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1640: Bestiary Finisher Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1640SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1640BestiaryFinisherAutomationTest,
	"AshenOath.QA.BestiaryFinisher.Milestone1640Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1640BestiaryFinisherAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1640SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1640SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1640 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1640 validation must return true"), Orchestrator->ValidateMilestone1640Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1640 BESTIARY FINISHER SUITE VERIFIED ======"));
	return true;
}
