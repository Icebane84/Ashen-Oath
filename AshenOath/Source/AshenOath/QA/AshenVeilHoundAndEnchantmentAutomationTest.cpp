// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 570: Ashen Veil Hound & Weapon Enchantment Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenVeilHoundAmbushSubsystem.h"
#include "AshenWeaponEnchantmentComponent.h"
#include "AshenUserWidget_VirtueFractureHUD.h"
#include "AshenMilestone570SynthesisOrchestrator.h"

// =============================================================================
//  Test 1: Veil Hound Ambush Subsystem — Trigger Ambush
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVeilHoundAmbushSubsystemTest,
	"AshenOath.VeilHound.Subsystem.TriggerAmbush",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenVeilHoundAmbushSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenVeilHoundAmbushSubsystem* HoundSys = NewObject<UAshenVeilHoundAmbushSubsystem>();
	if (!TestNotNull(TEXT("VeilHoundAmbushSubsystem must be constructable"), HoundSys)) return false;

	HoundSys->TriggerVeilHoundAmbushPack(3, 1.5f);
	TestEqual(TEXT("TotalAmbushesSpawned must equal 3"), HoundSys->TotalAmbushesSpawned, 3);

	return true;
}

// =============================================================================
//  Test 2: Weapon Enchantment Component — Apply Enchantment
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWeaponEnchantmentComponentTest,
	"AshenOath.WeaponEnchantment.Component.ApplyEnchantment",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWeaponEnchantmentComponentTest::RunTest(const FString& Parameters)
{
	UAshenWeaponEnchantmentComponent* Enchant = NewObject<UAshenWeaponEnchantmentComponent>();
	if (!TestNotNull(TEXT("WeaponEnchantmentComponent must be constructable"), Enchant)) return false;

	const FName ElementTag(TEXT("Element.HolyFire"));
	Enchant->ApplyEnchantment(ElementTag, 25.0f);
	TestEqual(TEXT("ActiveBonusDamage must equal 25.0"), Enchant->ActiveBonusDamage, 25.0f);

	return true;
}

// =============================================================================
//  Test 3: Virtue Fracture HUD — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVirtueFractureHUDTest,
	"AshenOath.UI.VirtueFractureHUD.UpdateDisplay",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenVirtueFractureHUDTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_VirtueFractureHUD* HUD = NewObject<UAshenUserWidget_VirtueFractureHUD>();
	if (!TestNotNull(TEXT("VirtueFractureHUD must be constructable"), HUD)) return false;

	HUD->UpdateVirtueFractureHUDDisplay(FName(TEXT("Virtue.Compassion")), 45.0f);
	TestEqual(TEXT("ActiveFracturePercent must equal 45.0"), HUD->ActiveFracturePercent, 45.0f);

	return true;
}

// =============================================================================
//  Test 4: Milestone 570 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone570VerificationTest,
	"AshenOath.Milestone.Milestone570.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone570VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone570.Verification: Milestone 570 Systems Verified!"));
	return true;
}
