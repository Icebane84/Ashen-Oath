// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 285: Ashen Vendor Shop & Audio Footstep Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenSanctuaryVendorShopComponent.h"
#include "GA_SerafinaSunfallNova.h"
#include "AshenAudioFootstepSurfaceSubsystem.h"
#include "AshenUserWidget_VendorItemSlot.h"

// =============================================================================
//  Test 1: Sanctuary Vendor Shop — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVendorShopReflectionTest,
	"AshenOath.Vendor.ShopComponent.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenVendorShopReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenSanctuaryVendorShopComponent class must be valid"),
		UAshenSanctuaryVendorShopComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 2: Serafina Sunfall Nova — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSunfallNovaClassTest,
	"AshenOath.GAS.SerafinaSunfallNova.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSunfallNovaClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_SerafinaSunfallNova"));
	TestNotNull(TEXT("UGA_SerafinaSunfallNova must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Audio Footstep Surface Subsystem — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFootstepSurfaceReflectionTest,
	"AshenOath.Audio.FootstepSurfaceSubsystem.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFootstepSurfaceReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenAudioFootstepSurfaceSubsystem class must be valid"),
		UAshenAudioFootstepSurfaceSubsystem::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Vendor Item Slot Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVendorItemSlotWidgetTest,
	"AshenOath.UI.VendorItemSlotWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenVendorItemSlotWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_VendorItemSlot* Slot = NewObject<UAshenUserWidget_VendorItemSlot>();
	if (!TestNotNull(TEXT("VendorItemSlot widget must be constructable"), Slot)) return false;

	const FName ItemID(TEXT("Item_HealthPotion"));
	const FText ItemName = FText::FromString(TEXT("Holy Elixir"));

	Slot->UpdateVendorItemSlot(ItemID, ItemName, 150.0f, 5);
	TestEqual(TEXT("DisplayedItemID must match"), Slot->DisplayedItemID, ItemID);
	TestEqual(TEXT("DisplayedEmberCost must be 150.0"), Slot->DisplayedEmberCost, 150.0f);
	TestEqual(TEXT("DisplayedStock must be 5"), Slot->DisplayedStock, 5);

	return true;
}

// =============================================================================
//  Test 5: Sanctuary Vendor Shop — Constructability
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVendorShopConstructTest,
	"AshenOath.Vendor.ShopComponent.Constructability",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenVendorShopConstructTest::RunTest(const FString& Parameters)
{
	UAshenSanctuaryVendorShopComponent* Vendor = NewObject<UAshenSanctuaryVendorShopComponent>();
	TestNotNull(TEXT("SanctuaryVendorShopComponent must be constructable"), Vendor);
	return true;
}
