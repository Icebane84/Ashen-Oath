// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenScenario8Types.generated.h"

/**
 * ELightEnvironmentState
 * 
 * Environmental illumination state in the subterranean catacombs.
 */
UENUM(BlueprintType)
enum class ELightEnvironmentState : uint8
{
	RadiantIlluminated  UMETA(DisplayName = "Radiant Illuminated (>600uu Light)"),
	FlickeringDim       UMETA(DisplayName = "Flickering Dim (250uu-600uu Light)"),
	GloomPerimeter      UMETA(DisplayName = "Gloom Perimeter (100uu-250uu Light)"),
	PitchBlackDarkness  UMETA(DisplayName = "Pitch Black Darkness (<100uu - Complete Blindness)")
};

/**
 * EEcholocationPulseType
 * 
 * Acoustic impulse type propagating through the catacombs.
 */
UENUM(BlueprintType)
enum class EEcholocationPulseType : uint8
{
	FootstepEcho       UMETA(DisplayName = "Footstep Echo (350uu Radius)"),
	BladeClangEcho     UMETA(DisplayName = "Blade Clang Echo (900uu Radius)"),
	GroundSlamSonar    UMETA(DisplayName = "Ground Slam Sonar (1800uu Radius)"),
	RadiantFlarePulse  UMETA(DisplayName = "Radiant Flare Pulse (1200uu Radius)")
};

/**
 * EAbyssLurkerAlertState
 * 
 * AI behavior alert state for subterranean abyss lurkers.
 */
UENUM(BlueprintType)
enum class EAbyssLurkerAlertState : uint8
{
	DormantSleeping  UMETA(DisplayName = "Dormant Sleeping in Shadows"),
	StalkingPrey     UMETA(DisplayName = "Stalking Prey in Darkness"),
	FleeingLight     UMETA(DisplayName = "Fleeing Radiant Flare"),
	AmbushLunging    UMETA(DisplayName = "Ambush Lunging from Darkness")
};

/**
 * FAbyssDarknessVector
 * 
 * Telemetry and illumination state in Scenario 8.
 */
USTRUCT(BlueprintType)
struct FAbyssDarknessVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario8")
	float TorchFuelPercent01 = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario8")
	float EffectiveLightRadiusUU = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario8")
	float DarknessAccuracyPenalty01 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario8")
	float SonarActiveRadiusUU = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario8")
	ELightEnvironmentState LightState = ELightEnvironmentState::RadiantIlluminated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario8")
	bool bInRadiantFlare = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTorchFuelChanged, float, NewFuel01, float, NewLightRadiusUU);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEcholocationPingEmitted, EEcholocationPulseType, PulseType, FVector, PingOrigin, float, PropagationRadiusUU);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLightEnvironmentChanged, ELightEnvironmentState, NewState, float, AccuracyPenalty01);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRadiantFlareTriggered, float, FlareDuration);
