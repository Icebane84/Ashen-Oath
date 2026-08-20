// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1400: Soul Rehabilitation Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1400SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1400SoulRehabilitationAutomationTest,
	"AshenOath.QA.SoulRehabilitation.Milestone1400Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1400SoulRehabilitationAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1400SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1400SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1400 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1400 validation must return true"), Orchestrator->ValidateMilestone1400Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1400 SOUL REHABILITATION TOOLING SUITE VERIFIED ======"));
	return true;
}
