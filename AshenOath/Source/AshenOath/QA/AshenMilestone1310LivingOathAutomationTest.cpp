// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1310: Living Oath QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1310SynthesisOrchestrator.h"
#include "Soul/AshenLivingOathRegistrySubsystem.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1310LivingOathAutomationTest,
	"AshenOath.QA.LivingOath.Milestone1310Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1310LivingOathAutomationTest::RunTest(const FString& Parameters)
{
	UAshenLivingOathRegistrySubsystem* Registry = NewObject<UAshenLivingOathRegistrySubsystem>();
	if (!TestNotNull(TEXT("LivingOathRegistrySubsystem must be constructable"), Registry)) return false;

	Registry->SwearOath("TestOath_ProtectGarrett", FText::FromString("I swear to protect Garrett."));
	TestEqual(TEXT("Registry count must equal 1"), Registry->ActiveOathRegistry.Num(), 1);

	Registry->FulfillOath("TestOath_ProtectGarrett");
	TestTrue(TEXT("Oath must be marked fulfilled"), Registry->ActiveOathRegistry[0].bFulfilled);

	UAshenMilestone1310SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1310SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1310 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1310 validation must return true"), Orchestrator->ValidateMilestone1310Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1310 LIVING OATH SUITE VERIFIED ======"));
	return true;
}
