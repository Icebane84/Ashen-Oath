// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1300: Living Oath Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1300SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1300LivingOathAutomationTest,
	"AshenOath.QA.LivingOath.Milestone1300Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1300LivingOathAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1300SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1300SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1300 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1300 validation must return true"), Orchestrator->ValidateMilestone1300Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1300 LIVING OATH TOOLING SUITE VERIFIED ======"));
	return true;
}
