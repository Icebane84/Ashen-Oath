// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenCompanionIntentTypes.generated.h"

// -----------------------------------------------------------------------------------
// COMPANION INTENT INFERENCE ENUMERATIONS (INTENT-SPEC-056)
// -----------------------------------------------------------------------------------

UENUM(BlueprintType)
enum class EPlayerFormationBreakIntent : uint8
{
	Unknown,
	InnocentRescue         UMETA(DisplayName = "Innocent Rescue (Self-Sacrificial Protection)"),
	TacticalFlankExploit   UMETA(DisplayName = "Tactical Flank Exploit (Seizing Vulnerability)"),
	BlindWrathAssault      UMETA(DisplayName = "Blind Wrath Assault (Ashen Mark Dysregulation)"),
	DesperateRetreat       UMETA(DisplayName = "Desperate Retreat (Breaking Under Poise Crack)")
};

UENUM(BlueprintType)
enum class ECompanionTacticalResponse : uint8
{
	ShoulderToShoulderCommit  UMETA(DisplayName = "Shoulder-To-Shoulder Commit ('Mr. Hero' Mutual Rush)"),
	CautiousFlankCompensate   UMETA(DisplayName = "Cautious Flank Compensate (Low-Trust Tactical Salvage)"),
	ConfrontationalIntervene  UMETA(DisplayName = "Confrontational Intervene (High-Trust Physical Body-Block)"),
	SynchronizedPincerStrike  UMETA(DisplayName = "Synchronized Pincer Strike (Tactical Flank Sync)"),
	DefensiveSanctuaryHold    UMETA(DisplayName = "Defensive Sanctuary Hold (Empathic Ward Leash)")
};

UENUM(BlueprintType)
enum class EIntentConfidenceTier : uint8
{
	Doubtful   UMETA(DisplayName = "Doubtful (Low Historical Precedent)"),
	Tentative  UMETA(DisplayName = "Tentative (Moderate Historical Precedent)"),
	Confident  UMETA(DisplayName = "Confident (High Historical Precedent)"),
	Absolute   UMETA(DisplayName = "Absolute (Unbreakable Pattern Continuity)")
};

// -----------------------------------------------------------------------------------
// COMPANION INTENT STRUCTS
// -----------------------------------------------------------------------------------

/**
 * Telemetry snapshot captured when Kaelen breaks formation or initiates a high-risk charge.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FPlayerIntentTelemetrySnapshot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	FString TelemetryId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	FVector PlayerVelocity = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	FVector TargetLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	bool bTargetIsInnocent = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	float PlayerStaminaRatio = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	float DistanceFromParty = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	FCanonicalSoulStateVector SoulState;
};

/**
 * Output of the companion's intent inference evaluation.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FCompanionIntentEvaluationResult
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	FName CompanionId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	EPlayerFormationBreakIntent InferredIntent = EPlayerFormationBreakIntent::Unknown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	EIntentConfidenceTier ConfidenceTier = EIntentConfidenceTier::Tentative;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	ECompanionTacticalResponse SelectedResponse = ECompanionTacticalResponse::CautiousFlankCompensate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	FGameplayTag ContextualBarkTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Intent")
	FString ContextualBarkDialogue;
};

// -----------------------------------------------------------------------------------
// MULTICAST DELEGATES
// -----------------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerFormationBreakDetected, const FPlayerIntentTelemetrySnapshot&, TelemetrySnapshot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCompanionIntentEvaluated, const FCompanionIntentEvaluationResult&, EvaluationResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShoulderToShoulderInitiated, FName, CompanionName, float, PoiseBuffScalar);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConfrontationalInterventionTriggered, FName, CompanionName, const FString&, Reason);
