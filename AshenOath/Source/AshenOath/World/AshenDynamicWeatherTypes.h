// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenDynamicWeatherTypes.generated.h"

/**
 * EWeatherHazardState
 * 
 * Active weather hazard states in the dynamic ecosystem.
 */
UENUM(BlueprintType)
enum class EWeatherHazardState : uint8
{
	ClearTemperate     UMETA(DisplayName = "Clear Temperate (Safe Baseline)"),
	BlizzardWhiteout   UMETA(DisplayName = "Blizzard Whiteout (-35°C, 400uu Visibility, -30% Speed)"),
	VolcanicAshStorm   UMETA(DisplayName = "Volcanic Ash Storm (Choking Soot, -25% Stamina Regen)"),
	AcidRainCorrosion  UMETA(DisplayName = "Acid Rain Corrosion (-2.5%/s Armor Durability, +35% Vulnerability)"),
	LightningSurge     UMETA(DisplayName = "Lightning Surge (Ionization Telegraphs, 850 Dmg Strikes)")
};

/**
 * EAtmosphericSeverity
 * 
 * Intensity level of the prevailing weather hazard.
 */
UENUM(BlueprintType)
enum class EAtmosphericSeverity : uint8
{
	MildDrift    UMETA(DisplayName = "Mild Drift (1.0x Intensity)"),
	ModerateGale UMETA(DisplayName = "Moderate Gale (1.5x Intensity)"),
	SevereCataclysm UMETA(DisplayName = "Severe Cataclysm (2.5x Intensity, Extreme Danger)")
};

/**
 * EWeatherShelterType
 * 
 * Environmental protection categories against weather hazards.
 */
UENUM(BlueprintType)
enum class EWeatherShelterType : uint8
{
	ExposedWilds    UMETA(DisplayName = "Exposed Wilds (0% Protection)"),
	CavernOverhang  UMETA(DisplayName = "Cavern Overhang (75% Rain/Lightning Protection)"),
	HearthSanctuary UMETA(DisplayName = "Hearth Sanctuary (100% Total Hazard Immunity)")
};

/**
 * FWeatherAtmosphericVector
 * 
 * Real-time atmospheric telemetry and climate metrics.
 */
USTRUCT(BlueprintType)
struct FWeatherAtmosphericVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	EWeatherHazardState WeatherState = EWeatherHazardState::ClearTemperate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	EAtmosphericSeverity Severity = EAtmosphericSeverity::MildDrift;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	float TemperatureCelsius = 18.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	float VisibilityDistanceUU = 5000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	float WindShearVelocityMps = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	float AcidCorrosionRatePerSec = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	float LightningChargeBuildup01 = 0.0f;
};

/**
 * FLightningStrikeHazardVector
 * 
 * Data vector for an impending localized lightning hazard strike.
 */
USTRUCT(BlueprintType)
struct FLightningStrikeHazardVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	FVector StrikeLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	float TelegraphRadiusUU = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	float TimeUntilImpactSeconds = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	float StrikeDamage = 850.0f;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeatherStateChanged, EWeatherHazardState, NewState, float, Temperature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLightningTelegraphed, const FLightningStrikeHazardVector&, StrikeHazard);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShelterStatusChanged, EWeatherShelterType, ShelterType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHazardDamageApplied, EWeatherHazardState, Hazard, float, DamageAmount);
