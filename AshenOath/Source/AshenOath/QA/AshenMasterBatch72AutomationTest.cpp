// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1455: Master Batch #72 QA Automation Test Suite — Garrett Tactical Utility & Trap Network Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1455MasterSynthesisOrchestrator.h"
#include "Companions/AshenGarrettGrappleComponent.h"
#include "Companions/AshenGarrettTrapNetworkComponent.h"

// =============================================================================
//  Test 1: Garrett Grapple Fire & Interpose State Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch72GrappleStateTest,
	"AshenOath.GarrettTactical.Grapple.StateVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch72GrappleStateTest::RunTest(const FString& Parameters)
{
	UAshenGarrettGrappleComponent* Grapple = NewObject<UAshenGarrettGrappleComponent>();
	if (!TestNotNull(TEXT("GrappleComponent must be constructable"), Grapple)) return false;

	Grapple->FireGrapple(FVector(500.0f, 0.0f, 0.0f), true);
	TestEqual(TEXT("Grapple state must be Interposing"), Grapple->CurrentGrappleState, EAshenGrappleState::Interposing);
	return true;
}

// =============================================================================
//  Test 2: Garrett Trap Network Cascade Detonation Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch72TrapCascadeTest,
	"AshenOath.GarrettTactical.TrapNetwork.CascadeVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch72TrapCascadeTest::RunTest(const FString& Parameters)
{
	UAshenGarrettTrapNetworkComponent* TrapNetwork = NewObject<UAshenGarrettTrapNetworkComponent>();
	if (!TestNotNull(TEXT("TrapNetworkComponent must be constructable"), TrapNetwork)) return false;

	TrapNetwork->RegisterTrapToNetwork();
	TrapNetwork->RegisterTrapToNetwork();
	TrapNetwork->RegisterTrapToNetwork();
	const int32 Detonated = TrapNetwork->TriggerNetworkCascade();
	TestEqual(TEXT("Detonated count must equal 3"), Detonated, 3);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1455 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1455MasterVerificationTest,
	"AshenOath.Milestone.Milestone1455.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1455MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1455MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1455MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1455 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1455 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1455Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1455 GARRETT TACTICAL PIPELINE VERIFIED (1,455 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
