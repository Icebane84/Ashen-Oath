// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1760: Companion Fatigue & Divergence Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1760SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1760CompanionAutomationTest,
	"AshenOath.QA.Companion.Milestone1760Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1760CompanionAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1760SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1760SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1760 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1760 validation must return true"), Orchestrator->ValidateMilestone1760Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1760 COMPANION FATIGUE SUITE VERIFIED ======"));
	return true;
}
