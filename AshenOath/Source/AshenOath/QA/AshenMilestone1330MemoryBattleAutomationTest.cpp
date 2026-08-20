// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1330: Memory Battle Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1330SynthesisOrchestrator.h"
#include "Soul/AshenMemoryFragmentCollectorComponent.h"
#include "AI/AshenPsychicEchoPhasedPhaseController.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1330MemoryBattleAutomationTest,
	"AshenOath.QA.MemoryBattle.Milestone1330Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1330MemoryBattleAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMemoryFragmentCollectorComponent* Collector = NewObject<UAshenMemoryFragmentCollectorComponent>();
	if (!TestNotNull(TEXT("FragmentCollector must be constructable"), Collector)) return false;

	Collector->CollectMemoryFragment("Fragment_OathKeep");
	TestEqual(TEXT("Reclaimed count must equal 1"), Collector->TotalReclaimedFragments, 1);

	UAshenPsychicEchoPhasedPhaseController* PhaseCtrl = NewObject<UAshenPsychicEchoPhasedPhaseController>();
	if (!TestNotNull(TEXT("PhaseController must be constructable"), PhaseCtrl)) return false;

	PhaseCtrl->EvaluatePhaseTransition(0.20f);
	TestEqual(TEXT("Boss phase must equal 3 at 20% health"), PhaseCtrl->CurrentPhase, 3);

	UAshenMilestone1330SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1330SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1330 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1330 validation must return true"), Orchestrator->ValidateMilestone1330Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1330 MEMORY BATTLE SUITE VERIFIED ======"));
	return true;
}
