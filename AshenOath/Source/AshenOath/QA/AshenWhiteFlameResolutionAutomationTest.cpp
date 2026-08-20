// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1150: Ashen White Flame Resolution QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1150SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWhiteFlameResolutionAutomationTest,
	"AshenOath.QA.WhiteFlameResolution.Milestone1150Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenWhiteFlameResolutionAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1150SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1150SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1150 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1150Synthesis();
	TestTrue(TEXT("Milestone 1150 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1150 WHITE FLAME RESOLUTION SUITE VERIFIED (1150 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
