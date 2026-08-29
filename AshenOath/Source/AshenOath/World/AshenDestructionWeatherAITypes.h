// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenDestructionWeatherAITypes.generated.h"

/**
 * EAtmosphericVisibilityTier
 * 
 * Visibility categories dictating lock-on range and AI perception cones.
 */
UENUM(BlueprintType)
enum class EAtmosphericVisibilityTier : uint8
{
	ClearDaylight    UMETA(DisplayName = "Clear Daylight (1500uu Lock-On, 2000uu AI Sight, 90 deg FoV)"),
	AcidRainMist     UMETA(DisplayName = "Acid Rain Mist (1100uu Lock-On, 1400uu AI Sight, 75 deg FoV)"),
	VolcanicAshStorm UMETA(DisplayName = "Volcanic Ash Storm (750uu Lock-On, 900uu AI Sight, 55 deg FoV)"),
	BlizzardWhiteout UMETA(DisplayName = "Blizzard Whiteout (500uu Lock-On, 600uu AI Sight, 45 deg FoV)")
};

/**
 * EConductiveSurfaceType
 * 
 * Material conductivity for electrical chain-lightning propagation.
 */
UENUM(BlueprintType)
enum class EConductiveSurfaceType : uint8
{
	NonConductiveStone UMETA(DisplayName = "Non-Conductive Dry Stone"),
	WetAcidPuddle      UMETA(DisplayName = "Wet Acid Rain Puddle (High Conductivity, 350uu Arc)"),
	MetallicIronRubble UMETA(DisplayName = "Metallic Iron Debris (High Conductivity, 350uu Arc)"),
	HeavyMetalArmor    UMETA(DisplayName = "Heavy Metal Armor (Electrified Target)")
};

/**
 * EAIPincerManeuverState
 * 
 * Tactical coordination state of AI squads navigating cleaved obstacles.
 */
UENUM(BlueprintType)
enum class EAIPincerManeuverState : uint8
{
	DirectApproach  UMETA(DisplayName = "Direct Approach (No Obstruction)"),
	HoldingCover    UMETA(DisplayName = "Holding Defensive Rubble Cover"),
	FlankingLeft    UMETA(DisplayName = "Flanking Left Vector (-65 deg)"),
	FlankingRight   UMETA(DisplayName = "Flanking Right Vector (+65 deg)"),
	ElevatedPerch   UMETA(DisplayName = "Taking Elevated Rubble Sightline")
};

/**
 * FWeatherPerceptionVector
 * 
 * Real-time perception and lock-on bounds under current weather conditions.
 */
USTRUCT(BlueprintType)
struct FWeatherPerceptionVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	EAtmosphericVisibilityTier VisibilityTier = EAtmosphericVisibilityTier::ClearDaylight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	float MaxLockOnRangeUU = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	float AISightRadiusUU = 2000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	float AIVisionConeDegrees = 90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	bool bStealthAmbushEligible = false;
};

/**
 * FConductiveArcTargetInfo
 * 
 * Target data for electrical chain-lightning propagation.
 */
USTRUCT(BlueprintType)
struct FConductiveArcTargetInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	AActor* TargetActor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	FVector Location = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	EConductiveSurfaceType SurfaceType = EConductiveSurfaceType::NonConductiveStone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	float ShockDamage = 350.0f;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeatherPerceptionClamped, EAtmosphericVisibilityTier, Tier, float, LockOnRange);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnConductiveLightningArced, FVector, Origin, int32, TargetsChained, float, TotalDamage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRubbleChokepointFormed, FVector, ObstacleLocation, float, ObstacleRadius);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCoverShattered, FVector, ShatterLocation, float, ShrapnelDamage);
