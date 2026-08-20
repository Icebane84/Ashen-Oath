// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1440: Garrett Tactical Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1440SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1440GarrettTacticalAutomationTest,
	"AshenOath.QA.GarrettTactical.Milestone1440Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1440GarrettTacticalAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1440SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1440SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1440 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1440 validation must return true"), Orchestrator->ValidateMilestone1440Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1440 GARRETT TACTICAL SUITE VERIFIED ======"));
	return true;
}
