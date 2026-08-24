// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenScenario6Types.generated.h"

/**
 * EBlizzardIntensity
 * 
 * Northern Marches blizzard weather states.
 */
UENUM(BlueprintType)
enum class EBlizzardIntensity : uint8
{
	CalmChill       UMETA(DisplayName = "Calm Chill (-5°C)"),
	DrivingSnow     UMETA(DisplayName = "Driving Snow (-15°C)"),
	SevereBlizzard  UMETA(DisplayName = "Severe Blizzard (-25°C)"),
	WhiteoutSurge   UMETA(DisplayName = "Whiteout Surge (-35°C)")
};

/**
 * EFrostbiteSeverity
 * 
 * Physiological stages of somatic freezing.
 */
UENUM(BlueprintType)
enum class EFrostbiteSeverity : uint8
{
	Normal       UMETA(DisplayName = "Normal / Warm"),
	NumbFingers  UMETA(DisplayName = "Numb Fingers (Frostbite 0.25-0.50)"),
	SlowingChill UMETA(DisplayName = "Slowing Chill (Frostbite 0.50-0.75)"),
	Hypothermia  UMETA(DisplayName = "Critical Hypothermia (Frostbite > 0.75)")
};

/**
 * EHearthSanctuaryState
 * 
 * Ignition state of the ancient Sanctified Hearth Brazier.
 */
UENUM(BlueprintType)
enum class EHearthSanctuaryState : uint8
{
	FrozenExtinguished UMETA(DisplayName = "Frozen Extinguished"),
	KindlingIgnition   UMETA(DisplayName = "Kindling Ignition"),
	SanctifiedBlaze    UMETA(DisplayName = "Sanctified Blaze (Full Sanctuary Active)")
};

/**
 * FSanctifiedHearthStateVector
 * 
 * Runtime diagnostic telemetry for Scenario 6: The Sanctified Hearth Resolution.
 */
USTRUCT(BlueprintType)
struct FSanctifiedHearthStateVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario6")
	EBlizzardIntensity BlizzardWeather = EBlizzardIntensity::DrivingSnow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario6")
	EFrostbiteSeverity FrostbiteSeverity = EFrostbiteSeverity::Normal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario6")
	float AmbientTemperatureCelsius = -15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario6")
	float FrostbiteGauge = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario6")
	float HearthIgnitionProgress = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario6")
	EHearthSanctuaryState HearthState = EHearthSanctuaryState::FrozenExtinguished;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario6")
	bool bInCompanionWarmthRadius = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBlizzardWeatherChanged, EBlizzardIntensity, NewIntensity, float, AmbientTemperature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFrostbiteUpdated, float, NewFrostbite, EFrostbiteSeverity, Severity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHearthIgnitionProgressChanged, float, NewProgress, EHearthSanctuaryState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSanctifiedHearthComplete, bool, bIsFullySanctified);
