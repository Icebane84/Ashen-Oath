// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenKineticBerserkTypes.generated.h"

/**
 * EAshenCounterAttackZone
 * 
 * 4-Zone angular counter-attack riposte directions mapped from incoming strikes.
 */
UENUM(BlueprintType)
enum class EAshenCounterAttackZone : uint8
{
	VerticalOverhead   UMETA(DisplayName = "Vertical Overhead Riposte (315° - 45°)"),
	HorizontalLeft     UMETA(DisplayName = "Left-to-Right Cleave (225° - 315°)"),
	HorizontalRight    UMETA(DisplayName = "Right-to-Left Cleave (45° - 135°)"),
	DiagonalUnderhand  UMETA(DisplayName = "Diagonal Underhand Lift (135° - 225°)")
};

/**
 * EAshenDebrisOcclusionState
 * 
 * Acoustic occlusion state of sound sources behind fractured Chaos rubble.
 */
UENUM(BlueprintType)
enum class EAshenDebrisOcclusionState : uint8
{
	Unoccluded UMETA(DisplayName = "Unoccluded (LPF 20,000 Hz)"),
	PartialDebris UMETA(DisplayName = "Partial Debris Occlusion (LPF 4,000 - 8,000 Hz)"),
	BuriedUnderRubble UMETA(DisplayName = "Buried Under Rubble (LPF 400 Hz Muffled)")
};

/**
 * EAshenTargetTrackingMode
 * 
 * Automated camera tracking mode during Berserk/Unchained states.
 */
UENUM(BlueprintType)
enum class EAshenTargetTrackingMode : uint8
{
	ManualFreeLook UMETA(DisplayName = "Manual Free Look"),
	AutomatedSphereLock UMETA(DisplayName = "Automated Sphere Lock (1200cm Sweep)")
};

/**
 * FAshenAngularCounterContext
 * 
 * Contextual data for angular counter-riposte calculation.
 */
USTRUCT(BlueprintType)
struct FAshenAngularCounterContext
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|KineticBerserk")
	FVector AttackerLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|KineticBerserk")
	FVector AttackDirection = FVector::ForwardVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|KineticBerserk")
	float ClockFaceAngleDegrees = 0.0f; // 0° to 360°

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|KineticBerserk")
	EAshenCounterAttackZone CounterZone = EAshenCounterAttackZone::VerticalOverhead;
};

/**
 * FAshenDebrisOcclusionContext
 * 
 * Diagnostic parameters for dynamic rubble audio occlusion raycasts.
 */
USTRUCT(BlueprintType)
struct FAshenDebrisOcclusionContext
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|KineticBerserk")
	int32 ObstructingDebrisCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|KineticBerserk")
	float CalculatedLowPassCutoff = 20000.0f; // 400 Hz to 20,000 Hz

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|KineticBerserk")
	EAshenDebrisOcclusionState OcclusionState = EAshenDebrisOcclusionState::Unoccluded;
};

/**
 * FAshenNiagaraShearTraceData
 * 
 * Back-face exit raycast data for geometry shearing particle instantiation.
 */
USTRUCT(BlueprintType)
struct FAshenNiagaraShearTraceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|KineticBerserk")
	FVector BladeEntryCoordinate = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|KineticBerserk")
	FVector BladeExitCoordinate = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|KineticBerserk")
	FVector ExitShearTrajectory = FVector::ForwardVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|KineticBerserk")
	float KineticEnergyJoules = 4500.0f;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAngularCounterMapped, EAshenCounterAttackZone, Zone, float, AngleDegrees);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDebrisOcclusionUpdated, float, CutoffFrequency, EAshenDebrisOcclusionState, State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlanarExitShearSpawned, const FVector&, ExitCoordinate, const FVector&, ShearVector);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetTrackingLocked, AActor*, TargetActor);
