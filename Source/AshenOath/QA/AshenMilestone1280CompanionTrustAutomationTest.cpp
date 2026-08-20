// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1280: Companion Trust QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1280SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1280CompanionTrustAutomationTest,
	"AshenOath.QA.CompanionTrust.Milestone1280Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1280CompanionTrustAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1280SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1280SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1280 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1280 validation must return true"), Orchestrator->ValidateMilestone1280Synthesis());
	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1280 COMPANION TRUST TOOLING SUITE VERIFIED ======"));
	return true;
}
