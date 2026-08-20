// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 575: Ashen Weather Particles, Whisperer Enemy & Whispering Wind Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenWeatherParticleFXSubsystem.h"
#include "AshenWhispererEnemy.h"
#include "AshenWhisperingWindEmitterComponent.h"

// =============================================================================
//  Test 1: Weather Particle FX Subsystem — Spawn FX
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWeatherParticleFXSubsystemTest,
	"AshenOath.WeatherParticle.Subsystem.SpawnFX",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWeatherParticleFXSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenWeatherParticleFXSubsystem* WeatherSys = NewObject<UAshenWeatherParticleFXSubsystem>();
	if (!TestNotNull(TEXT("WeatherParticleFXSubsystem must be constructable"), WeatherSys)) return false;

	const FName WeatherTag(TEXT("Weather.AshStorm"));
	WeatherSys->SpawnWeatherParticleFX(WeatherTag, 1.5f);
	TestEqual(TEXT("CurrentActiveWeatherTag must match"), WeatherSys->CurrentActiveWeatherTag, WeatherTag);

	return true;
}

// =============================================================================
//  Test 2: Whisperer Enemy — Shadow Phase
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWhispererEnemyPhaseTest,
	"AshenOath.Whisperer.Enemy.ShadowPhase",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWhispererEnemyPhaseTest::RunTest(const FString& Parameters)
{
	AAshenWhispererEnemy* Whisperer = NewObject<AAshenWhispererEnemy>();
	if (!TestNotNull(TEXT("WhispererEnemy must be constructable"), Whisperer)) return false;

	Whisperer->TriggerShadowPhase(false);
	TestFalse(TEXT("bIsPhasedIn must equal false"), Whisperer->bIsPhasedIn);

	return true;
}

// =============================================================================
//  Test 3: Whispering Wind Emitter Component — Emit Cue
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWhisperingWindEmitterTest,
	"AshenOath.WhisperingWind.Component.EmitCue",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWhisperingWindEmitterTest::RunTest(const FString& Parameters)
{
	UAshenWhisperingWindEmitterComponent* Emitter = NewObject<UAshenWhisperingWindEmitterComponent>();
	if (!TestNotNull(TEXT("WhisperingWindEmitterComponent must be constructable"), Emitter)) return false;

	Emitter->EmitWhisperCue(FName(TEXT("Whisper.BetrayalWarning")), 1.2f);
	TestEqual(TEXT("TotalWhispersEmitted must equal 1"), Emitter->TotalWhispersEmitted, 1);

	return true;
}
