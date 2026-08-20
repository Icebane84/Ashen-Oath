// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 425: Ashen Cognitive Debug & Sanctuary Blessing Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GA_SerafinaSunfallNova.h"
#include "AshenSanctuaryBlessingRegistrySubsystem.h"
#include "AshenUserWidget_SanctuaryBlessingMenu.h"

// =============================================================================
//  Test 1: Serafina Sunfall Nova — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCognitiveSunfallNovaClassTest,
	"AshenOath.GAS.SerafinaSunfallNova.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCognitiveSunfallNovaClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_SerafinaSunfallNova"));
	TestNotNull(TEXT("UGA_SerafinaSunfallNova must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 2: Sanctuary Blessing Registry Subsystem — Apply & Query
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSanctuaryBlessingSubsystemTest,
	"AshenOath.SanctuaryBlessing.RegistrySubsystem.ApplyAndQuery",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSanctuaryBlessingSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenSanctuaryBlessingRegistrySubsystem* Blessing = NewObject<UAshenSanctuaryBlessingRegistrySubsystem>();
	if (!TestNotNull(TEXT("SanctuaryBlessingRegistrySubsystem must be constructable"), Blessing)) return false;

	const FName BlessingID(TEXT("Blessing_RadiantVigor"));
	Blessing->RegisterSanctuaryBlessing(BlessingID, 25.0f);
	TestTrue(TEXT("ActiveBlessings must contain BlessingID"), Blessing->ActiveBlessings.Contains(BlessingID));

	return true;
}

// =============================================================================
//  Test 3: Sanctuary Blessing Menu Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSanctuaryBlessingMenuWidgetTest,
	"AshenOath.UI.SanctuaryBlessingMenuWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSanctuaryBlessingMenuWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_SanctuaryBlessingMenu* Widget = NewObject<UAshenUserWidget_SanctuaryBlessingMenu>();
	if (!TestNotNull(TEXT("SanctuaryBlessingMenu widget must be constructable"), Widget)) return false;

	const FName BlessingID(TEXT("Blessing_AethelgardResolve"));
	Widget->UpdateBlessingMenuDisplay(BlessingID, 1.30f);
	TestEqual(TEXT("DisplayedBuffMultiplier must equal 1.30"), Widget->DisplayedBuffMultiplier, 1.30f);

	return true;
}
