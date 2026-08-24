// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenScenario7Types.generated.h"

/**
 * ECalderaSurgePhase
 * 
 * Eruption cycle state for volcanic caldera magma hazards.
 */
UENUM(BlueprintType)
enum class ECalderaSurgePhase : uint8
{
	DormantCalm       UMETA(DisplayName = "Dormant Calm (Low Heat Hazard)"),
	TelegraphWarning  UMETA(DisplayName = "Telegraph Warning (Ground Fissure Glowing)"),
	ActiveEruption    UMETA(DisplayName = "Active Eruption (Magma Geyser Lethal)"),
	CoolingDissipation UMETA(DisplayName = "Cooling Dissipation (Steam Venting)")
};

/**
 * EHeatExhaustionTier
 * 
 * Somatic heat exhaustion state of the character.
 */
UENUM(BlueprintType)
enum class EHeatExhaustionTier : uint8
{
	Comfortable   UMETA(DisplayName = "Comfortable (<30% Heat Exhaustion)"),
	Dehydrated    UMETA(DisplayName = "Dehydrated (30%-60% Heat - 1.3x Stamina Drain)"),
	Heatstroke    UMETA(DisplayName = "Heatstroke (60%-90% Heat - 1.7x Stamina Drain)"),
	Incinerating  UMETA(DisplayName = "Incinerating (>90% Heat - Continuous Burn Dmg)")
};

/**
 * ETemperedBladeState
 * 
 * Molten tempering progression of Kaelen's weapon.
 */
UENUM(BlueprintType)
enum class ETemperedBladeState : uint8
{
	ColdSteel     UMETA(DisplayName = "Cold Steel (Standard Physical Damage)"),
	MoltenHeated  UMETA(DisplayName = "Molten Heated (+40% Fire Dmg, Obsidian Piercing)"),
	Overheated    UMETA(DisplayName = "Overheated (Degrading Blade Integrity)"),
	QuenchedSafe  UMETA(DisplayName = "Quenched Safe (Tempering Hardened)")
};

/**
 * FCalderaThermodynamicsVector
 * 
 * Telemetry and environmental thermodynamic state in Scenario 7.
 */
USTRUCT(BlueprintType)
struct FCalderaThermodynamicsVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario7")
	float AmbientCalderaTempC = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario7")
	float HeatExhaustion01 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario7")
	float StaminaDrainMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario7")
	float BladeTemperedHeatC = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario7")
	ETemperedBladeState BladeState = ETemperedBladeState::ColdSteel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario7")
	ECalderaSurgePhase SurgePhase = ECalderaSurgePhase::DormantCalm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario7")
	bool bInsideCoolingMist = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCalderaTemperatureChanged, float, NewTempC, float, HeatExhaustion);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMagmaSurgeStateChanged, ECalderaSurgePhase, NewPhase, FVector, SurgeLocation);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBladeTemperingStateChanged, ETemperedBladeState, NewState, float, BladeTempC);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeatExhaustionTierChanged, EHeatExhaustionTier, NewTier);
