// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1530: Boss Inquisition Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1530SynthesisOrchestrator.h"
#include "AI/AIC_BrotherMalakor.h"
#include "Combat/AshenEldrinMemoryDuelTransitionComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1530BossInquisitionAutomationTest,
	"AshenOath.QA.BossInquisition.Milestone1530Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1530BossInquisitionAutomationTest::RunTest(const FString& Parameters)
{
	AAIC_BrotherMalakor* BossAI = NewObject<AAIC_BrotherMalakor>();
	if (!TestNotNull(TEXT("BossAI must be constructable"), BossAI)) return false;

	BossAI->EvaluatePhaseProgression(0.30f);
	TestEqual(TEXT("Boss phase at 30% health must be Phase3_MartyrAvenger"), BossAI->CurrentBossPhase, EAshenBossPhase::Phase3_MartyrAvenger);

	UAshenEldrinMemoryDuelTransitionComponent* DuelComp = NewObject<UAshenEldrinMemoryDuelTransitionComponent>();
	if (!TestNotNull(TEXT("MemoryDuelTransitionComponent must be constructable"), DuelComp)) return false;

	TestTrue(TEXT("Memory duel transition must initiate"), DuelComp->InitiateMemoryDuelTransition(FVector(100.0f, 200.0f, 0.0f)));
	TestTrue(TEXT("bIsInMindscapeArena must equal true"), DuelComp->bIsInMindscapeArena);

	UAshenMilestone1530SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1530SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1530 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1530 validation must return true"), Orchestrator->ValidateMilestone1530Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1530 BOSS INQUISITION SUITE VERIFIED ======"));
	return true;
}
