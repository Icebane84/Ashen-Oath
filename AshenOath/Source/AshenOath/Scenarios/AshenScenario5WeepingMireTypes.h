// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenScenario5WeepingMireTypes.generated.h"

/**
 * EUnchainedVesselPhase
 * 
 * Phases of Kaelen's Unchained state in the Weeping Mire.
 */
UENUM(BlueprintType)
enum class EUnchainedVesselPhase : uint8
{
	Dormant UMETA(DisplayName = "Dormant (Standard Combat)"),
	UnchainedFrenzy UMETA(DisplayName = "Unchained Frenzy (+50% Damage, 140 BPM Haptics)"),
	ExhaustedVulnerable UMETA(DisplayName = "Exhausted Vulnerable (Companion Boundary Defense Active)")
};

/**
 * EWeepingMireHazardType
 * 
 * Environmental hazard types in the Weeping Mire.
 */
UENUM(BlueprintType)
enum class EWeepingMireHazardType : uint8
{
	DeepMudSludge UMETA(DisplayName = "Deep Mud Sludge (0.50x Locomotion Speed)"),
	VolatileGasPocket UMETA(DisplayName = "Volatile Gas Pocket (Flammable Methane)"),
	SubmergedRootSnare UMETA(DisplayName = "Submerged Root Snare (Transient Root)")
};

/**
 * ECompanionBoundaryDefenseState
 * 
 * Companion protective state during Kaelen's exhaustion window.
 */
UENUM(BlueprintType)
enum class ECompanionBoundaryDefenseState : uint8
{
	Inactive UMETA(DisplayName = "Inactive (Normal AI Tracking)"),
	InterceptionPerimeter UMETA(DisplayName = "Interception Perimeter (Shielding Kaelen)"),
	CounterStrike UMETA(DisplayName = "Counter Strike (Repelling Swarm)")
};

/**
 * FMireMudLocomotionContext
 * 
 * Movement penalty parameters in mud zones.
 */
USTRUCT(BlueprintType)
struct FMireMudLocomotionContext
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario5")
	float MudFrictionCoefficient = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario5")
	float StaminaDrainPerSecond = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario5")
	bool bInDeepMud = false;
};

/**
 * FUnchainedCombatTelemetry
 * 
 * Telemetry profile during Unchained activation.
 */
USTRUCT(BlueprintType)
struct FUnchainedCombatTelemetry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario5")
	float DamageMultiplier = 1.50f; // +50%

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario5")
	float HeartRateBPM = 140.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario5")
	float FrenzyRemainingSeconds = 12.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario5")
	int32 GasPocketsDetonated = 0;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnchainedPhaseChanged, EUnchainedVesselPhase, NewPhase);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGasPocketIgnited, const FName&, PocketId, float, DetonationRadius);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBoundaryDefenseTriggered, ECompanionBoundaryDefenseState, State, float, DefenseRadius);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeepingMireCleared, bool, bZeroCompanionDowned);
