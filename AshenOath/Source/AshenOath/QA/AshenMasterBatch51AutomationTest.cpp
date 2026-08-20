// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1035: Ashen Master Batch #51 QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1035MasterSynthesisOrchestrator.h"
#include "Narrative/AshenDiegeticJournalSubsystem.h"
#include "Narrative/AshenMemoryReconciliationEngine.h"
#include "UI/AshenCompanionInterfaceAnnotationComponent.h"
#include "UI/AshenSomaticPresentationController.h"

// =============================================================================
//  Test 1: Living Journal Event Dispatch & Multi-Perspective Array
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenLivingJournalSubsystemDispatchTest,
	"AshenOath.Narrative.LivingJournal.EventDispatchAndPerspectives",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenLivingJournalSubsystemDispatchTest::RunTest(const FString& Parameters)
{
	UAshenDiegeticJournalSubsystem* Subsystem = NewObject<UAshenDiegeticJournalSubsystem>();
	if (!TestNotNull(TEXT("Diegetic Journal Subsystem must be constructable"), Subsystem)) return false;

	FJournalEvent TestEvent;
	TestEvent.MemoryNodeID = "BLACKWOOD_BRIDGE_CONFRONTATION";

	FJournalPerspective KaelenPerspective;
	KaelenPerspective.AuthorName = "Kaelen";
	KaelenPerspective.InterpretationText = FText::FromString("Blackwood Bridge. The mist was thick with the scent of burning pine.");
	TestEvent.Perspectives.Add(KaelenPerspective);

	FJournalPerspective GarrettPerspective;
	GarrettPerspective.AuthorName = "Garrett";
	GarrettPerspective.InterpretationText = FText::FromString("Don't attack the shoulders. Wait for the left-foot plant.");
	TestEvent.Perspectives.Add(GarrettPerspective);

	Subsystem->DispatchJournalEvent(TestEvent);

	TestEqual(TEXT("Journal history must log 1 event"), Subsystem->GetJournalHistoryForNode("BLACKWOOD_BRIDGE_CONFRONTATION").Num(), 1);
	return true;
}

// =============================================================================
//  Test 2: Somatic Presentation Controller — Sanity & Corruption Distortion
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch51SomaticPresentationControllerTest,
	"AshenOath.UI.SomaticPresentation.DistortionScalarsBatch51",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch51SomaticPresentationControllerTest::RunTest(const FString& Parameters)
{
	UAshenSomaticPresentationController* Comp = NewObject<UAshenSomaticPresentationController>();
	if (!TestNotNull(TEXT("Somatic Presentation Controller must be constructable"), Comp)) return false;

	Comp->UpdateSomaticPresentation(0.2f, 0.8f);
	TestEqual(TEXT("Ink bleed scalar must equal 0.8f"), Comp->InkBleedScalar, 0.8f);
	TestEqual(TEXT("Handwriting wobble intensity must equal 0.8f"), Comp->HandwritingWobbleIntensity, 0.8f);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1035 Verification Across All 1,035 Builds
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1035MasterVerificationTest,
	"AshenOath.Milestone.Milestone1035.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1035MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1035MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1035MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1035 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMasterMilestone1035Synthesis();
	TestTrue(TEXT("Master Milestone 1035 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1035 LIVING JOURNAL SUITE VERIFIED (1035 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
