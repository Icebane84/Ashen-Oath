// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenParasiticBladeTypes.generated.h"

/**
 * EBladeParasiteState
 * 
 * Consciousness and corruption state of Oathbringer's parasitic bond.
 */
UENUM(BlueprintType)
enum class EBladeParasiteState : uint8
{
	DormantSteel        UMETA(DisplayName = "Dormant Steel (Low Corruption < 30%)"),
	AwakenedWhispers    UMETA(DisplayName = "Awakened Whispers (Eldrin Active 30%-70%)"),
	ParasiticOvercharge UMETA(DisplayName = "Parasitic Overcharge (Nyx Dominance > 70%)"),
	GloomwoodFrozen     UMETA(DisplayName = "Gloomwood Frozen (Chemically Stabilized)")
};

/**
 * EPommelGazeTarget
 * 
 * Target entity tracked by the garnet wolf-head pommel eyes.
 */
UENUM(BlueprintType)
enum class EPommelGazeTarget : uint8
{
	KaelenFace      UMETA(DisplayName = "Kaelen (Introspective Guilt)"),
	ClosestThreat   UMETA(DisplayName = "Closest Enemy Threat"),
	GarrettSentinel UMETA(DisplayName = "Garrett (Paranoid Suspicion)"),
	SerafinaWarden  UMETA(DisplayName = "Serafina (Transference Predation)")
};

/**
 * EGloomwoodStabilizationTier
 * 
 * Alchemical efficacy tier of Garrett's Gloomwood Sap Needle.
 */
UENUM(BlueprintType)
enum class EGloomwoodStabilizationTier : uint8
{
	StandardSap     UMETA(DisplayName = "Standard Sap (8s Freeze, -12 Semitones)"),
	ConcentratedSap UMETA(DisplayName = "Concentrated Sap (12s Freeze, -18 Semitones)"),
	PurifiedElixir  UMETA(DisplayName = "Purified Elixir (16s Freeze, Debt Reduction)")
};

/**
 * FOathbringerParasiticVector
 * 
 * Live telemetry and physical state of the parasitic greatsword.
 */
USTRUCT(BlueprintType)
struct FOathbringerParasiticVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Blade")
	float Corruption01 = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Blade")
	float BladeMassKg = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Blade")
	float SwingDragPlayRate = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Blade")
	float PommelGlowEmissive = 0.10f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Blade")
	EBladeParasiteState State = EBladeParasiteState::DormantSteel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Blade")
	bool bGloomwoodFrozen = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Blade")
	float GloomwoodTimeRemainingSeconds = 0.0f;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnParasiteStateChanged, EBladeParasiteState, NewState, float, Corruption01);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEldrinWhisperTriggered, const FText&, WhisperText, float, VolumeMultiplier);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGloomwoodNeedleInjected, float, FreezeDurationSeconds);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBladeMassRecalculated, float, NewMassKg);
