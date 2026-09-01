// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenMasterCutTypes.h"
#include "Combat/GA_AshenStrike_MasterCuts.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. AUTOMATION TEST: Master Cuts Strike Parameters & Armor Penetration
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterCutsParametersTest,
	"AshenOath.Combat.MasterCuts.StrikeParameters",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterCutsParametersTest::RunTest(const FString& Parameters)
{
	// 1. Zornhau (Wrath Hew)
	UGA_AshenStrike_Zornhau* Zornhau = NewObject<UGA_AshenStrike_Zornhau>();
	TestNotNull(TEXT("Zornhau ability instantiated"), Zornhau);
	if (Zornhau)
	{
		const FAshenStrikeParameters& P = Zornhau->GetStrikeParameters();
		TestEqual(TEXT("Zornhau BaseDamage"), P.BaseDamage, 85.0f);
		TestEqual(TEXT("Zornhau PoiseDamage"), P.PoiseDamage, 50.0f);
		TestEqual(TEXT("Zornhau WindowDuration is 115 BPM Invariant (0.15s)"), P.WindowDurationSeconds, 0.15f);
	}

	// 2. Krumphau (Crooked Hew)
	UGA_AshenStrike_Krumphau* Krumphau = NewObject<UGA_AshenStrike_Krumphau>();
	TestNotNull(TEXT("Krumphau ability instantiated"), Krumphau);
	if (Krumphau)
	{
		const FAshenStrikeParameters& P = Krumphau->GetStrikeParameters();
		TestEqual(TEXT("Krumphau high poise damage (shield break)"), P.PoiseDamage, 75.0f);
	}

	// 3. Mordhau (Pommel Strike)
	UGA_AshenStrike_Mordhau* Mordhau = NewObject<UGA_AshenStrike_Mordhau>();
	TestNotNull(TEXT("Mordhau ability instantiated"), Mordhau);
	if (Mordhau)
	{
		const FAshenStrikeParameters& P = Mordhau->GetStrikeParameters();
		TestEqual(TEXT("Mordhau 100% Armor Penetration"), P.ArmorPenetrationFraction, 1.0f);
		TestEqual(TEXT("Mordhau massive blunt poise damage"), P.PoiseDamage, 120.0f);
	}

	return true;
}

// -----------------------------------------------------------------------------
// 2. AUTOMATION TEST: Guard Transition Chain Validity
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterCutsGuardChainTest,
	"AshenOath.Combat.MasterCuts.GuardTransitionChain",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterCutsGuardChainTest::RunTest(const FString& Parameters)
{
	// Zwerchhau self-chaining (horizontal helicopter loop)
	UGA_AshenStrike_Zwerchhau* Zwerchhau = NewObject<UGA_AshenStrike_Zwerchhau>();
	TestNotNull(TEXT("Zwerchhau ability instantiated"), Zwerchhau);
	if (Zwerchhau)
	{
		const FAshenStrikeParameters& P = Zwerchhau->GetStrikeParameters();
		TestTrue(TEXT("Zwerchhau requires Ochs guard tag"), P.RequiredGuardTag.MatchesTag(FGameplayTag::RequestGameplayTag(FName("State.Stance.Ochs"))));
		TestTrue(TEXT("Zwerchhau chains back to Ochs guard tag"), P.NextGuardTag.MatchesTag(FGameplayTag::RequestGameplayTag(FName("State.Stance.Ochs"))));
	}

	// Scheitelhau downward cut chains to Pflug
	UGA_AshenStrike_Scheitelhau* Scheitelhau = NewObject<UGA_AshenStrike_Scheitelhau>();
	TestNotNull(TEXT("Scheitelhau ability instantiated"), Scheitelhau);
	if (Scheitelhau)
	{
		const FAshenStrikeParameters& P = Scheitelhau->GetStrikeParameters();
		TestTrue(TEXT("Scheitelhau requires Vom Tag"), P.RequiredGuardTag.MatchesTag(FGameplayTag::RequestGameplayTag(FName("State.Stance.VomTag"))));
		TestTrue(TEXT("Scheitelhau chains to Pflug"), P.NextGuardTag.MatchesTag(FGameplayTag::RequestGameplayTag(FName("State.Stance.Pflug"))));
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
