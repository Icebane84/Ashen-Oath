// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1240: Soul Constellation Kernel QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1240SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSoulConstellationKernelAutomationTest,
	"AshenOath.QA.SoulConstellationKernel.Milestone1240Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSoulConstellationKernelAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1240SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1240SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1240 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1240 validation must return true"), Orchestrator->ValidateMilestone1240Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1240 SOUL CONSTELLATION KERNEL SUITE VERIFIED ======"));
	return true;
}
