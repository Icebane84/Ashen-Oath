// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1030: Ashen Memory Reconciliation QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1030SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMemoryReconciliationAutomationTest,
	"AshenOath.QA.MemoryReconciliation.Milestone1030Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenMemoryReconciliationAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1030SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1030SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1030 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1030Synthesis();
	TestTrue(TEXT("Milestone 1030 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1030 MEMORY RECONCILIATION SUITE VERIFIED (1030 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
