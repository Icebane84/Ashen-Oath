// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 785: Ashen Oathbringer Upgrade & Cleave Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenOathbringerRunicEngravingComponent.h"
#include "AshenOathbringerHeavyOverheadCleaveAbility.h"
#include "AshenOathbringerResonanceSynergyCalculator.h"

// =============================================================================
//  Test 1: Oathbringer Runic Engraving Component — Engrave Rune
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenOathbringerRunicEngravingComponentTest,
	"AshenOath.RunicEngraving.Component.EngraveRune",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenOathbringerRunicEngravingComponentTest::RunTest(const FString& Parameters)
{
	UAshenOathbringerRunicEngravingComponent* RuneComp = NewObject<UAshenOathbringerRunicEngravingComponent>();
	if (!TestNotNull(TEXT("OathbringerRunicEngravingComponent must be constructable"), RuneComp)) return false;

	RuneComp->EngraveHolyRune(FName(TEXT("Rune.HolyNova")), 50.0f);
	TestEqual(TEXT("ActiveEngravedRune must match Rune.HolyNova"), RuneComp->ActiveEngravedRune, FName(TEXT("Rune.HolyNova")));

	return true;
}

// =============================================================================
//  Test 2: Oathbringer Heavy Overhead Cleave Ability — Execute Ability
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenOathbringerHeavyOverheadCleaveAbilityTest,
	"AshenOath.OathbringerAbilities.Ability.HeavyOverheadCleave",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenOathbringerHeavyOverheadCleaveAbilityTest::RunTest(const FString& Parameters)
{
	UAshenOathbringerHeavyOverheadCleaveAbility* Ability = NewObject<UAshenOathbringerHeavyOverheadCleaveAbility>();
	if (!TestNotNull(TEXT("OathbringerHeavyOverheadCleaveAbility must be constructable"), Ability)) return false;

	Ability->ExecuteHeavyOverheadCleave(nullptr, 500.0f);
	return true;
}

// =============================================================================
//  Test 3: Oathbringer Resonance Synergy Calculator — Calculate Buff
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenOathbringerResonanceSynergyCalculatorTest,
	"AshenOath.ResonanceSynergy.Calculator.CalculateBuff",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenOathbringerResonanceSynergyCalculatorTest::RunTest(const FString& Parameters)
{
	UAshenOathbringerResonanceSynergyCalculator* Calc = NewObject<UAshenOathbringerResonanceSynergyCalculator>();
	if (!TestNotNull(TEXT("OathbringerResonanceSynergyCalculator must be constructable"), Calc)) return false;

	const float Buff = Calc->CalculateResonancePartyBuff(100.0f);
	TestEqual(TEXT("Max resonance party buff must equal 30.0%"), Buff, 30.0f);

	return true;
}
