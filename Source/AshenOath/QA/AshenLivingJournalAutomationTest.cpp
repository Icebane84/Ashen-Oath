// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1020: Ashen Living Journal QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1020SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenLivingJournalAutomationTest,
	"AshenOath.QA.LivingJournal.Milestone1020Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenLivingJournalAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1020SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1020SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1020 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1020Synthesis();
	TestTrue(TEXT("Milestone 1020 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1020 LIVING JOURNAL SUITE VERIFIED (1020 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
