// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1660: Living Oath Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1660SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1660LivingOathAutomationTest,
	"AshenOath.QA.LivingOath.Milestone1660Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1660LivingOathAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1660SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1660SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1660 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1660 validation must return true"), Orchestrator->ValidateMilestone1660Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1660 LIVING OATH SUITE VERIFIED ======"));
	return true;
}
