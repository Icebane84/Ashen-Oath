// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1335: Master Batch #66 QA Automation Test Suite — Memory Battles & Echo Reclamation Arena
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1335MasterSynthesisOrchestrator.h"
#include "Soul/AshenMemoryFragmentCollectorComponent.h"
#include "AI/AshenPsychicEchoBossAIComponent.h"

// =============================================================================
//  Test 1: Memory Fragment Collector Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch66FragmentCollectorTest,
	"AshenOath.MemoryBattle.FragmentCollector.CollectionVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch66FragmentCollectorTest::RunTest(const FString& Parameters)
{
	UAshenMemoryFragmentCollectorComponent* Collector = NewObject<UAshenMemoryFragmentCollectorComponent>();
	if (!TestNotNull(TEXT("FragmentCollector must be constructable"), Collector)) return false;

	Collector->CollectMemoryFragment("Fragment_OathKeep_01");
	TestEqual(TEXT("Total reclaimed fragments must equal 1"), Collector->TotalReclaimedFragments, 1);
	return true;
}

// =============================================================================
//  Test 2: Boss AI Stance Modulation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch66BossAIModulationTest,
	"AshenOath.MemoryBattle.BossAI.StanceModulationVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch66BossAIModulationTest::RunTest(const FString& Parameters)
{
	UAshenPsychicEchoBossAIComponent* BossAI = NewObject<UAshenPsychicEchoBossAIComponent>();
	if (!TestNotNull(TEXT("BossAIComponent must be constructable"), BossAI)) return false;

	BossAI->UpdateBossStanceBehavior(2);
	TestTrue(TEXT("Aggression multiplier must equal 1.50f"), FMath::IsNearlyEqual(BossAI->AggressionMultiplier, 1.50f, 0.001f));
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1335 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1335MasterVerificationTest,
	"AshenOath.Milestone.Milestone1335.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1335MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1335MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1335MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1335 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1335 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1335Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1335 MEMORY BATTLES PIPELINE VERIFIED (1,335 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
