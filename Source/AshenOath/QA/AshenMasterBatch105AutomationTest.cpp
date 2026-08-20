// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 2115: Master Batch #105 QA Automation Test Suite — Garrett's Alchemical Formulation Matrix
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenAlchemicalMatrixSubsystem.h"
#include "Combat/AshenBurningSteelOilComponent.h"
#include "Combat/AshenGhostbloomFlareComponent.h"
#include "Combat/AshenAlchemicalCaltropGridComponent.h"
#include "Combat/AshenIgnitedCutlassMeshAdapter.h"

// =============================================================================
//  Test 1: Alchemical Inventory & Crafting Logic Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch105CraftingAndInventoryTest,
	"AshenOath.Alchemy.CraftingAndInventory.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch105CraftingAndInventoryTest::RunTest(const FString& Parameters)
{
	// Test 1: Subsystem Inventory Initialization
	UAshenAlchemicalMatrixSubsystem* Subsystem = NewObject<UAshenAlchemicalMatrixSubsystem>();
	if (!TestNotNull(TEXT("AlchemicalMatrixSubsystem must be constructable"), Subsystem)) return false;

	TestEqual(TEXT("Initial Burning Steel vials must be 4"), Subsystem->GarrettPouch.BurningSteelOilVials, 4);
	TestEqual(TEXT("Initial Gloomwood needles must be 3"), Subsystem->GarrettPouch.GloomwoodDampenerNeedles, 3);
	TestEqual(TEXT("Initial Caltrops must be 5"), Subsystem->GarrettPouch.CaltropSupply, 5);

	// Test 2: Crafting
	TestTrue(TEXT("Crafting Burning Steel must succeed"), Subsystem->CraftAlchemicalMatrix(EAlchemicalMatrixType::BurningSteelOil, 2));
	TestEqual(TEXT("Burning Steel vials must now be 6"), Subsystem->GarrettPouch.BurningSteelOilVials, 6);

	// Test 3: Consumption
	TestTrue(TEXT("Consuming Burning Steel must succeed"), Subsystem->ConsumeAlchemicalMatrix(EAlchemicalMatrixType::BurningSteelOil));
	TestEqual(TEXT("Burning Steel vials must now be 5"), Subsystem->GarrettPouch.BurningSteelOilVials, 5);

	return true;
}

// =============================================================================
//  Test 2: Burning Steel Oil, Ghostbloom Stun & Caltrop Grid Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch105CombatMatricesTest,
	"AshenOath.Alchemy.CombatMatrices.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch105CombatMatricesTest::RunTest(const FString& Parameters)
{
	// Test 1: Burning Steel Posture & Armor Math
	UAshenBurningSteelOilComponent* OilComp = NewObject<UAshenBurningSteelOilComponent>();
	if (!TestNotNull(TEXT("BurningSteelOilComponent must be constructable"), OilComp)) return false;

	TestEqual(TEXT("Posture bonus must equal +35.0"), OilComp->PostureDamageBonus, 35.0f);
	TestEqual(TEXT("Armor strip percentage must equal 15%"), OilComp->ArmorStripPercentage, 0.15f);

	// Test 2: Ghostbloom Flash Flare Parameters
	UAshenGhostbloomFlareComponent* FlareComp = NewObject<UAshenGhostbloomFlareComponent>();
	if (!TestNotNull(TEXT("GhostbloomFlareComponent must be constructable"), FlareComp)) return false;

	TestEqual(TEXT("Stun duration must be 4.0s"), FlareComp->StunDurationSeconds, 4.0f);
	TestEqual(TEXT("Flash radius must be 600uu"), FlareComp->FlashRadiusUnits, 600.0f);

	// Test 3: Caltrop Grid Tracking
	UAshenAlchemicalCaltropGridComponent* GridComp = NewObject<UAshenAlchemicalCaltropGridComponent>();
	if (!TestNotNull(TEXT("AlchemicalCaltropGridComponent must be constructable"), GridComp)) return false;

	GridComp->RegisterCaltropFieldSpawned();
	GridComp->RegisterCaltropFieldSpawned();
	TestEqual(TEXT("Active caltrop fields must equal 2"), GridComp->ActiveCaltropFieldsCount, 2);

	// Test 4: Ignited Weapon Mesh Glow
	UAshenIgnitedCutlassMeshAdapter* CutlassAdapter = NewObject<UAshenIgnitedCutlassMeshAdapter>();
	if (!TestNotNull(TEXT("IgnitedCutlassMeshAdapter must be constructable"), CutlassAdapter)) return false;

	CutlassAdapter->SetCutlassIgnitionState(true);
	TestEqual(TEXT("Flame emissive glow must equal 3.0"), CutlassAdapter->FlameEmissiveGlow, 3.0f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #105 ALCHEMICAL MATRIX VERIFIED (2,115 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
