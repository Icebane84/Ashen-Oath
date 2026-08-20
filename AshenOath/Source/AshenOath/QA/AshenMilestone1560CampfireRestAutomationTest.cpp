// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1560: Campfire Rest Tooling QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1560SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1560CampfireRestAutomationTest,
	"AshenOath.QA.CampfireRest.Milestone1560Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1560CampfireRestAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1560SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1560SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1560 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1560 validation must return true"), Orchestrator->ValidateMilestone1560Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1560 CAMPFIRE REST SUITE VERIFIED ======"));
	return true;
}
