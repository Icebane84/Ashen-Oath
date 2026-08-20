// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenMassKineticTypes.generated.h"

// -----------------------------------------------------------------------------------
// MASS KINETIC & CLEAVE ENUMS (KINETIC-SPEC-060)
// -----------------------------------------------------------------------------------

UENUM(BlueprintType)
enum class EKineticCleaveStance : uint8
{
	LightInnerFlame       UMETA(DisplayName = "Light Inner Flame (45kg Agile Longsword)"),
	DarkShadowUnleashed   UMETA(DisplayName = "Dark Shadow Unleashed (180kg Nightsteel Greatsword)")
};

UENUM(BlueprintType)
enum class EStructuralFractureTier : uint8
{
	SurfaceChipping       UMETA(DisplayName = "Surface Chipping (< 1500 Joules)"),
	StructuralCrack       UMETA(DisplayName = "Structural Crack (1500 - 4500 Joules)"),
	CatastrophicCleave    UMETA(DisplayName = "Catastrophic Cleave (> 4500 Joules)")
};

// -----------------------------------------------------------------------------------
// MASS KINETIC & CLEAVE STRUCTS
// -----------------------------------------------------------------------------------

/**
 * Real-time calculation snapshot of a weapon swing's kinetic energy and velocity.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FKineticSwingSnapshot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinetic")
	FString SwingId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinetic")
	EKineticCleaveStance Stance = EKineticCleaveStance::LightInnerFlame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinetic")
	float WeaponMassKG = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinetic")
	float BladeTipVelocity = 0.0f; // cm/s

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinetic")
	float KineticEnergyJoules = 0.0f; // Ek = 0.5 * m * v^2

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinetic")
	EStructuralFractureTier FractureTier = EStructuralFractureTier::SurfaceChipping;
};

/**
 * Real-time calculation of volume resistance drag when cleaving through solid matter.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FVolumeDragResult
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinetic")
	float SubmergedVolumeCM3 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinetic")
	float AdjustedAnimPlayRate = 1.0f; // Clamped to [0.08, 1.0]

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinetic")
	float CompressedFOV = 90.0f; // Clamped to [76.0, 90.0]

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinetic")
	bool bShearedThroughMatter = false;
};

// -----------------------------------------------------------------------------------
// MULTICAST DELEGATES
// -----------------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKineticSwingCalculated, const FKineticSwingSnapshot&, Snapshot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVolumeDragUpdated, const FVolumeDragResult&, DragResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStructuralDestructionTriggered, const FVector&, Location, float, EnergyJoules);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnKineticDeflectionSuccessful, float, ImpactAngle, float, AttackerPostureDamage);
