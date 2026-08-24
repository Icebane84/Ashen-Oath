// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenShroudKnightTypes.generated.h"

/**
 * EShroudKnightPhaseState
 * 
 * Physical or spectral intangibility state of the Shroud-Knight.
 */
UENUM(BlueprintType)
enum class EShroudKnightPhaseState : uint8
{
	PhysicalSolid     UMETA(DisplayName = "Physical Solid (100% Opacity, Standard Collision)"),
	SpectralPhasing   UMETA(DisplayName = "Spectral Phasing (15% Dither Opacity, Wall Passable)"),
	ThreadAnchored    UMETA(DisplayName = "Thread Anchored (Phase Lockout by Garrett)"),
	TrinityVulnerable UMETA(DisplayName = "Trinity Vulnerable (Poise Broken for Purge)")
};

/**
 * EParanoiaInfectionTier
 * 
 * Sensory distortion level inflicted on Kaelen.
 */
UENUM(BlueprintType)
enum class EParanoiaInfectionTier : uint8
{
	ClearMind       UMETA(DisplayName = "Clear Mind (0%-25% Infection)"),
	PeripheralEchoes UMETA(DisplayName = "Peripheral Echoes (25%-50% Infection, Vanishing Phantoms)"),
	VignetteTerror  UMETA(DisplayName = "Vignette Terror (50%-75% Infection, Chromatic Jitter)"),
	FullPsychosis   UMETA(DisplayName = "Full Psychosis (>75% Infection, Hallucinatory Paranoia)")
};

/**
 * ETrinityStrikeStep
 * 
 * Step progression in the 3-Way Trinity Strike finisher.
 */
UENUM(BlueprintType)
enum class ETrinityStrikeStep : uint8
{
	None              UMETA(DisplayName = "None / Ready"),
	KaelenGuardBreak  UMETA(DisplayName = "Step 1: Kaelen Kinetic Guard Break (Heavy Strike)"),
	GarrettThreadLock UMETA(DisplayName = "Step 2: Garrett Shadow Thread Anchor"),
	SerafinaPurgeBeam UMETA(DisplayName = "Step 3: Serafina White Flame Purge (3.5x Finisher)")
};

/**
 * FShroudKnightBossVector
 * 
 * Live telemetry and combat state of the Shroud-Knight encounter.
 */
USTRUCT(BlueprintType)
struct FShroudKnightBossVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	float HealthPercent = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	float ParanoiaInfection01 = 0.10f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	float DitherOpacity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	EShroudKnightPhaseState PhaseState = EShroudKnightPhaseState::PhysicalSolid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	EParanoiaInfectionTier ParanoiaTier = EParanoiaInfectionTier::ClearMind;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	ETrinityStrikeStep TrinityStep = ETrinityStrikeStep::None;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShroudKnightPhaseChanged, EShroudKnightPhaseState, NewPhase, float, DitherOpacity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnParanoiaInfectionChanged, float, Infection01, EParanoiaInfectionTier, Tier);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTrinityStrikeProgressed, ETrinityStrikeStep, CurrentStep);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTrinityStrikeCompleted, float, FinisherDamage, bool, bBossDefeated);
