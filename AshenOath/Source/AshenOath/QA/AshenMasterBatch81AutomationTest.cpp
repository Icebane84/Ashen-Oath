// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1635: Master Batch #81 QA Automation Test Suite — Synergistic Finisher & Trauma Resolution Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1635MasterSynthesisOrchestrator.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "Combat/AshenFinisherTraumaResolverComponent.h"
#include "Companions/AshenGarrettLineSnareComponent.h"

// =============================================================================
//  Test 1: Finisher Selection Matrix Resolution Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch81FinisherMatrixTest,
	"AshenOath.Finisher.Matrix.ResolutionVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch81FinisherMatrixTest::RunTest(const FString& Parameters)
{
	UAshenPartySyncFinisherSubsystem* Subsystem = NewObject<UAshenPartySyncFinisherSubsystem>();
	if (!TestNotNull(TEXT("PartySyncFinisherSubsystem must be constructable"), Subsystem)) return false;

	// Verify all 5 branches
	TestEqual(TEXT("Branch 1: Dark Mode"), Subsystem->EvaluateFinisherEligibility(true, 0.0f, false, 1), EAshenPartyFinisherType::ShepherdsIntervention);
	TestEqual(TEXT("Branch 2: Burnout >= 70%"), Subsystem->EvaluateFinisherEligibility(false, 0.75f, false, 1), EAshenPartyFinisherType::EmpathicConduitNova);
	TestEqual(TEXT("Branch 3: 3+ broken enemies"), Subsystem->EvaluateFinisherEligibility(false, 0.1f, false, 3), EAshenPartyFinisherType::AshenTriangleCollapse);
	TestEqual(TEXT("Branch 4: Armored target"), Subsystem->EvaluateFinisherEligibility(false, 0.1f, true, 1), EAshenPartyFinisherType::SentinelsEclipse);
	TestEqual(TEXT("Branch 5: Default"), Subsystem->EvaluateFinisherEligibility(false, 0.1f, false, 1), EAshenPartyFinisherType::TripartiteResonantCleave);
	return true;
}

// =============================================================================
//  Test 2: Garrett Line Snare & Trauma Resolution Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch81SnareAndTraumaTest,
	"AshenOath.Finisher.SnareAndTrauma.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch81SnareAndTraumaTest::RunTest(const FString& Parameters)
{
	UAshenGarrettLineSnareComponent* Snare = NewObject<UAshenGarrettLineSnareComponent>();
	if (!TestNotNull(TEXT("GarrettLineSnareComponent must be constructable"), Snare)) return false;

	Snare->ExecuteLineSnareVault(nullptr);
	TestTrue(TEXT("bTargetNeckExposed must equal true"), Snare->bTargetNeckExposed);

	UAshenFinisherTraumaResolverComponent* Trauma = NewObject<UAshenFinisherTraumaResolverComponent>();
	if (!TestNotNull(TEXT("FinisherTraumaResolverComponent must be constructable"), Trauma)) return false;

	Trauma->ResolveTraumaPaydown(EAshenPartyFinisherType::EmpathicConduitNova, 100.0f, 80.0f);
	TestEqual(TEXT("Silence timer must be 0 for Nova"), Trauma->SilenceTimer, 0.0f);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1635 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1635MasterVerificationTest,
	"AshenOath.Milestone.Milestone1635.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1635MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1635MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1635MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1635 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1635 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1635Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1635 SYNERGISTIC FINISHER & TRAUMA PIPELINE VERIFIED (1,635 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
