// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1370: Companion Dialogue Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1370SynthesisOrchestrator.h"
#include "Narrative/AshenCompanionDialogueBranchingSubsystem.h"
#include "Companions/AshenCompanionEmpathicStateEvaluator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1370CompanionDialogueAutomationTest,
	"AshenOath.QA.CompanionDialogue.Milestone1370Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1370CompanionDialogueAutomationTest::RunTest(const FString& Parameters)
{
	UAshenCompanionDialogueBranchingSubsystem* Branching = NewObject<UAshenCompanionDialogueBranchingSubsystem>();
	if (!TestNotNull(TEXT("DialogueBranchingSubsystem must be constructable"), Branching)) return false;

	FText Line = Branching->SelectDynamicDialogueLine("Garrett", 1, 0.80f);
	TestTrue(TEXT("Dialogue line must be non-empty"), !Line.IsEmpty());

	UAshenCompanionEmpathicStateEvaluator* Evaluator = NewObject<UAshenCompanionEmpathicStateEvaluator>();
	if (!TestNotNull(TEXT("EmpathicStateEvaluator must be constructable"), Evaluator)) return false;

	FString Mood = Evaluator->EvaluateEmpathicMood(0.80f, 0.20f, 0.10f);
	TestEqual(TEXT("Mood must equal Harmonious"), Mood, FString("Harmonious"));

	UAshenMilestone1370SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1370SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1370 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1370 validation must return true"), Orchestrator->ValidateMilestone1370Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1370 COMPANION DIALOGUE SUITE VERIFIED ======"));
	return true;
}
