// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1700: Character Finisher GAS Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1700SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1700CharacterFinisherAutomationTest,
	"AshenOath.QA.CharacterFinisherGAS.Milestone1700Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1700CharacterFinisherAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1700SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1700SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1700 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1700 validation must return true"), Orchestrator->ValidateMilestone1700Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1700 CHARACTER FINISHER GAS SUITE VERIFIED ======"));
	return true;
}
