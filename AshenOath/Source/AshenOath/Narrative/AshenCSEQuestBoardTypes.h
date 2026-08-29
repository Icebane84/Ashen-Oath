// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenCSEQuestBoardTypes.generated.h"

/**
 * ECognitiveDissonanceTier
 * 
 * Party psychological synchronization state.
 */
UENUM(BlueprintType)
enum class ECognitiveDissonanceTier : uint8
{
	HarmonicConsensus      UMETA(DisplayName = "Harmonic Consensus (D < 0.25: +30% Synergy Dmg, Instant Assists)"),
	PhilosophicalFriction  UMETA(DisplayName = "Philosophical Friction (0.25 <= D <= 0.50: Balanced Dialogue)"),
	IdeologicalDivergence  UMETA(DisplayName = "Ideological Divergence (0.51 <= D <= 0.75: +20% Tandem Stamina Drain)"),
	PsychologicalFracture  UMETA(DisplayName = "Psychological Fracture (D > 0.75: Radical Ultimatums, Map Anomalies)")
};

/**
 * EDissonanceQuestCategory
 * 
 * Archetypes of dynamic psychological contracts.
 */
UENUM(BlueprintType)
enum class EDissonanceQuestCategory : uint8
{
	ContradictionTrial    UMETA(DisplayName = "Contradiction Trial (Unredacted Historical Relics)"),
	CompanionDivergence   UMETA(DisplayName = "Companion Divergence (Garrett vs Serafina Ultimatums)"),
	MemoryReintegration   UMETA(DisplayName = "Memory Re-Integration (Overland Anomaly Crucibles)")
};

/**
 * EQuestResolutionOutcome
 * 
 * Outcome branch chosen for a resolved contract.
 */
UENUM(BlueprintType)
enum class EQuestResolutionOutcome : uint8
{
	PendingActive        UMETA(DisplayName = "Pending Active"),
	ResolvedGarrettPragmatic UMETA(DisplayName = "Resolved Garrett (Pragmatic Survival Doctrine)"),
	ResolvedSerafinaDogmatic UMETA(DisplayName = "Resolved Serafina (Radiant Orthodoxy Doctrine)"),
	TranscendedConsensus     UMETA(DisplayName = "Transcended Consensus (Unified Synthesis)")
};

/**
 * FCognitiveStateVector
 * 
 * 3-axis cognitive alignment weights for a single perspective [0.0 to 1.0].
 */
USTRUCT(BlueprintType)
struct FCognitiveStateVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|CSE")
	float Pragmatism = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|CSE")
	float Dogma = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|CSE")
	float HistoricalTruth = 0.5f;
};

/**
 * FDissonanceQuestContract
 * 
 * Dynamic psychological contract definition.
 */
USTRUCT(BlueprintType)
struct FDissonanceQuestContract
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|CSE")
	FName ContractId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|CSE")
	FText Title = FText::GetEmpty();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|CSE")
	EDissonanceQuestCategory Category = EDissonanceQuestCategory::ContradictionTrial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|CSE")
	float DissonanceThreshold = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|CSE")
	EQuestResolutionOutcome Outcome = EQuestResolutionOutcome::PendingActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|CSE")
	bool bIsCompleted = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCognitiveDissonanceShifted, float, DissonanceIndex, ECognitiveDissonanceTier, DissonanceTier);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDissonanceQuestGenerated, const FDissonanceQuestContract&, NewContract);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDissonanceQuestResolved, FName, ContractId, EQuestResolutionOutcome, Outcome);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionAlignmentUpdated, float, GarrettPragmatism, float, SerafinaDogma);
