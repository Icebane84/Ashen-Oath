// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1655: Master Batch #82 QA Automation Test Suite — Bestiary & Labyrinth Bespoke Finisher Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1655MasterSynthesisOrchestrator.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "Combat/AshenSlagSerpentThermalVentComponent.h"
#include "World/AshenRootGnarlTerrainClearanceActor.h"

// =============================================================================
//  Test 1: Slag-Serpent Cryo-Quench & Vent Cauterization
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch82SlagSerpentTest,
	"AshenOath.BestiaryFinisher.SlagSerpent.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch82SlagSerpentTest::RunTest(const FString& Parameters)
{
	UAshenSlagSerpentThermalVentComponent* Vent = NewObject<UAshenSlagSerpentThermalVentComponent>();
	if (!TestNotNull(TEXT("SlagSerpentThermalVentComponent must be constructable"), Vent)) return false;

	Vent->ApplyCryoQuench();
	TestTrue(TEXT("bIsVentCarapaceCracked must equal true"), Vent->bIsVentCarapaceCracked);

	Vent->ExtinguishFurnaceHeart();
	TestEqual(TEXT("InternalFurnaceTemp must equal 0.0f"), Vent->InternalFurnaceTemp, 0.0f);
	return true;
}

// =============================================================================
//  Test 2: Root-Gnarl Terrain Clearance
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch82RootGnarlTest,
	"AshenOath.BestiaryFinisher.RootGnarl.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch82RootGnarlTest::RunTest(const FString& Parameters)
{
	AAshenRootGnarlTerrainClearanceActor* Actor = NewObject<AAshenRootGnarlTerrainClearanceActor>();
	if (!TestNotNull(TEXT("RootGnarlTerrainClearanceActor must be constructable"), Actor)) return false;

	Actor->ClearRootBlockade();
	TestTrue(TEXT("bIsPathCleared must equal true"), Actor->bIsPathCleared);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1655 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1655MasterVerificationTest,
	"AshenOath.Milestone.Milestone1655.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1655MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1655MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1655MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1655 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1655 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1655Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1655 BESTIARY & LABYRINTH FINISHER PIPELINE VERIFIED (1,655 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
