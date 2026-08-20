// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 590: Ashen Armor Scuff, Atmospheric Sanity & Boss Death Cinematic Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenArmorScuffDecalSubsystem.h"
#include "AshenAtmosphericSanityModifierVolume.h"
#include "AshenBossDeathCinematicDirectorSubsystem.h"

// =============================================================================
//  Test 1: Armor Scuff Decal Subsystem — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenArmorScuffSubsystemClassTest,
	"AshenOath.ArmorScuff.Subsystem.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenArmorScuffSubsystemClassTest::RunTest(const FString& Parameters)
{
	UClass* SubClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.AshenArmorScuffDecalSubsystem"));
	TestNotNull(TEXT("UAshenArmorScuffDecalSubsystem must be registered in UObject system"), SubClass);
	return true;
}

// =============================================================================
//  Test 2: Atmospheric Sanity Modifier Volume — Evaluate Drain
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAtmosphericSanityVolumeTest,
	"AshenOath.SanityVolume.Volume.EvaluateDrain",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAtmosphericSanityVolumeTest::RunTest(const FString& Parameters)
{
	AAshenAtmosphericSanityModifierVolume* Vol = NewObject<AAshenAtmosphericSanityModifierVolume>();
	if (!TestNotNull(TEXT("AtmosphericSanityModifierVolume must be constructable"), Vol)) return false;

	Vol->EvaluateSanityDrainModifier(50.0f);
	TestEqual(TEXT("CurrentDrainMultiplier must equal 2.0"), Vol->CurrentDrainMultiplier, 2.0f);

	return true;
}

// =============================================================================
//  Test 3: Boss Death Cinematic Director Subsystem — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossDeathCinematicClassTest,
	"AshenOath.BossCinematic.Subsystem.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossDeathCinematicClassTest::RunTest(const FString& Parameters)
{
	UClass* SubClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.AshenBossDeathCinematicDirectorSubsystem"));
	TestNotNull(TEXT("UAshenBossDeathCinematicDirectorSubsystem must be registered in UObject system"), SubClass);
	return true;
}
