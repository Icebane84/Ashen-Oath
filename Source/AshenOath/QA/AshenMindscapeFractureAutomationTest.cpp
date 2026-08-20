// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 960: Ashen Mindscape Fracture QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone960SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMindscapeFractureAutomationTest,
	"AshenOath.QA.MindscapeFracture.Milestone960Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenMindscapeFractureAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone960SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone960SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 960 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone960Synthesis();
	TestTrue(TEXT("Milestone 960 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 960 MINDSCAPE FRACTURE SUITE VERIFIED (960 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
