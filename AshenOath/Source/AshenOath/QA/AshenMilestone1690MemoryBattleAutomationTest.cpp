// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1690: Memory Battle Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1690SynthesisOrchestrator.h"
#include "Memory/AshenMemoryBattleSubsystem.h"
#include "Memory/AshenPsychicEchoResolverComponent.h"
#include "World/AshenLorekeeperMemoryBeaconActor.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1690MemoryBattleAutomationTest,
	"AshenOath.QA.MemoryBattle.Milestone1690Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1690MemoryBattleAutomationTest::RunTest(const FString& Parameters)
{
	// Test 1: Memory Battle Lifecycle
	UAshenMemoryBattleSubsystem* BattleSubsystem = NewObject<UAshenMemoryBattleSubsystem>();
	if (!TestNotNull(TEXT("MemoryBattleSubsystem must be constructable"), BattleSubsystem)) return false;

	BattleSubsystem->InitiateMemoryBattle(FName(TEXT("Echo_SilentSpire")), 0.75f, false);
	TestTrue(TEXT("bIsMemoryBattleActive must equal true"), BattleSubsystem->bIsMemoryBattleActive);
	TestEqual(TEXT("ActiveEchoID must equal Echo_SilentSpire"), BattleSubsystem->ActiveEchoID, FName(TEXT("Echo_SilentSpire")));

	BattleSubsystem->ConcludeMemoryBattle(true);
	TestFalse(TEXT("bIsMemoryBattleActive must equal false"), BattleSubsystem->bIsMemoryBattleActive);

	// Test 2: Psychic Echo Resolution
	UAshenPsychicEchoResolverComponent* ResolverComp = NewObject<UAshenPsychicEchoResolverComponent>();
	if (!TestNotNull(TEXT("PsychicEchoResolverComponent must be constructable"), ResolverComp)) return false;

	float Reward = ResolverComp->ResolvePsychicEcho(FName(TEXT("Echo_SilentSpire")), 0.75f, true);
	TestTrue(TEXT("Reward must be greater than 0"), Reward > 0.0f);

	UAshenMilestone1690SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1690SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1690 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1690 validation must return true"), Orchestrator->ValidateMilestone1690Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1690 MEMORY BATTLE SUITE VERIFIED ======"));
	return true;
}
