// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 196: Ashen Economy & Combat Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenVendorMerchantSubsystem.h"
#include "GA_GarrettTripwireDetonation.h"
#include "AshenPlayerStanceFXComponent.h"
#include "AshenUserWidget_VendorShop.h"

// =============================================================================
//  Test 1: Vendor Merchant Subsystem — Registration & Catalog
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVendorRegistrationTest,
	"AshenOath.Economy.VendorSubsystem.Registration",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenVendorRegistrationTest::RunTest(const FString& Parameters)
{
	UAshenVendorMerchantSubsystem* Subsystem = NewObject<UAshenVendorMerchantSubsystem>();
	if (!TestNotNull(TEXT("VendorMerchantSubsystem must be constructable"), Subsystem)) return false;

	const FName VendorID(TEXT("Merchant_Blacksmith_01"));
	Subsystem->RegisterVendor(VendorID);

	FAshenItemData Item;
	Item.ItemID = FName(TEXT("Item_HealthPotion"));
	Item.ItemName = FString(TEXT("Ashen Healing Balm"));
	Item.Quantity = 1;

	Subsystem->AddVendorItem(VendorID, Item, 50, 10);
	TestEqual(TEXT("Vendor catalog must contain 1 item"), Subsystem->GetVendorCatalog(VendorID).Num(), 1);

	return true;
}

// =============================================================================
//  Test 2: Garrett Tripwire Detonation — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTripwireDetonationClassTest,
	"AshenOath.GAS.GarrettTripwire.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTripwireDetonationClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_GarrettTripwireDetonation"));
	TestNotNull(TEXT("UGA_GarrettTripwireDetonation must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Player Stance FX — State Trigger
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPlayerStanceFXTriggerTest,
	"AshenOath.Combat.StanceFX.TriggerState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPlayerStanceFXTriggerTest::RunTest(const FString& Parameters)
{
	UAshenPlayerStanceFXComponent* FXComp = NewObject<UAshenPlayerStanceFXComponent>();
	if (!TestNotNull(TEXT("PlayerStanceFXComponent must be constructable"), FXComp)) return false;

	FXComp->TriggerStanceFX(EStanceProfile::Hunched_Guarded, 1.5f);
	TestEqual(TEXT("Active stance must be HunchedGuarded"), FXComp->GetActiveStanceFX(), EStanceProfile::Hunched_Guarded);

	return true;
}

// =============================================================================
//  Test 4: Vendor Shop Widget — Open & Close
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVendorShopWidgetOpenCloseTest,
	"AshenOath.UI.VendorShopWidget.OpenClose",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenVendorShopWidgetOpenCloseTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_VendorShop* Widget = NewObject<UAshenUserWidget_VendorShop>();
	if (!TestNotNull(TEXT("VendorShop widget must be constructable"), Widget)) return false;

	TArray<FAshenVendorItem> EmptyCatalog;
	const FName VendorID(TEXT("Vendor_Alchemist"));

	Widget->OpenVendorShop(VendorID, EmptyCatalog, 500);
	TestTrue(TEXT("bShopOpen must be true after OpenVendorShop"), Widget->bShopOpen);
	TestEqual(TEXT("CurrentVendorID must match"), Widget->CurrentVendorID, VendorID);

	Widget->CloseVendorShop();
	TestFalse(TEXT("bShopOpen must be false after CloseVendorShop"), Widget->bShopOpen);

	return true;
}

// =============================================================================
//  Test 5: Vendor Merchant Subsystem — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVendorSubsystemReflectionTest,
	"AshenOath.Economy.VendorSubsystem.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenVendorSubsystemReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenVendorMerchantSubsystem class must be valid"),
		UAshenVendorMerchantSubsystem::StaticClass() != nullptr);

	UFunction* BuyFn = UAshenVendorMerchantSubsystem::StaticClass()->FindFunctionByName(FName("BuyItem"));
	TestNotNull(TEXT("BuyItem must be a registered UFUNCTION"), BuyFn);

	UFunction* SellFn = UAshenVendorMerchantSubsystem::StaticClass()->FindFunctionByName(FName("SellItem"));
	TestNotNull(TEXT("SellItem must be a registered UFUNCTION"), SellFn);

	return true;
}
