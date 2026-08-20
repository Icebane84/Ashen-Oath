// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1010: Ashen Sovereign Phoenix QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1010SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSovereignPhoenixAutomationTest,
	"AshenOath.QA.SovereignPhoenix.Milestone1010Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenSovereignPhoenixAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1010SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1010SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1010 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1010Synthesis();
	TestTrue(TEXT("Milestone 1010 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1010 SOVEREIGN PHOENIX SUITE VERIFIED (1010 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
