// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenTransferenceBurnoutTypes.generated.h"

// -----------------------------------------------------------------------------------
// TRANSFERENCE & BURNOUT ENUMERATIONS (BURDEN-SPEC-057)
// -----------------------------------------------------------------------------------

UENUM(BlueprintType)
enum class EFoeStaggerResolutionChoice : uint8
{
	Unknown,
	MercifulBinding       UMETA(DisplayName = "Merciful Binding (Purification & Sparing)"),
	RuthlessExecution     UMETA(DisplayName = "Ruthless Execution (Pragmatic Elimination)"),
	DesperateIgnored      UMETA(DisplayName = "Desperate Ignored (Combat Disengagement)")
};

UENUM(BlueprintType)
enum class EBurnoutSeverityTier : uint8
{
	Nominal               UMETA(DisplayName = "Nominal (Fresh & Unburdened)"),
	Strained              UMETA(DisplayName = "Strained (Minor Somatic Tremor)"),
	Exhausted             UMETA(DisplayName = "Exhausted (Severe Recovery Delay)"),
	CriticalCollapse      UMETA(DisplayName = "Critical Collapse (Imminent Breakdown)")
};

UENUM(BlueprintType)
enum class EShadowMarkOveruseResponse : uint8
{
	PermittedRestraint    UMETA(DisplayName = "Permitted Restraint (Disciplined Usage)"),
	VerbalCaution         UMETA(DisplayName = "Verbal Caution (Warning Against Corruption)"),
	PhysicalIntervention  UMETA(DisplayName = "Physical Intervention (Body-Block & Grounding)")
};

// -----------------------------------------------------------------------------------
// TRANSFERENCE & MORAL EVALUATION STRUCTS
// -----------------------------------------------------------------------------------

/**
 * Snapshot of transference burden when Serafina heals Kaelen.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FTransferenceBurdenSnapshot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Transference")
	FString TransferenceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Transference")
	float TraumaAbsorbed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Transference")
	float SerafinaCumulativeBurnout = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Transference")
	EBurnoutSeverityTier BurnoutTier = EBurnoutSeverityTier::Nominal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Transference")
	float RecoveryDelayPenaltySeconds = 0.0f;
};

/**
 * Result of companion moral evaluation on sparing vs executing staggered foes.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FMercyExecutionEvaluationResult
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Transference")
	EFoeStaggerResolutionChoice ChoiceMade = EFoeStaggerResolutionChoice::Unknown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Transference")
	float GarrettPragmaticApprovalDelta = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Transference")
	float SerafinaMoralPurityDelta = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Transference")
	FGameplayTag EvaluationTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Transference")
	FString ContextualDialogue;
};

// -----------------------------------------------------------------------------------
// MULTICAST DELEGATES
// -----------------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTransferenceAbsorbed, const FTransferenceBurdenSnapshot&, Snapshot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStaggerResolutionEvaluated, const FMercyExecutionEvaluationResult&, EvaluationResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBurnoutTierChanged, FName, CompanionName, EBurnoutSeverityTier, NewTier);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShadowOveruseInterventionTriggered, FName, CompanionName, EShadowMarkOveruseResponse, Response);
