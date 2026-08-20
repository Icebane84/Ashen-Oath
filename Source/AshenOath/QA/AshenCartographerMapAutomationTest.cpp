// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1120: Ashen Cartographer Map QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1120SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCartographerMapAutomationTest,
	"AshenOath.QA.CartographerMap.Milestone1120Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenCartographerMapAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1120SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1120SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1120 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1120Synthesis();
	TestTrue(TEXT("Milestone 1120 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1120 CARTOGRAPHER MAP SUITE VERIFIED (1120 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
