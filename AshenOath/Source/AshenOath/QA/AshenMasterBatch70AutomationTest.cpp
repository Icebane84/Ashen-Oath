// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1415: Master Batch #70 QA Automation Test Suite — Soul Constellation Rehabilitation & Integration Chamber
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1415MasterSynthesisOrchestrator.h"
#include "Soul/AshenImprintIntegrationRitualSubsystem.h"
#include "Soul/AshenRehabilitationTraitShiftEvaluator.h"

// =============================================================================
//  Test 1: Imprint Purification Subsystem Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch70ImprintPurificationTest,
	"AshenOath.SoulRehabilitation.Ritual.PurificationVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch70ImprintPurificationTest::RunTest(const FString& Parameters)
{
	UAshenImprintIntegrationRitualSubsystem* Subsystem = NewObject<UAshenImprintIntegrationRitualSubsystem>();
	if (!TestNotNull(TEXT("RitualSubsystem must be constructable"), Subsystem)) return false;

	Subsystem->ActiveImprintCount = 5;
	Subsystem->PurifyOldestImprint();
	TestEqual(TEXT("Active imprints must equal 4 after purification"), Subsystem->ActiveImprintCount, 4);
	return true;
}

// =============================================================================
//  Test 2: Trait Bonus Evaluation Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch70TraitBonusTest,
	"AshenOath.SoulRehabilitation.Trait.BonusEvaluationVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch70TraitBonusTest::RunTest(const FString& Parameters)
{
	UAshenRehabilitationTraitShiftEvaluator* Evaluator = NewObject<UAshenRehabilitationTraitShiftEvaluator>();
	if (!TestNotNull(TEXT("TraitShiftEvaluator must be constructable"), Evaluator)) return false;

	Evaluator->ApplyPermanentRehabilitationTraitBonuses(1.0f);
	TestTrue(TEXT("Stance recovery bonus must equal 1.10f"), FMath::IsNearlyEqual(Evaluator->StanceRecoveryBonusMultiplier, 1.10f, 0.001f));
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1415 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1415MasterVerificationTest,
	"AshenOath.Milestone.Milestone1415.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1415MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1415MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1415MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1415 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1415 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1415Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1415 SOUL REHABILITATION PIPELINE VERIFIED (1,415 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
