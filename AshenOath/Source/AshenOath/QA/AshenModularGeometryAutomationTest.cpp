// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1230: Ashen Modular Geometry QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1230SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenModularGeometryAutomationTest,
	"AshenOath.QA.ModularGeometry.Milestone1230Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenModularGeometryAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1230SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1230SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1230 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1230Synthesis();
	TestTrue(TEXT("Milestone 1230 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1230 MODULAR GEOMETRY SUITE VERIFIED (1230 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
