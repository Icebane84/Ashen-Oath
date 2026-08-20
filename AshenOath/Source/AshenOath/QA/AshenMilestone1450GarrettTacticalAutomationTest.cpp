// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1450: Garrett Tactical Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1450SynthesisOrchestrator.h"
#include "Companions/AshenGarrettGrappleComponent.h"
#include "Companions/AshenGarrettTrapNetworkComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1450GarrettTacticalAutomationTest,
	"AshenOath.QA.GarrettTactical.Milestone1450Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1450GarrettTacticalAutomationTest::RunTest(const FString& Parameters)
{
	UAshenGarrettGrappleComponent* Grapple = NewObject<UAshenGarrettGrappleComponent>();
	if (!TestNotNull(TEXT("GrappleComponent must be constructable"), Grapple)) return false;

	Grapple->FireGrapple(FVector(100.0f, 200.0f, 0.0f), false);
	TestEqual(TEXT("Grapple state must be Firing"), Grapple->CurrentGrappleState, EAshenGrappleState::Firing);

	UAshenGarrettTrapNetworkComponent* TrapNetwork = NewObject<UAshenGarrettTrapNetworkComponent>();
	if (!TestNotNull(TEXT("TrapNetworkComponent must be constructable"), TrapNetwork)) return false;

	TrapNetwork->RegisterTrapToNetwork();
	TrapNetwork->RegisterTrapToNetwork();
	const int32 Cascade = TrapNetwork->TriggerNetworkCascade();
	TestEqual(TEXT("Cascade count must equal 2"), Cascade, 2);

	UAshenMilestone1450SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1450SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1450 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1450 validation must return true"), Orchestrator->ValidateMilestone1450Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1450 GARRETT TACTICAL SUITE VERIFIED ======"));
	return true;
}
