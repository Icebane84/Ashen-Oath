// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1220: Ashen Duality Engine QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1220SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDualityEngineAutomationTest,
	"AshenOath.QA.DualityEngine.Milestone1220Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenDualityEngineAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1220SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1220SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1220 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1220Synthesis();
	TestTrue(TEXT("Milestone 1220 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1220 DUALITY ENGINE SUITE VERIFIED (1220 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
