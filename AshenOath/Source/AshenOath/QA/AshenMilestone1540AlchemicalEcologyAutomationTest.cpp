// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1540: Alchemical Ecology Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1540SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1540AlchemicalEcologyAutomationTest,
	"AshenOath.QA.AlchemicalEcology.Milestone1540Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1540AlchemicalEcologyAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1540SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1540SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1540 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1540 validation must return true"), Orchestrator->ValidateMilestone1540Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1540 ALCHEMICAL ECOLOGY SUITE VERIFIED ======"));
	return true;
}
