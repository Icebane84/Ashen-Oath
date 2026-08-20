// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 186: Ashen Utility & Ability Systems Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenFastTravelSubsystem.h"
#include "AshenQuickUseBeltComponent.h"
#include "GA_KaelenWhirlwindSlash.h"
#include "GA_GarrettSmokeScreen.h"
#include "AshenSanityFilterPostProcessComponent.h"
#include "AshenUserWidget_QuickBelt.h"

// =============================================================================
//  Test 1: Fast Travel Subsystem — Registration & Unlocking
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFastTravelUnlockTest,
	"AshenOath.Systems.FastTravel.UnlockSanctuary",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFastTravelUnlockTest::RunTest(const FString& Parameters)
{
	UAshenFastTravelSubsystem* Subsystem = NewObject<UAshenFastTravelSubsystem>();
	if (!TestNotNull(TEXT("FastTravelSubsystem must be constructable"), Subsystem)) return false;

	const FName TestSanctuary(TEXT("Campfire_FrozenTarn"));
	Subsystem->RegisterSanctuary(TestSanctuary, FVector(100.0f, 200.0f, 300.0f), false);

	TestFalse(TEXT("Sanctuary must initially be locked"), Subsystem->IsSanctuaryUnlocked(TestSanctuary));

	Subsystem->UnlockSanctuary(TestSanctuary);
	TestTrue(TEXT("Sanctuary must be unlocked after UnlockSanctuary call"), Subsystem->IsSanctuaryUnlocked(TestSanctuary));

	TestEqual(TEXT("Unlocked count must be 1"), Subsystem->GetUnlockedSanctuaries().Num(), 1);

	return true;
}

// =============================================================================
//  Test 2: Quick-Use Belt Component — Slot Cycling
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenQuickBeltCyclingTest,
	"AshenOath.Systems.QuickBelt.SlotCycling",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenQuickBeltCyclingTest::RunTest(const FString& Parameters)
{
	UAshenQuickUseBeltComponent* Belt = NewObject<UAshenQuickUseBeltComponent>();
	if (!TestNotNull(TEXT("QuickUseBeltComponent must be constructable"), Belt)) return false;

	TestEqual(TEXT("Initial active slot must be 0"), Belt->GetActiveSlotIndex(), 0);

	Belt->CycleSlot(true); // Next slot -> 1
	TestEqual(TEXT("Active slot must be 1 after CycleSlot(true)"), Belt->GetActiveSlotIndex(), 1);

	Belt->CycleSlot(false); // Prev slot -> 0
	TestEqual(TEXT("Active slot must be 0 after CycleSlot(false)"), Belt->GetActiveSlotIndex(), 0);

	Belt->CycleSlot(false); // Wrap backwards -> 3
	TestEqual(TEXT("Active slot must wrap to 3 on backward cycle from 0"), Belt->GetActiveSlotIndex(), 3);

	return true;
}

// =============================================================================
//  Test 3: Kaelen Whirlwind Slash — Class Registration
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWhirlwindSlashClassTest,
	"AshenOath.GAS.KaelenWhirlwind.ClassRegistration",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWhirlwindSlashClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenWhirlwindSlash"));
	TestNotNull(TEXT("UGA_KaelenWhirlwindSlash must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 4: Sanity Filter Component — Distortion Calculation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSanityFilterDistortionTest,
	"AshenOath.Systems.SanityFilter.DistortionCalculation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSanityFilterDistortionTest::RunTest(const FString& Parameters)
{
	UAshenSanityFilterPostProcessComponent* Filter = NewObject<UAshenSanityFilterPostProcessComponent>();
	if (!TestNotNull(TEXT("SanityFilterPostProcessComponent must be constructable"), Filter)) return false;

	// Full sanity = 0% distortion
	Filter->UpdateFilterFromSanity(100.0f, 100.0f);
	TestEqual(TEXT("Full sanity must produce 0.0 distortion intensity"), Filter->GetCurrentDistortionIntensity(), 0.0f);

	// Zero sanity = 100% (1.0) distortion
	Filter->UpdateFilterFromSanity(0.0f, 100.0f);
	TestEqual(TEXT("Zero sanity must produce 1.0 distortion intensity"), Filter->GetCurrentDistortionIntensity(), 1.0f);

	// Half sanity = 50% (0.5) distortion
	Filter->UpdateFilterFromSanity(50.0f, 100.0f);
	TestEqual(TEXT("Half sanity must produce 0.5 distortion intensity"), Filter->GetCurrentDistortionIntensity(), 0.5f);

	return true;
}

// =============================================================================
//  Test 5: Quick-Belt UI Widget — Active Highlight
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenQuickBeltWidgetHighlightTest,
	"AshenOath.UI.QuickBeltWidget.Highlight",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenQuickBeltWidgetHighlightTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_QuickBelt* Widget = NewObject<UAshenUserWidget_QuickBelt>();
	if (!TestNotNull(TEXT("QuickBelt widget must be constructable"), Widget)) return false;

	Widget->SetActiveSlotHighlight(2);
	TestEqual(TEXT("Current active slot must be 2"), Widget->CurrentActiveSlot, 2);

	return true;
}
