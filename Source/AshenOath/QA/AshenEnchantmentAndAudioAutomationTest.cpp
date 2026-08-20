// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 225: Ashen Weapon Enchantment & Audio Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenWeaponEnchantmentComponent.h"
#include "GA_GarrettGrapplingHook.h"
#include "AshenAudioDynamicOcclusionSubsystem.h"
#include "AshenUserWidget_WeaponEnchantmentSlot.h"

// =============================================================================
//  Test 1: Weapon Enchantment Component — Infusion & Damage
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWeaponInfusionTest,
	"AshenOath.Weapon.Enchantment.InfusionApplication",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWeaponInfusionTest::RunTest(const FString& Parameters)
{
	UAshenWeaponEnchantmentComponent* Comp = NewObject<UAshenWeaponEnchantmentComponent>();
	if (!TestNotNull(TEXT("WeaponEnchantmentComponent must be constructable"), Comp)) return false;

	Comp->ApplyEnchantment(FName(TEXT("Element.HolyFire")), 40.0f);
	TestEqual(TEXT("Bonus damage must be 40.0"), Comp->ActiveBonusDamage, 40.0f);

	return true;
}

// =============================================================================
//  Test 2: Garrett Grappling Hook — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGrapplingHookClassTest,
	"AshenOath.GAS.GarrettGrapple.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGrapplingHookClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_GarrettGrapplingHook"));
	TestNotNull(TEXT("UGA_GarrettGrapplingHook must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Audio Dynamic Occlusion — Cutoff Frequencies
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAudioOcclusionFrequencyTest,
	"AshenOath.Audio.DynamicOcclusion.CutoffFrequencies",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAudioOcclusionFrequencyTest::RunTest(const FString& Parameters)
{
	UAshenAudioDynamicOcclusionSubsystem* Sub = NewObject<UAshenAudioDynamicOcclusionSubsystem>();
	if (!TestNotNull(TEXT("AudioDynamicOcclusionSubsystem must be constructable"), Sub)) return false;

	TestEqual(TEXT("MaxCutoffFrequency must default to 20000 Hz"), Sub->MaxCutoffFrequency, 20000.0f);
	TestEqual(TEXT("MinCutoffFrequency must default to 800 Hz"), Sub->MinCutoffFrequency, 800.0f);

	return true;
}

// =============================================================================
//  Test 4: Weapon Enchantment Slot Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWeaponEnchantmentSlotWidgetTest,
	"AshenOath.UI.WeaponEnchantmentSlotWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWeaponEnchantmentSlotWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_WeaponEnchantmentSlot* Slot = NewObject<UAshenUserWidget_WeaponEnchantmentSlot>();
	if (!TestNotNull(TEXT("WeaponEnchantmentSlot widget must be constructable"), Slot)) return false;

	Slot->UpdateInfusionSlot(EAshenElementInfusion::HolyFire, 12.5f, 35.0f);
	TestEqual(TEXT("CurrentInfusion must be HolyFire"), Slot->CurrentInfusion, EAshenElementInfusion::HolyFire);
	TestEqual(TEXT("CurrentRemainingDuration must be 12.5"), Slot->CurrentRemainingDuration, 12.5f);
	TestEqual(TEXT("CurrentBonusDamage must be 35.0"), Slot->CurrentBonusDamage, 35.0f);

	return true;
}

// =============================================================================
//  Test 5: Weapon Enchantment Component — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWeaponEnchantmentReflectionTest,
	"AshenOath.Weapon.Enchantment.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWeaponEnchantmentReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenWeaponEnchantmentComponent class must be valid"),
		UAshenWeaponEnchantmentComponent::StaticClass() != nullptr);
	return true;
}
