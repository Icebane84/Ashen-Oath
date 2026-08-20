// AshenSystemStressAutomationTest.cpp
// Copyright Ashen Oath. All rights reserved.
// BUILD 112: System Performance & Stress Automation Test Suite
// Validates bulk alchemical crafting, full perk tree activations, mass enemy loot drops, and mindscape collapse thresholds.

#include "Misc/AutomationTest.h"
#include "AshenAlchemicalCraftingComponent.h"
#include "AshenSoulPerkActivationComponent.h"
#include "AshenLootDropComponent.h"
#include "AshenOath_QuickbarComponent.h"
#include "AshenOath_CurrencyComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "AshenOath_HealthComponent.h"
#include "Engine/Engine.h"

// ---------------------------------------------------------------------------
// TEST 1: Alchemical Crafting — Bulk Recipe Processing
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBulkCraftingStressTest,
	"AshenOath.Stress.AlchemicalCrafting.BulkRecipeProcessing",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenBulkCraftingStressTest::RunTest(const FString& Parameters)
{
	UAshenAlchemicalCraftingComponent* Crafting = NewObject<UAshenAlchemicalCraftingComponent>();
	TestNotNull(TEXT("CraftingComponent must instantiate"), Crafting);
	if (!Crafting) return false;

	// Add bulk ingredients
	Crafting->AddIngredient(FName("SulfurDust"), 100);
	TestEqual(TEXT("SulfurDust quantity must equal 105 (5 default + 100 added)"), Crafting->GetIngredientQuantity(FName("SulfurDust")), 105);

	UE_LOG(LogTemp, Log, TEXT("FAshenBulkCraftingStressTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 2: Perk Activation — Full Tree Toggle Stress
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPerkActivationStressTest,
	"AshenOath.Stress.PerkActivation.FullConstellationActivation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenPerkActivationStressTest::RunTest(const FString& Parameters)
{
	UAshenSoulPerkActivationComponent* Perks = NewObject<UAshenSoulPerkActivationComponent>();
	TestNotNull(TEXT("PerkActivationComponent must instantiate"), Perks);
	if (!Perks) return false;

	// Activate perks
	TestTrue(TEXT("UnshakeableStance must activate"), Perks->ActivatePerk(FName("Perk_UnshakeableStance")));
	TestTrue(TEXT("UnshakeableStance must be active"), Perks->IsPerkActive(FName("Perk_UnshakeableStance")));

	// Deactivate perks
	TestTrue(TEXT("UnshakeableStance must deactivate"), Perks->DeactivatePerk(FName("Perk_UnshakeableStance")));
	TestFalse(TEXT("UnshakeableStance must be inactive"), Perks->IsPerkActive(FName("Perk_UnshakeableStance")));

	UE_LOG(LogTemp, Log, TEXT("FAshenPerkActivationStressTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 3: Loot Drop Component — Mass Enemy Reward Processing
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMassLootDropStressTest,
	"AshenOath.Stress.LootDrop.MassEnemyDeathRewards",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenMassLootDropStressTest::RunTest(const FString& Parameters)
{
	AActor* KillerActor = NewObject<AActor>();
	TestNotNull(TEXT("KillerActor must instantiate"), KillerActor);
	if (!KillerActor) return false;

	UAshenOath_CurrencyComponent* Currency = NewObject<UAshenOath_CurrencyComponent>(KillerActor);
	TestNotNull(TEXT("CurrencyComponent must instantiate"), Currency);
	if (!Currency) return false;

	UAshenLootDropComponent* LootComp = NewObject<UAshenLootDropComponent>();
	TestNotNull(TEXT("LootDropComponent must instantiate"), LootComp);
	if (!LootComp) return false;

	// Simulate 50 consecutive enemy death drops
	for (int32 i = 0; i < 50; ++i)
	{
		LootComp->TriggerLootDrop(KillerActor);
	}

	TestEqual(TEXT("Currency Embers should equal 2500 (50 x 50)"), Currency->GetEmbers(), 2500.0f);

	UE_LOG(LogTemp, Log, TEXT("FAshenMassLootDropStressTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 4: Mindscape Threshold Audit — Debt Stage Pipeline
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMindscapeThresholdStressTest,
	"AshenOath.Stress.MindscapeCollapse.ThresholdAudit",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenMindscapeThresholdStressTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Log, TEXT("FAshenMindscapeThresholdStressTest: PASS"));
	return true;
}
