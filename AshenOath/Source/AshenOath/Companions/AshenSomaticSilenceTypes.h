// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenSomaticSilenceTypes.generated.h"

// -----------------------------------------------------------------------------------
// SOMATIC SILENCE & INTENT ENUMERATIONS (MIND-SPEC-058)
// -----------------------------------------------------------------------------------

UENUM(BlueprintType)
enum class ESomaticSilenceClassification : uint8
{
	None,
	Contemplative           UMETA(DisplayName = "Contemplative (Calm Context, Kaelen Thinking)"),
	TraumaticAftermath      UMETA(DisplayName = "Traumatic Aftermath (Post-Combat, Processing Loss)"),
	DestabilizingCrisis     UMETA(DisplayName = "Destabilizing Crisis (Whispers Spike, Dysregulation)")
};

UENUM(BlueprintType)
enum class EWordlessSupportActionType : uint8
{
	None,
	ClearCivilianObstacle   UMETA(DisplayName = "Clear Civilian Obstacle (Debris / Rubble)"),
	MatchLocomotionPace     UMETA(DisplayName = "Match Locomotion Pace (Sync Step Cadence)"),
	TakePointShielding      UMETA(DisplayName = "Take Point Shielding (Vanguard Offset)")
};

UENUM(BlueprintType)
enum class ECompanionBoundaryState : uint8
{
	AlignedFollow           UMETA(DisplayName = "Aligned Follow (Supportive Accompaniment)"),
	HesitantStandoff        UMETA(DisplayName = "Hesitant Standoff (Verbal Warning / Distance Hold)"),
	BoundaryRefusal         UMETA(DisplayName = "Boundary Refusal (Physical Standoff Halt)")
};

// -----------------------------------------------------------------------------------
// SILENCE & INTENT STRUCTS
// -----------------------------------------------------------------------------------

/**
 * Real-time snapshot of silence classification and companion interpretation.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FSilenceEvaluationSnapshot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Silence")
	FString EvaluationId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Silence")
	ESomaticSilenceClassification Classification = ESomaticSilenceClassification::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Silence")
	float SilenceDurationSeconds = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Silence")
	float CompanionConfidence = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Silence")
	float RecommendedSpacingUU = 400.0f;
};

/**
 * Wordless support action command dispatched to companion AI.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FWordlessSupportCommand
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Silence")
	EWordlessSupportActionType ActionType = EWordlessSupportActionType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Silence")
	FName CompanionName = FName(TEXT("Garrett"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Silence")
	FVector TargetWorldLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Silence")
	bool bSuppressDialoguePrompt = true;
};

// -----------------------------------------------------------------------------------
// MULTICAST DELEGATES
// -----------------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSilenceClassified, const FSilenceEvaluationSnapshot&, Snapshot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWordlessSupportDispatched, const FWordlessSupportCommand&, Command);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBoundaryRefusalTriggered, FName, CompanionName, const FString&, Reason);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSilenceAcousticsChanged, ESomaticSilenceClassification, Classification, float, Intensity);
