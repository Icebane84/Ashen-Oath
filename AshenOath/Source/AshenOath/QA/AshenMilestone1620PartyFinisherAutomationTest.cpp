// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1620: Party Finisher Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1620SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1620PartyFinisherAutomationTest,
	"AshenOath.QA.PartyFinisher.Milestone1620Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1620PartyFinisherAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1620SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1620SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1620 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1620 validation must return true"), Orchestrator->ValidateMilestone1620Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1620 PARTY FINISHER SUITE VERIFIED ======"));
	return true;
}
