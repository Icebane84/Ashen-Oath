// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1320: Memory Battle Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1320SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1320MemoryBattleAutomationTest,
	"AshenOath.QA.MemoryBattle.Milestone1320Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1320MemoryBattleAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1320SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1320SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1320 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1320 validation must return true"), Orchestrator->ValidateMilestone1320Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1320 MEMORY BATTLE TOOLING SUITE VERIFIED ======"));
	return true;
}
