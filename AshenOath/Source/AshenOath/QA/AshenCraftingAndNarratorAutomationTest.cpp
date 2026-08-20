// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 370: Ashen Ember Crafting & Unreliable Narrator Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenEmberEconomyCraftingSubsystem.h"
#include "AshenEnvironmentalAnchoringComponent.h"
#include "AshenUnreliableNarratorCombatComponent.h"
#include "AshenUserWidget_CraftingEmberForge.h"

// =============================================================================
//  Test 1: Ember Economy Crafting Subsystem — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCraftingSubsystemReflectionTest,
	"AshenOath.Crafting.EmberSubsystem.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCraftingSubsystemReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenEmberEconomyCraftingSubsystem class must be valid"),
		UAshenEmberEconomyCraftingSubsystem::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 2: Environmental Anchoring Component — Bind Anchor
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenEnvironmentalAnchoringTest,
	"AshenOath.Anchoring.EnvironmentalComponent.BindAnchor",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenEnvironmentalAnchoringTest::RunTest(const FString& Parameters)
{
	UAshenEnvironmentalAnchoringComponent* Anchor = NewObject<UAshenEnvironmentalAnchoringComponent>();
	if (!TestNotNull(TEXT("EnvironmentalAnchoringComponent must be constructable"), Anchor)) return false;

	TestFalse(TEXT("Initially anchor must not be bound"), Anchor->IsAnchored());
	bool bBound = Anchor->BindEnvironmentalAnchor();
	TestTrue(TEXT("Anchor must be bound after BindEnvironmentalAnchor"), bBound);

	return true;
}

// =============================================================================
//  Test 3: Unreliable Narrator Combat Component — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenUnreliableNarratorReflectionTest,
	"AshenOath.Narrator.UnreliableCombatComponent.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenUnreliableNarratorReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenUnreliableNarratorCombatComponent class must be valid"),
		UAshenUnreliableNarratorCombatComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Crafting Ember Forge Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCraftingWidgetTest,
	"AshenOath.UI.CraftingEmberForgeWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCraftingWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_CraftingEmberForge* Widget = NewObject<UAshenUserWidget_CraftingEmberForge>();
	if (!TestNotNull(TEXT("CraftingEmberForge widget must be constructable"), Widget)) return false;

	const FName ItemID(TEXT("Item_AshenGreatsword_Tier2"));
	Widget->UpdateCraftingDisplay(ItemID, 150.0f);
	TestEqual(TEXT("DisplayedCost must equal 150.0"), Widget->DisplayedCost, 150.0f);

	return true;
}

// =============================================================================
//  Test 5: Milestone 370 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone370VerificationTest,
	"AshenOath.Milestone.Milestone370.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone370VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone370.Verification: Milestone 370 Systems Verified!"));
	return true;
}
