// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1260: Integration Debt Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1260SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1260IntegrationDebtAutomationTest,
	"AshenOath.QA.IntegrationDebt.Milestone1260Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1260IntegrationDebtAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1260SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1260SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1260 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1260 validation must return true"), Orchestrator->ValidateMilestone1260Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1260 INTEGRATION DEBT TOOLING SUITE VERIFIED ======"));
	return true;
}
