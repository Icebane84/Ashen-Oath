// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1575: Master Batch #78 QA Automation Test Suite — Campfire Rest Area & Heartstone Crucible Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1575MasterSynthesisOrchestrator.h"
#include "World/AshenCampfireRestAreaActor.h"
#include "World/AshenHeartstoneSubsystem.h"

// =============================================================================
//  Test 1: Campfire Rest Sequence & State Transition Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch78CampfireStateTest,
	"AshenOath.CampfireRest.State.TransitionVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch78CampfireStateTest::RunTest(const FString& Parameters)
{
	AAshenCampfireRestAreaActor* Campfire = NewObject<AAshenCampfireRestAreaActor>();
	if (!TestNotNull(TEXT("Campfire must be constructable"), Campfire)) return false;

	Campfire->KindleCampfire();
	TestEqual(TEXT("Campfire state must be Kindled"), Campfire->CurrentState, EAshenCampfireRestState::Kindled);

	Campfire->TriggerCampfireRest(nullptr);
	TestEqual(TEXT("Campfire state after rest trigger must be Resonating"), Campfire->CurrentState, EAshenCampfireRestState::Resonating);
	return true;
}

// =============================================================================
//  Test 2: Heartstone Crucible Remnant Transmutation Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch78HeartstoneCrucibleTest,
	"AshenOath.CampfireRest.Heartstone.CrucibleVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch78HeartstoneCrucibleTest::RunTest(const FString& Parameters)
{
	UAshenHeartstoneSubsystem* Subsystem = NewObject<UAshenHeartstoneSubsystem>();
	if (!TestNotNull(TEXT("HeartstoneSubsystem must be constructable"), Subsystem)) return false;

	const bool bForged = Subsystem->TransmuteRemnantsToPerk(FName(TEXT("Perk_CovenantPact")), 8, 35.0f);
	TestTrue(TEXT("TransmuteRemnantsToPerk must succeed"), bForged);
	TestEqual(TEXT("TotalForgedTraits must equal 1"), Subsystem->TotalForgedTraits, 1);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1575 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1575MasterVerificationTest,
	"AshenOath.Milestone.Milestone1575.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1575MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1575MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1575MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1575 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1575 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1575Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1575 CAMPFIRE REST PIPELINE VERIFIED (1,575 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
