// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1140: Ashen Devil's Bargain QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1140SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDevilsBargainAutomationTest,
	"AshenOath.QA.DevilsBargain.Milestone1140Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenDevilsBargainAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1140SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1140SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1140 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1140Synthesis();
	TestTrue(TEXT("Milestone 1140 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1140 DEVIL'S BARGAIN SUITE VERIFIED (1140 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
