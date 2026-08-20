// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1720: Null Zone & Corruption Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1720SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1720NullZoneAutomationTest,
	"AshenOath.QA.NullZone.Milestone1720Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1720NullZoneAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1720SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1720SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1720 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1720 validation must return true"), Orchestrator->ValidateMilestone1720Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1720 NULL ZONE SUITE VERIFIED ======"));
	return true;
}
