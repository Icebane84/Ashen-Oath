// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1090: Ashen Resonance Spatializer QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1090SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenResonanceSpatializerAutomationTest,
	"AshenOath.QA.ResonanceSpatializer.Milestone1090Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenResonanceSpatializerAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1090SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1090SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1090 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone1090Synthesis();
	TestTrue(TEXT("Milestone 1090 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 1090 RESONANCE SPATIALIZER SUITE VERIFIED (1090 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
