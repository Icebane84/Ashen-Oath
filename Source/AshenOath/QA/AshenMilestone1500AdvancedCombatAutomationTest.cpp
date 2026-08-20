// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1500: Advanced Combat Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1500SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1500AdvancedCombatAutomationTest,
	"AshenOath.QA.AdvancedCombat.Milestone1500Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1500AdvancedCombatAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1500SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1500SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1500 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1500 validation must return true"), Orchestrator->ValidateMilestone1500Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1500 ADVANCED COMBAT SUITE VERIFIED ======"));
	return true;
}
