// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenCombatKinematicsTypes.generated.h"

/**
 * EAshenWeightClass
 * 
 * Equipment load weight class determining dodge velocity, i-frame windows, and stamina consumption.
 */
UENUM(BlueprintType)
enum class EAshenWeightClass : uint8
{
	LightLoad     UMETA(DisplayName = "Light Load (<30% Load: Agile Ninja Roll, 0.28s i-Frames, 15 Stamina)"),
	MediumLoad    UMETA(DisplayName = "Medium Load (30-70% Load: Tactical Roll, 0.24s i-Frames, 20 Stamina)"),
	HeavyLoad     UMETA(DisplayName = "Heavy Load (71-100% Load: Fat Roll, 0.16s i-Frames, 35 Stamina, Camera Shake)"),
	Overburdened  UMETA(DisplayName = "Overburdened (>100% Load: Stumble Hop, 0.05s i-Frames, 50 Stamina)")
};

/**
 * EPoiseStaggerState
 * 
 * Target posture and guard break state.
 */
UENUM(BlueprintType)
enum class EPoiseStaggerState : uint8
{
	SolidGuard     UMETA(DisplayName = "Solid Guard (Normal Poise Regeneration)"),
	UnsteadyGuard  UMETA(DisplayName = "Unsteady Guard (<30% Poise, Increased Stagger Vulnerability)"),
	PoiseBroken    UMETA(DisplayName = "Poise Broken (Guard Shattered, 0.20s Hitstop Time Dilation)"),
	RiposteVulnerable UMETA(DisplayName = "Riposte Vulnerable (+50% Critical Damage Window)")
};

/**
 * EParryRiposteQuality
 * 
 * Timing precision tiers of deflection and parrying.
 */
UENUM(BlueprintType)
enum class EParryRiposteQuality : uint8
{
	MissedDeflection  UMETA(DisplayName = "Missed Deflection (Full Damage & Poise Taken)"),
	GlancingBlock     UMETA(DisplayName = "Glancing Block (50% Damage Mitigated)"),
	StandardParry     UMETA(DisplayName = "Standard Parry (100% Damage Mitigated, Minor Enemy Stagger)"),
	PerfectRiposte    UMETA(DisplayName = "Perfect Riposte (+50 Stamina, +35 White Flame, +25% Riposte Dmg)")
};

/**
 * FDodgeScalingParameters
 * 
 * Precise mathematical parameters configured for each weight class.
 */
USTRUCT(BlueprintType)
struct FDodgeScalingParameters
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	float RollDurationSeconds = 0.40f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	float IFrameDurationSeconds = 0.24f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	float StaminaCost = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	float LaunchForce = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	float ImpactCameraTrauma = 0.0f;
};

/**
 * FCombatKinematicsVector
 * 
 * Real-time state vector linking equipment weight, stamina pulse, poise, and deflection buffs.
 */
USTRUCT(BlueprintType)
struct FCombatKinematicsVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	float CurrentEquipmentWeightKg = 25.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	float MaxEquipLoadKg = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	EAshenWeightClass WeightClass = EAshenWeightClass::MediumLoad;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	bool bInCardiacExhaustion = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	float SwingWindupSlowdown = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	EPoiseStaggerState StaggerState = EPoiseStaggerState::SolidGuard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	bool bRiposteBuffActive = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeightClassChanged, EAshenWeightClass, NewWeightClass, float, WeightRatio);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCardiacExhaustionToggled, bool, bIsExhausted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPoiseBreakTriggered, AActor*, BrokenActor, float, HitstopDilation);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPerfectParrySurgeTriggered, float, StaminaRestored, float, WhiteFlameGain, float, RiposteBonusDmg);
