// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 410: Ashen Regional Corruption & Garrett Poison Smoke Grid Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GA_GarrettPoisonSmokeGrid.h"
#include "AshenRegionalCorruptionSpreadSubsystem.h"
#include "AshenUserWidget_RegionalCorruptionMap.h"

// =============================================================================
//  Test 1: Garrett Poison Smoke Grid — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGarrettPoisonSmokeGridClassTest,
	"AshenOath.GAS.GarrettPoisonSmokeGrid.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGarrettPoisonSmokeGridClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_GarrettPoisonSmokeGrid"));
	TestNotNull(TEXT("UGA_GarrettPoisonSmokeGrid must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 2: Regional Corruption Spread Subsystem — Advance Corruption
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenRegionalCorruptionSubsystemTest,
	"AshenOath.RegionalCorruption.SpreadSubsystem.AdvanceCorruption",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenRegionalCorruptionSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenRegionalCorruptionSpreadSubsystem* Subsystem = NewObject<UAshenRegionalCorruptionSpreadSubsystem>();
	if (!TestNotNull(TEXT("RegionalCorruptionSpreadSubsystem must be constructable"), Subsystem)) return false;

	const FName ZoneID(TEXT("Zone_VoidScarredPlains"));
	Subsystem->AdvanceZoneCorruption(ZoneID, 45.0f);
	TestEqual(TEXT("Zone corruption level must equal 45.0"), Subsystem->GetZoneCorruptionLevel(ZoneID), 45.0f);

	return true;
}

// =============================================================================
//  Test 3: Regional Corruption Map Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenRegionalCorruptionMapWidgetTest,
	"AshenOath.UI.RegionalCorruptionMapWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenRegionalCorruptionMapWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_RegionalCorruptionMap* Widget = NewObject<UAshenUserWidget_RegionalCorruptionMap>();
	if (!TestNotNull(TEXT("RegionalCorruptionMap widget must be constructable"), Widget)) return false;

	const FName ZoneID(TEXT("Zone_AshenForest"));
	Widget->UpdateCorruptionMapDisplay(ZoneID, 72.5f);
	TestEqual(TEXT("DisplayedCorruptionPercentage must equal 72.5"), Widget->DisplayedCorruptionPercentage, 72.5f);

	return true;
}
