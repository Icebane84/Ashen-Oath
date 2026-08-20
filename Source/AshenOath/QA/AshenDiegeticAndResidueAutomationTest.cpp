// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 470: Ashen Diegetic Armor Damage & Emotional Residue Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDiegeticArmorDamageSubsystem.h"
#include "AshenUserWidget_ArmorDamageHUD.h"
#include "AshenCompanionEmotionalResidueComponent.h"
#include "GA_SerafinaRadiantPurgeNova.h"

// =============================================================================
//  Test 1: Diegetic Armor Damage Subsystem — Limb Damage & Query
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDiegeticArmorDamageSubsystemTest,
	"AshenOath.ArmorDamage.Subsystem.LimbDamage",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenDiegeticArmorDamageSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenDiegeticArmorDamageSubsystem* Armor = NewObject<UAshenDiegeticArmorDamageSubsystem>();
	if (!TestNotNull(TEXT("DiegeticArmorDamageSubsystem must be constructable"), Armor)) return false;

	const FName LimbSlot(TEXT("Chestplate"));
	Armor->ApplyArmorLimbDamage(LimbSlot, 30.0f);
	TestEqual(TEXT("Chestplate integrity must equal 70.0"), Armor->GetLimbArmorIntegrity(LimbSlot), 70.0f);

	return true;
}

// =============================================================================
//  Test 2: Companion Emotional Residue Component — Accumulation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenEmotionalResidueComponentTest,
	"AshenOath.EmotionalResidue.Component.Accumulate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenEmotionalResidueComponentTest::RunTest(const FString& Parameters)
{
	UAshenCompanionEmotionalResidueComponent* Residue = NewObject<UAshenCompanionEmotionalResidueComponent>();
	if (!TestNotNull(TEXT("CompanionEmotionalResidueComponent must be constructable"), Residue)) return false;

	const FName CompanionID(TEXT("Companion_Garrett"));
	Residue->AccumulateEmotionalResidue(CompanionID, 25.0f);
	TestEqual(TEXT("CalculatedTotalResidue must equal 25.0"), Residue->CalculatedTotalResidue, 25.0f);

	return true;
}

// =============================================================================
//  Test 3: Serafina Radiant Purge Nova — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDiegeticRadiantPurgeNovaClassTest,
	"AshenOath.GAS.SerafinaRadiantPurgeNova.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenDiegeticRadiantPurgeNovaClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_SerafinaRadiantPurgeNova"));
	TestNotNull(TEXT("UGA_SerafinaRadiantPurgeNova must be registered in UObject system"), AbilityClass);
	return true;
}
