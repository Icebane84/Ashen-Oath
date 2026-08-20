// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 390: Ashen Faction Merchant & Void Shatter Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GA_KaelenUnchainedVoidShatter.h"
#include "AshenGeopoliticalFactionMerchantSubsystem.h"
#include "AshenUserWidget_FactionMerchantShop.h"

// =============================================================================
//  Test 1: Kaelen Unchained Void Shatter — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenUnchainedVoidShatterClassTest,
	"AshenOath.GAS.KaelenUnchainedVoidShatter.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenUnchainedVoidShatterClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenUnchainedVoidShatter"));
	TestNotNull(TEXT("UGA_KaelenUnchainedVoidShatter must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 2: Geopolitical Faction Merchant Subsystem — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFactionMerchantSubsystemTest,
	"AshenOath.Merchant.GeopoliticalSubsystem.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFactionMerchantSubsystemTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenGeopoliticalFactionMerchantSubsystem class must be valid"),
		UAshenGeopoliticalFactionMerchantSubsystem::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 3: Faction Merchant Shop Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFactionMerchantShopWidgetTest,
	"AshenOath.UI.FactionMerchantShopWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFactionMerchantShopWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_FactionMerchantShop* Widget = NewObject<UAshenUserWidget_FactionMerchantShop>();
	if (!TestNotNull(TEXT("FactionMerchantShop widget must be constructable"), Widget)) return false;

	const FName FactionID(TEXT("Faction_OrderOfTheWhiteFlame"));
	Widget->UpdateFactionShopDisplay(FactionID, 3);
	TestEqual(TEXT("ActiveItemTier must equal 3"), Widget->ActiveItemTier, 3);

	return true;
}
