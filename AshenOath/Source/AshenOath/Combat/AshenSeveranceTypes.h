// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenSeveranceTypes.generated.h"

/**
 * ESeveranceBoneTarget
 * 
 * Target anatomical bone sockets for executioner dismemberment slicing.
 */
UENUM(BlueprintType)
enum class ESeveranceBoneTarget : uint8
{
	None       UMETA(DisplayName = "None"),
	Head       UMETA(DisplayName = "Head / Neck (Decapitation)"),
	RightArm   UMETA(DisplayName = "Right Arm / Weapon Hand (Disarm)"),
	LeftArm    UMETA(DisplayName = "Left Arm / Shield Hand (Sunder)"),
	TorsoWaist UMETA(DisplayName = "Torso / Waist (Bisection)"),
	RightLeg   UMETA(DisplayName = "Right Leg (Cripple)"),
	LeftLeg    UMETA(DisplayName = "Left Leg (Cripple)")
};

/**
 * ESeveranceSeverityTier
 * 
 * Severity classification of the dismemberment event based on poise break depth and damage.
 */
UENUM(BlueprintType)
enum class ESeveranceSeverityTier : uint8
{
	MinorLimb       UMETA(DisplayName = "Minor: Hand/Forearm Severance"),
	MajorLimb       UMETA(DisplayName = "Major: Full Arm/Leg Amputation"),
	TotalBisection  UMETA(DisplayName = "Total: Complete Waist/Torso Cleave"),
	Decapitation    UMETA(DisplayName = "Apex: Clean Head Severance")
};

/**
 * EAdrenalineSurgeType
 * 
 * Somatic adrenaline buffs unlocked upon landing executioner kills.
 */
UENUM(BlueprintType)
enum class EAdrenalineSurgeType : uint8
{
	None             UMETA(DisplayName = "None"),
	StaminaRefill    UMETA(DisplayName = "Stamina Surge (+25.0 Stamina Refill)"),
	MomentumBurst    UMETA(DisplayName = "Momentum Burst (1.25x Movement Speed & Hyper-Armor)"),
	FlowEmpowerment  UMETA(DisplayName = "Flow Empowerment (+15.0 Flow Charge)")
};

/**
 * FSeveranceSlicePlaneData
 * 
 * Geometric definition of the cutting plane for dynamic procedural slicing.
 */
USTRUCT(BlueprintType)
struct FSeveranceSlicePlaneData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	FVector PlanePosition = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	FVector PlaneNormal = FVector::UpVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	FVector ImpulseDirection = FVector::ForwardVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	float ImpulseStrength = 850.0f;
};

/**
 * FSeveranceDismembermentResult
 * 
 * Output metrics following a confirmed execution slice.
 */
USTRUCT(BlueprintType)
struct FSeveranceDismembermentResult
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	bool bSeveranceExecuted = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	ESeveranceBoneTarget SeveredBone = ESeveranceBoneTarget::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	ESeveranceSeverityTier SeverityTier = ESeveranceSeverityTier::MajorLimb;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	float BloodSplatterVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	float AdrenalineGranted = 25.0f;
};

/**
 * FAdrenalineSurgeState
 * 
 * Active adrenaline buffs on the player.
 */
USTRUCT(BlueprintType)
struct FAdrenalineSurgeState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	float CurrentAdrenaline = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	float MaxAdrenaline = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	bool bHyperArmorActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance")
	float DurationRemainingSeconds = 0.0f;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSeveranceExecuted, const FSeveranceDismembermentResult&, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAdrenalineSurgeTriggered, EAdrenalineSurgeType, SurgeType, float, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBloodSplatterSpawned, FVector, Location, FVector, Direction);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNearbyAIWitnessedExecution, AActor*, ExecutedActor);
