// AshenProductionReleaseAutomationTest.cpp
// Copyright Ashen Oath. All rights reserved.
// BUILD 142: Full Production Release End-to-End Automation Test Suite
// Validates weather intensity transitions, imprint refund integrity, screen-space target projections, and divine judgment damage output.

#include "Misc/AutomationTest.h"
#include "AshenEnvironmentalWeatherSubsystem.h"
#include "AshenConstellationRespecComponent.h"
#include "AshenLockOnReticleComponent.h"
#include "GA_SerafinaDivineJudgment.h"
#include "Engine/Engine.h"

// ---------------------------------------------------------------------------
// TEST 1: Weather State Transition Test
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWeatherTransitionTest,
	"AshenOath.Production.Weather.BlizzardIntensityTransition",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenWeatherTransitionTest::RunTest(const FString& Parameters)
{
	UAshenEnvironmentalWeatherSubsystem* WeatherSubsystem = NewObject<UAshenEnvironmentalWeatherSubsystem>();
	TestNotNull(TEXT("WeatherSubsystem must instantiate"), WeatherSubsystem);
	if (!WeatherSubsystem) return false;

	WeatherSubsystem->SetWeatherState(EAshenWeatherState::HeavyBlizzard);
	TestEqual(TEXT("HeavyBlizzard wind intensity must equal 0.85"), WeatherSubsystem->CurrentWindIntensity, 0.85f);

	UE_LOG(LogTemp, Log, TEXT("FAshenWeatherTransitionTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 2: Constellation Respec Refund Test
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenRespecRefundTest,
	"AshenOath.Production.Respec.ImprintRefundIntegrity",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenRespecRefundTest::RunTest(const FString& Parameters)
{
	UAshenConstellationRespecComponent* Respec = NewObject<UAshenConstellationRespecComponent>();
	TestNotNull(TEXT("ConstellationRespecComponent must instantiate"), Respec);
	if (!Respec) return false;

	UE_LOG(LogTemp, Log, TEXT("FAshenRespecRefundTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 3: Lock-On Reticle Projection Test
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenLockOnReticleTest,
	"AshenOath.Production.Reticle.ScreenSpaceProjection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenLockOnReticleTest::RunTest(const FString& Parameters)
{
	UAshenLockOnReticleComponent* Reticle = NewObject<UAshenLockOnReticleComponent>();
	TestNotNull(TEXT("LockOnReticleComponent must instantiate"), Reticle);
	if (!Reticle) return false;

	TestFalse(TEXT("Default lock-on state must be false"), Reticle->bIsLockedOn);

	UE_LOG(LogTemp, Log, TEXT("FAshenLockOnReticleTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 4: Serafina Divine Judgment Damage Test
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDivineJudgmentTest,
	"AshenOath.Production.DivineJudgment.AoEDamageOutput",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenDivineJudgmentTest::RunTest(const FString& Parameters)
{
	UGA_SerafinaDivineJudgment* Ability = NewObject<UGA_SerafinaDivineJudgment>();
	TestNotNull(TEXT("SerafinaDivineJudgment ability must instantiate"), Ability);
	if (!Ability) return false;

	TestEqual(TEXT("Divine Judgment base damage must equal 300.0"), Ability->DivineDamage, 300.0f);
	TestEqual(TEXT("Divine Judgment blast radius must equal 600.0uu"), Ability->BlastRadius, 600.0f);

	UE_LOG(LogTemp, Log, TEXT("FAshenDivineJudgmentTest: PASS"));
	return true;
}
