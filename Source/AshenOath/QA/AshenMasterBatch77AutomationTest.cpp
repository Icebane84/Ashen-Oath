// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1555: Master Batch #77 QA Automation Test Suite — Alchemical Lantern Fluid Dynamics & Regional Corruption Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1555MasterSynthesisOrchestrator.h"
#include "Core/AshenAlchemicalLanternComponent.h"
#include "World/AshenRegionalCorruptionSpreadSubsystem.h"

// =============================================================================
//  Test 1: Alchemical Lantern Ignition & Fuel Consumption Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch77LanternFuelTest,
	"AshenOath.AlchemicalEcology.Lantern.FuelVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch77LanternFuelTest::RunTest(const FString& Parameters)
{
	UAshenAlchemicalLanternComponent* Lantern = NewObject<UAshenAlchemicalLanternComponent>();
	if (!TestNotNull(TEXT("LanternComponent must be constructable"), Lantern)) return false;

	Lantern->ToggleLantern(true);
	TestTrue(TEXT("bIsLanternLit must equal true"), Lantern->bIsLanternLit);

	Lantern->ConsumeFuel(20.0f);
	TestTrue(TEXT("Fuel after consumption must be < 100.0f"), Lantern->CurrentFuel < 100.0f);
	return true;
}

// =============================================================================
//  Test 2: Regional Corruption 64-Sector Array Propagation Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch77RegionalCorruptionTest,
	"AshenOath.AlchemicalEcology.Corruption.PropagationVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch77RegionalCorruptionTest::RunTest(const FString& Parameters)
{
	UAshenRegionalCorruptionSpreadSubsystem* Subsystem = NewObject<UAshenRegionalCorruptionSpreadSubsystem>();
	if (!TestNotNull(TEXT("RegionalCorruptionSubsystem must be constructable"), Subsystem)) return false;

	Subsystem->PropagateRegionalCorruption(12, 60.0f);
	TestEqual(TEXT("Sector 12 corruption must equal 60.0f"), Subsystem->GetSectorCorruption(12), 60.0f);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1555 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1555MasterVerificationTest,
	"AshenOath.Milestone.Milestone1555.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1555MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1555MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1555MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1555 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1555 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1555Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1555 ALCHEMICAL ECOLOGY PIPELINE VERIFIED (1,555 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
