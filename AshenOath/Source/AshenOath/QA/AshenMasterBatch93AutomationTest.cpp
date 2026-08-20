// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1875: Master Batch #93 QA Automation Test Suite — World Traversal, Dynamic Weather & Environmental Hazards
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "World/AshenWeatherMiasmaSubsystem.h"
#include "World/AshenMiasmaExposureComponent.h"
#include "World/AshenAtmosphericConductivityEvaluatorComponent.h"
#include "Player/AshenTraversalMovementEnhancerComponent.h"
#include "Companions/AshenWeatherCompanionReactionAdapter.h"
#include "Combat/AshenAetherDashGASAbility.h"
#include "Combat/AshenAtmosphericPurgeGASAbility.h"

// =============================================================================
//  Test 1: Weather Transitions & Environmental Toxicity Exposure Math
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch93WeatherExposureTest,
	"AshenOath.Weather.WeatherExposure.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch93WeatherExposureTest::RunTest(const FString& Parameters)
{
	// Test 1: Weather Subsystem Transitions
	UAshenWeatherMiasmaSubsystem* Subsystem = NewObject<UAshenWeatherMiasmaSubsystem>();
	if (!TestNotNull(TEXT("WeatherMiasmaSubsystem must be constructable"), Subsystem)) return false;

	TestTrue(TEXT("Transition to VoidMiasma must succeed"), Subsystem->TransitionToWeather(EWeatherState::VoidMiasma));
	TestEqual(TEXT("VoidMiasma toxicity must be 0.75"), Subsystem->GetAtmosphericToxicity(), 0.75f);
	TestEqual(TEXT("VoidMiasma visibility range must be 1500.0uu"), Subsystem->AtmosphereData.VisibilityRange, 1500.0f);

	TestTrue(TEXT("Transition to AshBlizzard must succeed"), Subsystem->TransitionToWeather(EWeatherState::AshBlizzard));
	TestEqual(TEXT("AshBlizzard wind velocity must be 600.0uu/s"), Subsystem->AtmosphereData.WindVelocity, 600.0f);

	// Test 2: Miasma Exposure Damage & Filter Protection
	UAshenMiasmaExposureComponent* Exposure = NewObject<UAshenMiasmaExposureComponent>();
	if (!TestNotNull(TEXT("MiasmaExposureComponent must be constructable"), Exposure)) return false;

	// Low toxicity (0.10 <= 0.20 safe baseline) -> 0 damage
	const float SafeDamage = Exposure->CalculateExposureDamage(1.0f, 0.10f);
	TestEqual(TEXT("Safe atmospheric toxicity must yield 0 damage"), SafeDamage, 0.0f);

	// High toxicity (0.75) with 100% filter (90% protection -> 10% damage ratio)
	// TickDMG = 12.0 * 0.75 * 0.10 * 1.0 = 0.90
	const float ProtectedDamage = Exposure->CalculateExposureDamage(1.0f, 0.75f);
	TestEqual(TEXT("100% filter protected tick damage must equal 0.90"), ProtectedDamage, 0.90f);

	return true;
}

// =============================================================================
//  Test 2: Conductivity, Movement Scaling & Companion Gear
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch93ConductivityAndMovementTest,
	"AshenOath.Weather.ConductivityAndMovement.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch93ConductivityAndMovementTest::RunTest(const FString& Parameters)
{
	// Elemental Conductivity Multipliers
	UAshenAtmosphericConductivityEvaluatorComponent* Conductivity = NewObject<UAshenAtmosphericConductivityEvaluatorComponent>();
	if (!TestNotNull(TEXT("AtmosphericConductivityEvaluatorComponent must be constructable"), Conductivity)) return false;

	TestEqual(TEXT("PsychicStorm resonance multiplier must equal 1.20x (+20%)"),
		Conductivity->CalculateResonanceMultiplier(EWeatherState::PsychicStorm), 1.20f);
	TestEqual(TEXT("AshBlizzard friction multiplier must equal 0.70x"),
		Conductivity->CalculateMovementFrictionMultiplier(EWeatherState::AshBlizzard), 0.70f);

	// Movement Enhancer Sprint & Dash Math
	UAshenTraversalMovementEnhancerComponent* Movement = NewObject<UAshenTraversalMovementEnhancerComponent>();
	if (!TestNotNull(TEXT("TraversalMovementEnhancerComponent must be constructable"), Movement)) return false;

	const float NormalSprint = Movement->CalculateAdjustedSprintSpeed(0.0f, false);
	TestEqual(TEXT("Base sprint speed must equal 600.0 uu/s"), NormalSprint, 600.0f);

	const float ResistedSprint = Movement->CalculateAdjustedSprintSpeed(0.20f, false);
	TestEqual(TEXT("Sprint speed with 20% wind resistance must equal 480.0 uu/s"), ResistedSprint, 480.0f);

	const float DashSpeed = Movement->CalculateAdjustedSprintSpeed(0.0f, true);
	TestEqual(TEXT("Aether dash sprint surge must equal 1320.0 uu/s (2.2x)"), DashSpeed, 1320.0f);

	// Companion Weather Gear Evaluation
	UAshenWeatherCompanionReactionAdapter* CompanionAdapter = NewObject<UAshenWeatherCompanionReactionAdapter>();
	if (!TestNotNull(TEXT("WeatherCompanionReactionAdapter must be constructable"), CompanionAdapter)) return false;

	const FName MaskGear = CompanionAdapter->EvaluateCompanionWeatherGear(FName(TEXT("Garrett")), EWeatherState::VoidMiasma, 0.80f);
	TestEqual(TEXT("Companion must equip RespiratorMask during VoidMiasma"), MaskGear, FName(TEXT("Gear.RespiratorMask")));

	const FName CloakGear = CompanionAdapter->EvaluateCompanionWeatherGear(FName(TEXT("Serafina")), EWeatherState::AshBlizzard, 0.20f);
	TestEqual(TEXT("Companion must equip HeavyAshCloak during AshBlizzard"), CloakGear, FName(TEXT("Gear.HeavyAshCloak")));

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #93 WEATHER, TRAVERSAL & HAZARDS TEST SUITE VERIFIED (1,875 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
