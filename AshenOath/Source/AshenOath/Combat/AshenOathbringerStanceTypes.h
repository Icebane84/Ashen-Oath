// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenOathbringerStanceTypes.generated.h"

/**
 * EOathbringerMartialStance
 * 
 * The 4 historical greatsword martial guards of Oathbringer.
 */
UENUM(BlueprintType)
enum class EOathbringerMartialStance : uint8
{
	VomTag_HighWrath   UMETA(DisplayName = "Vom Tag: High Wrath Guard (Overhead Cleaves, +40% Poise Dmg, Crimson Seam)"),
	Pflug_LowPlow      UMETA(DisplayName = "Pflug: Low Plow Guard (Lunging Thrusts, -30% Stamina Cost, White Flame Seam)"),
	Ochs_CrownGuard    UMETA(DisplayName = "Ochs: Crown Guard (Deflection Counter-Binds, +0.12s Parry Window, Gold Seam)"),
	Mordhau_HalfSword  UMETA(DisplayName = "Mordhau: Half-Sword & Pommel (100% Armor Penetration, Shield Shatter, Umbral Seam)")
};

/**
 * EFlowChainingTimingQuality
 * 
 * Timing precision when executing stance transitions during attack recoveries.
 */
UENUM(BlueprintType)
enum class EFlowChainingTimingQuality : uint8
{
	MissedTiming   UMETA(DisplayName = "Missed Timing (Full Recovery & Standard Stamina Drain)"),
	FlowGlintClean UMETA(DisplayName = "Flow Glint Clean (0 Stamina Cost, +25% Momentum Buff, +15 Flow Charge)")
};

/**
 * FOathbringerStanceKinematics
 * 
 * Combat and physical parameters for an active stance.
 */
USTRUCT(BlueprintType)
struct FOathbringerStanceKinematics
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Oathbringer")
	EOathbringerMartialStance Stance = EOathbringerMartialStance::VomTag_HighWrath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Oathbringer")
	float DamageMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Oathbringer")
	float PoiseDamageMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Oathbringer")
	float StaminaCost = 25.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Oathbringer")
	float ParryWindowSeconds = 0.10f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Oathbringer")
	float ArmorPenetrationPercent = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Oathbringer")
	FLinearColor RunicSeamColor = FLinearColor::White;
};

/**
 * FFlowChainingWindowData
 * 
 * Active timing bounds for stamina-neutral recovery canceling.
 */
USTRUCT(BlueprintType)
struct FFlowChainingWindowData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Oathbringer")
	bool bWindowActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Oathbringer")
	float WindowStartSeconds = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Oathbringer")
	float WindowDurationSeconds = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Oathbringer")
	float CurrentFlowCharge = 0.0f;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOathbringerStanceChanged, EOathbringerMartialStance, NewStance, const FOathbringerStanceKinematics&, Kinematics);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFlowChainingGlintTriggered, EFlowChainingTimingQuality, Quality, float, FlowChargeGranted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRunicSeamColorUpdated, FLinearColor, SeamColor, float, EmissiveIntensity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCounterBindParryLanded, EOathbringerMartialStance, Stance, float, RiposteDamageBonus);
