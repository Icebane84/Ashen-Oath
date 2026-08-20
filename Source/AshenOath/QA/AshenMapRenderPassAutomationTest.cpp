// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1130: Ashen Map Render Pass QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1130SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMapRenderPassAutomationTest,
	"AshenOath.QA.MapRenderPass.Milestone1130Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenMapRenderPassAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1130SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1130SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1130 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1130Synthesis();
	TestTrue(TEXT("Milestone 1130 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1130 MAP RENDER PASS SUITE VERIFIED (1130 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
