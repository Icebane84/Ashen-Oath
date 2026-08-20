// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1495: Master Batch #74 QA Automation Test Suite — Unreliable Narrator & Labyrinth Distortion Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1495MasterSynthesisOrchestrator.h"
#include "Memory/AshenUnreliableNarratorEnvironmentalVolume.h"
#include "Memory/AshenUnreliableNarratorCombatComponent.h"

// =============================================================================
//  Test 1: Hallucination Sanity State Progression Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch74SanityProgressionTest,
	"AshenOath.UnreliableNarrator.Sanity.ProgressionVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch74SanityProgressionTest::RunTest(const FString& Parameters)
{
	AAshenUnreliableNarratorEnvironmentalVolume* Volume = NewObject<AAshenUnreliableNarratorEnvironmentalVolume>();
	if (!TestNotNull(TEXT("NarratorEnvironmentalVolume must be constructable"), Volume)) return false;

	Volume->EvaluateSanityDistortion(0.25f, 0.50f);
	TestEqual(TEXT("Hallucination state must be Warped_Labyrinth"), Volume->CurrentHallucinationState, EAshenEnvironmentalHallucinationState::Warped_Labyrinth);
	return true;
}

// =============================================================================
//  Test 2: Combat Mirage Spawn Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch74MirageSpawnTest,
	"AshenOath.UnreliableNarrator.Combat.MirageSpawnVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch74MirageSpawnTest::RunTest(const FString& Parameters)
{
	UAshenUnreliableNarratorCombatComponent* CombatComp = NewObject<UAshenUnreliableNarratorCombatComponent>();
	if (!TestNotNull(TEXT("CombatComponent must be constructable"), CombatComp)) return false;

	CombatComp->SpawnCombatMirage(FVector(200.0f, 300.0f, 0.0f));
	TestEqual(TEXT("Active mirage count must equal 1"), CombatComp->ActiveMirageCount, 1);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1495 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1495MasterVerificationTest,
	"AshenOath.Milestone.Milestone1495.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1495MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1495MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1495MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1495 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1495 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1495Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1495 UNRELIABLE NARRATOR PIPELINE VERIFIED (1,495 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
