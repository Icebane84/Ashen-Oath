// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenScenario9Types.generated.h"

/**
 * EVoidGravityZoneTier
 * 
 * Localized gravitational field tier in the floating archipelago.
 */
UENUM(BlueprintType)
enum class EVoidGravityZoneTier : uint8
{
	StandardGravity     UMETA(DisplayName = "Standard Gravity (1.00g)"),
	LowVoidGravity      UMETA(DisplayName = "Low Void Gravity (0.35g - High Jump)"),
	ZeroGOrbitalDrift   UMETA(DisplayName = "Zero-G Orbital Drift (0.10g - Float)"),
	HyperGravitonWell   UMETA(DisplayName = "Hyper Graviton Well (1.50g - Heavy Crush)")
};

/**
 * EWindShearGustState
 * 
 * Atmospheric wind shear state across the high-altitude citadel chasms.
 */
UENUM(BlueprintType)
enum class EWindShearGustState : uint8
{
	CalmBreeze          UMETA(DisplayName = "Calm Breeze (5-15 m/s)"),
	GaleShearWarning    UMETA(DisplayName = "Gale Shear Warning (20-30 m/s - Gust Building)"),
	ViolentWindShear    UMETA(DisplayName = "Violent Wind Shear (35-50 m/s - Destabilizing)"),
	VortexMaelstrom     UMETA(DisplayName = "Vortex Maelstrom (Void Turbulence)")
};

/**
 * ETelekineticBridgeStatus
 * 
 * Resonant light bridge integrity state.
 */
UENUM(BlueprintType)
enum class ETelekineticBridgeStatus : uint8
{
	InactiveClosed      UMETA(DisplayName = "Inactive Closed Chasm"),
	ChannelingForming   UMETA(DisplayName = "Channeling Forming Bridge"),
	StableActive        UMETA(DisplayName = "Stable Active Resonant Bridge"),
	DecayingDissolving  UMETA(DisplayName = "Decaying Dissolving Bridge")
};

/**
 * FWhisperingCitadelVector
 * 
 * Telemetry and environmental physics vector in Scenario 9.
 */
USTRUCT(BlueprintType)
struct FWhisperingCitadelVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario9")
	float GravityScale = 0.35f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario9")
	float WindSpeedMps = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario9")
	FVector WindDirection = FVector(1.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario9")
	float BridgeStability01 = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario9")
	EVoidGravityZoneTier GravityTier = EVoidGravityZoneTier::LowVoidGravity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario9")
	EWindShearGustState WindState = EWindShearGustState::CalmBreeze;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario9")
	ETelekineticBridgeStatus BridgeStatus = ETelekineticBridgeStatus::StableActive;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGravityZoneChanged, EVoidGravityZoneTier, NewTier, float, GravityScale);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnWindShearGustTriggered, EWindShearGustState, WindState, float, WindSpeedMps, FVector, WindDirection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTelekineticBridgeStateChanged, ETelekineticBridgeStatus, Status, float, Stability01);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGravitonCleaveExecuted, float, ImpactJoules);
