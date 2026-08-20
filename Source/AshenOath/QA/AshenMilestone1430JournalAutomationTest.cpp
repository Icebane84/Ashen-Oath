// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1430: Wayfarer's Journal Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1430SynthesisOrchestrator.h"
#include "Narrative/AshenWayfarerJournalSubsystem.h"
#include "UI/AshenJournalHandwritingMorphComponent.h"
#include "UI/AshenJournalCharcoalStrikethroughComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1430JournalAutomationTest,
	"AshenOath.QA.WayfarerJournal.Milestone1430Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1430JournalAutomationTest::RunTest(const FString& Parameters)
{
	UAshenWayfarerJournalSubsystem* Subsystem = NewObject<UAshenWayfarerJournalSubsystem>();
	if (!TestNotNull(TEXT("JournalSubsystem must be constructable"), Subsystem)) return false;

	Subsystem->RecordCampJournalEntry(
		"WeepingMire_Camp",
		FText::FromString("Rest at the Weeping Mire"),
		FText::FromString("The mud here tastes of sulfur and rotting peat..."),
		FText::FromString("This isn't a tactic, Kaelen."),
		FText::FromString("Kaelen... your handwriting is shaking."),
		0.25f, // Garrett trust <= 0.35f
		0.30f, // Serafina trust <= 0.35f
		0.80f  // Kaelen debt > 0.75f
	);

	FAshenJournalEntry Latest = Subsystem->GetLatestJournalEntry();
	TestTrue(TEXT("Garrett strikethrough must be true under low trust"), Latest.bGarrettHasStrikethrough);

	UAshenJournalHandwritingMorphComponent* MorphComp = NewObject<UAshenJournalHandwritingMorphComponent>();
	if (!TestNotNull(TEXT("HandwritingMorphComponent must be constructable"), MorphComp)) return false;

	MorphComp->CalculateHandwritingDegradation(0.85f);
	TestTrue(TEXT("Jitter frequency must be > 0 under high debt"), MorphComp->LetterJitterFrequency > 0.0f);

	UAshenMilestone1430SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1430SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1430 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1430 validation must return true"), Orchestrator->ValidateMilestone1430Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1430 WAYFARER'S JOURNAL SUITE VERIFIED ======"));
	return true;
}
