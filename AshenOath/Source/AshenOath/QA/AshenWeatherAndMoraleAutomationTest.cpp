// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 530: Ashen Weather & Party Morale Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenEnvironmentalWeatherAtmosphereSubsystem.h"
#include "AshenUserWidget_WeatherAtmosphereHUD.h"
#include "AshenPartyMoralResonanceSubsystem.h"
#include "GA_KaelenHolyAvengerCleaveExecution.h"

// =============================================================================
//  Test 1: Environmental Weather Atmosphere Subsystem — Modulate Weather
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWeatherAtmosphereSubsystemTest,
	"AshenOath.Weather.Subsystem.ModulateWeather",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWeatherAtmosphereSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenEnvironmentalWeatherAtmosphereSubsystem* Weather = NewObject<UAshenEnvironmentalWeatherAtmosphereSubsystem>();
	if (!TestNotNull(TEXT("EnvironmentalWeatherAtmosphereSubsystem must be constructable"), Weather)) return false;

	Weather->ModulateWeatherForCorruption(50.0f); // 50% corruption -> 800u wind velocity
	return true;
}

// =============================================================================
//  Test 2: Party Moral Resonance Subsystem — Alignment Shift
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPartyMoralResonanceSubsystemTest,
	"AshenOath.PartyMorale.Subsystem.RegisterChoice",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPartyMoralResonanceSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenPartyMoralResonanceSubsystem* Morale = NewObject<UAshenPartyMoralResonanceSubsystem>();
	if (!TestNotNull(TEXT("PartyMoralResonanceSubsystem must be constructable"), Morale)) return false;

	const FName AlignmentTag(TEXT("Moral.SelflessSacrifice"));
	Morale->RegisterMoralChoiceResolution(AlignmentTag, 0.25f);
	TestEqual(TEXT("CalculatedPartyMoraleMultiplier must equal 1.25"), Morale->CalculatedPartyMoraleMultiplier, 1.25f);

	return true;
}

// =============================================================================
//  Test 3: Kaelen Holy Avenger Cleave Execution — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenHolyAvengerCleaveClassTest,
	"AshenOath.GAS.KaelenHolyAvengerCleaveExecution.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenHolyAvengerCleaveClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenHolyAvengerCleaveExecution"));
	TestNotNull(TEXT("UGA_KaelenHolyAvengerCleaveExecution must be registered in UObject system"), AbilityClass);
	return true;
}
