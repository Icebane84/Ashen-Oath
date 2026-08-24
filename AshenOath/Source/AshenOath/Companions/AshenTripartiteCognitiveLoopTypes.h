// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenTripartiteCognitiveLoopTypes.generated.h"

/**
 * ETripartiteBehaviorMode
 * 
 * Macro cognitive states of the Kaelen-Garrett-Serafina tripartite party loop.
 */
UENUM(BlueprintType)
enum class ETripartiteBehaviorMode : uint8
{
	CombatEngagement       UMETA(DisplayName = "Combat Engagement (High-Velocity Flank & Sync)"),
	ContemplativeSilence   UMETA(DisplayName = "Contemplative Silence (Exploration / Stride Match)"),
	TraumaAftermath        UMETA(DisplayName = "Trauma Aftermath (Wordless Avoidance / Distance)"),
	CampfireRestoration    UMETA(DisplayName = "Campfire Restoration (Multi-Author Marginalia Rest)")
};

/**
 * ECompanionAttunementPhase
 * 
 * Resonance tiers between Kaelen, Garrett, and Serafina.
 */
UENUM(BlueprintType)
enum class ECompanionAttunementPhase : uint8
{
	FracturedDivergence UMETA(DisplayName = "Fractured Divergence (Attunement < 0.30)"),
	GuardedAlignment    UMETA(DisplayName = "Guarded Alignment (Attunement 0.30-0.70)"),
	UnifiedResonance    UMETA(DisplayName = "Unified Resonance (Attunement >= 0.70)")
};

/**
 * FTripartiteAttunementVector
 * 
 * Runtime diagnostic telemetry for the tripartite companion cognitive loop.
 */
USTRUCT(BlueprintType)
struct FTripartiteAttunementVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tripartite")
	ETripartiteBehaviorMode ActiveMode = ETripartiteBehaviorMode::CombatEngagement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tripartite")
	ECompanionAttunementPhase AttunementPhase = ECompanionAttunementPhase::GuardedAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tripartite")
	float TripartiteAttunementScore = 0.50f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tripartite")
	float GarrettFlankAngleDegrees = 90.0f; // Relative flank offset

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tripartite")
	float SerafinaSupportDistanceUU = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tripartite")
	bool bSilenceContractMaintained = true;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTripartiteModeChanged, ETripartiteBehaviorMode, NewMode, ECompanionAttunementPhase, NewPhase);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttunementScoreUpdated, float, NewScore, float, FinisherDamageMultiplier);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEQSSpatialCoordinatesShifted, float, GarrettFlankAngle, float, SerafinaDistance);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTripartiteFinisherReady, bool, bIsReady);
