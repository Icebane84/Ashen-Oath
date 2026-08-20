// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1570: Campfire Rest Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1570SynthesisOrchestrator.h"
#include "World/AshenCampfireRestAreaActor.h"
#include "World/AshenHeartstoneSubsystem.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1570CampfireRestAutomationTest,
	"AshenOath.QA.CampfireRest.Milestone1570Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1570CampfireRestAutomationTest::RunTest(const FString& Parameters)
{
	AAshenCampfireRestAreaActor* CampfireActor = NewObject<AAshenCampfireRestAreaActor>();
	if (!TestNotNull(TEXT("CampfireRestAreaActor must be constructable"), CampfireActor)) return false;

	CampfireActor->KindleCampfire();
	TestEqual(TEXT("CurrentState must equal Kindled"), CampfireActor->CurrentState, EAshenCampfireRestState::Kindled);

	UAshenHeartstoneSubsystem* Heartstone = NewObject<UAshenHeartstoneSubsystem>();
	if (!TestNotNull(TEXT("HeartstoneSubsystem must be constructable"), Heartstone)) return false;

	TestTrue(TEXT("Transmute remnants to perk must return true"), Heartstone->TransmuteRemnantsToPerk(FName(TEXT("Perk_UnyieldingAegis")), 5, 20.0f));
	TestEqual(TEXT("TotalForgedTraits must equal 1"), Heartstone->TotalForgedTraits, 1);

	UAshenMilestone1570SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1570SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1570 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1570 validation must return true"), Orchestrator->ValidateMilestone1570Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1570 CAMPFIRE REST SUITE VERIFIED ======"));
	return true;
}
