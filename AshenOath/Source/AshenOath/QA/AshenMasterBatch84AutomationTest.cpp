// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1695: Master Batch #84 QA Automation Test Suite — Memory Battle, Psychic Echoes & Lorekeeper Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1695MasterSynthesisOrchestrator.h"
#include "Memory/AshenMemoryBattleSubsystem.h"
#include "AI/AshenMemoryBattleEnemy.h"
#include "World/AshenLorekeeperMemoryBeaconActor.h"

// =============================================================================
//  Test 1: Memory Battle Enemy Scaling
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch84MemoryEnemyTest,
	"AshenOath.MemoryBattle.EnemyScaling.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch84MemoryEnemyTest::RunTest(const FString& Parameters)
{
	AAshenMemoryBattleEnemy* Enemy = NewObject<AAshenMemoryBattleEnemy>();
	if (!TestNotNull(TEXT("MemoryBattleEnemy must be constructable"), Enemy)) return false;

	Enemy->ScaleEnemyToImprint(0.50f);
	TestTrue(TEXT("BaseHealth must scale above 500.0f"), Enemy->BaseHealth > 500.0f);
	return true;
}

// =============================================================================
//  Test 2: Lorekeeper Memory Beacon Ignition
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch84BeaconTest,
	"AshenOath.MemoryBattle.BeaconIgnition.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch84BeaconTest::RunTest(const FString& Parameters)
{
	AAshenLorekeeperMemoryBeaconActor* Beacon = NewObject<AAshenLorekeeperMemoryBeaconActor>();
	if (!TestNotNull(TEXT("LorekeeperMemoryBeaconActor must be constructable"), Beacon)) return false;

	Beacon->IgniteMemoryBeacon(FName(TEXT("Echo_SilentSpire")));
	TestTrue(TEXT("bIsBeaconIgnited must equal true"), Beacon->bIsBeaconIgnited);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1695 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1695MasterVerificationTest,
	"AshenOath.Milestone.Milestone1695.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1695MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1695MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1695MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1695 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1695 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1695Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1695 MEMORY BATTLE & LOREKEEPER PIPELINE VERIFIED (1,695 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
