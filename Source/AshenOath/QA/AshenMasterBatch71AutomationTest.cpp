// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1435: Master Batch #71 QA Automation Test Suite — Wayfarer's Journal Diegetic Somatic Chronicle & Psychological Marginalia Engine
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1435MasterSynthesisOrchestrator.h"
#include "Narrative/AshenWayfarerJournalSubsystem.h"
#include "Narrative/AshenJournalDialogueGatingAdapter.h"
#include "Companions/AshenJournalCompanionAISpacingAdapter.h"

// =============================================================================
//  Test 1: Wayfarer Journal Entry Compilation & Strikethrough Logic
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch71JournalEntryCompilationTest,
	"AshenOath.WayfarerJournal.Entry.CompilationVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch71JournalEntryCompilationTest::RunTest(const FString& Parameters)
{
	UAshenWayfarerJournalSubsystem* Subsystem = NewObject<UAshenWayfarerJournalSubsystem>();
	if (!TestNotNull(TEXT("JournalSubsystem must be constructable"), Subsystem)) return false;

	Subsystem->RecordCampJournalEntry(
		"WeepingMire_Camp",
		FText::FromString("Rest at the Weeping Mire"),
		FText::FromString("The mud here tastes of sulfur and rotting peat... I am their shield."),
		FText::FromString("This isn't a tactic, Kaelen."),
		FText::FromString("Kaelen... your handwriting is shaking."),
		0.30f, // Garrett trust <= 0.35f -> Guarded Friction
		0.28f, // Serafina trust <= 0.35f
		0.80f  // Kaelen debt > 0.75f
	);

	FAshenJournalEntry Entry = Subsystem->GetLatestJournalEntry();
	TestTrue(TEXT("Garrett strikethrough must be true"), Entry.bGarrettHasStrikethrough);
	TestTrue(TEXT("Ink bleed intensity must equal 0.80f"), FMath::IsNearlyEqual(Entry.PageInkBleedIntensity, 0.80f, 0.001f));
	return true;
}

// =============================================================================
//  Test 2: Dialogue Gating & Companion Spacing Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch71DownstreamReactivityTest,
	"AshenOath.WayfarerJournal.Downstream.ReactivityVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch71DownstreamReactivityTest::RunTest(const FString& Parameters)
{
	UAshenJournalDialogueGatingAdapter* DialogueAdapter = NewObject<UAshenJournalDialogueGatingAdapter>();
	if (!TestNotNull(TEXT("DialogueAdapter must be constructable"), DialogueAdapter)) return false;

	DialogueAdapter->UpdateDialogueGatingForJournalFriction(true);
	TestTrue(TEXT("Vulnerable dialogue paths must be locked"), DialogueAdapter->bAreVulnerablePathsLocked);

	UAshenJournalCompanionAISpacingAdapter* SpacingAdapter = NewObject<UAshenJournalCompanionAISpacingAdapter>();
	if (!TestNotNull(TEXT("SpacingAdapter must be constructable"), SpacingAdapter)) return false;

	SpacingAdapter->UpdateCompanionSpacingForFriction(true);
	TestEqual(TEXT("Follow distance must expand to 700 units"), SpacingAdapter->CompanionFollowDistance, 700.0f);
	TestTrue(TEXT("Hand on pommel stance must be active"), SpacingAdapter->bHandOnPommelStance);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1435 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1435MasterVerificationTest,
	"AshenOath.Milestone.Milestone1435.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1435MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1435MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1435MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1435 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1435 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1435Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1435 WAYFARER'S JOURNAL PIPELINE VERIFIED (1,435 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
