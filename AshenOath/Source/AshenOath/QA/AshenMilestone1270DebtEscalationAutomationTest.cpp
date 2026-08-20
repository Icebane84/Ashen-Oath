// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1270: Integration Debt Escalation QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1270SynthesisOrchestrator.h"
#include "Soul/AshenIntegrationDebtManager.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1270DebtEscalationAutomationTest,
	"AshenOath.QA.IntegrationDebt.Milestone1270Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1270DebtEscalationAutomationTest::RunTest(const FString& Parameters)
{
	UAshenIntegrationDebtManager* Manager = NewObject<UAshenIntegrationDebtManager>();
	if (!TestNotNull(TEXT("IntegrationDebtManager must be constructable"), Manager)) return false;

	TestEqual(TEXT("Debt 0.10f must be Stable"), Manager->EvaluateDebtStage(0.10f), EAshenIntegrationDebtStage::Stable);
	TestEqual(TEXT("Debt 0.60f must be MemoryBleed"), Manager->EvaluateDebtStage(0.60f), EAshenIntegrationDebtStage::MemoryBleed);
	TestEqual(TEXT("Debt 0.85f must be RuntimeNoise"), Manager->EvaluateDebtStage(0.85f), EAshenIntegrationDebtStage::RuntimeNoise);
	TestEqual(TEXT("Debt 1.00f must be ForcedCollapse"), Manager->EvaluateDebtStage(1.00f), EAshenIntegrationDebtStage::ForcedCollapse);

	UAshenMilestone1270SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1270SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1270 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1270 validation must return true"), Orchestrator->ValidateMilestone1270Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1270 DEBT ESCALATION SUITE VERIFIED ======"));
	return true;
}
