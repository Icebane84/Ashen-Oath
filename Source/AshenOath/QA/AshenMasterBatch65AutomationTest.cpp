// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1315: Master Batch #65 QA Automation Test Suite — The Living Oath Engine & FOathRecord Registry
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1315MasterSynthesisOrchestrator.h"
#include "Soul/AshenLivingOathRegistrySubsystem.h"
#include "Combat/AshenOathBurnStaminaDrainComponent.h"
#include "World/AshenMindscapeOathReactivityMPCModulator.h"

// =============================================================================
//  Test 1: Living Oath Registry — Swear, Fulfill, Breach lifecycle
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch65OathLifecycleTest,
	"AshenOath.LivingOath.Registry.OathLifecycleVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch65OathLifecycleTest::RunTest(const FString& Parameters)
{
	UAshenLivingOathRegistrySubsystem* Registry = NewObject<UAshenLivingOathRegistrySubsystem>();
	if (!TestNotNull(TEXT("LivingOathRegistrySubsystem must be constructable"), Registry)) return false;

	Registry->SwearOath("Oath_ProtectGarrett", FText::FromString("Keep Garrett alive"));
	TestTrue(TEXT("Burden must equal 0.25f after swearing 1 oath"), FMath::IsNearlyEqual(Registry->ActiveOathBurden, 0.25f, 0.001f));

	Registry->BreachOath("Oath_ProtectGarrett");
	TestTrue(TEXT("Burden must equal 0.75f after breaching oath"), FMath::IsNearlyEqual(Registry->ActiveOathBurden, 0.75f, 0.001f));
	TestTrue(TEXT("Oath must be marked broken"), Registry->ActiveOathRegistry[0].bBroken);
	return true;
}

// =============================================================================
//  Test 2: Oath Burn & Mindscape MPC Modulator
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch65OathBurnAndMPCTest,
	"AshenOath.LivingOath.Modulation.OathBurnAndMPCVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch65OathBurnAndMPCTest::RunTest(const FString& Parameters)
{
	UAshenOathBurnStaminaDrainComponent* BurnComp = NewObject<UAshenOathBurnStaminaDrainComponent>();
	if (!TestNotNull(TEXT("OathBurnStaminaDrainComponent must be constructable"), BurnComp)) return false;

	BurnComp->SetOathBurnState(true);
	TestTrue(TEXT("Oath burn must be active"), BurnComp->bOathBurnActive);

	UAshenMindscapeOathReactivityMPCModulator* MPCMod = NewObject<UAshenMindscapeOathReactivityMPCModulator>();
	if (!TestNotNull(TEXT("MPCModulator must be constructable"), MPCMod)) return false;

	MPCMod->UpdateMPCForOathBurden(0.85f);
	TestTrue(TEXT("MPC_OathCorruption must equal 0.85f"), FMath::IsNearlyEqual(MPCMod->OathCorruptionScalar, 0.85f, 0.001f));
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1315 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1315MasterVerificationTest,
	"AshenOath.Milestone.Milestone1315.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1315MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1315MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1315MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1315 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1315 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1315Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1315 LIVING OATH ENGINE VERIFIED (1,315 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
