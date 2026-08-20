// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenRelationalEcologyTypes.generated.h"

// -----------------------------------------------------------------------------------
// RELATIONAL ECOLOGY ENUMERATIONS (ECOL-SPEC-053)
// -----------------------------------------------------------------------------------

UENUM(BlueprintType)
enum class ECompanionInterventionType : uint8
{
	CostlyPresenceInterception UMETA(DisplayName = "Costly Presence (Takes crushing blow for Kaelen)"),
	WordlessFlankSync          UMETA(DisplayName = "Wordless Flank Sync (High-risk synchronized strike)"),
	EmpathicTransference       UMETA(DisplayName = "Empathic Transference (Absorbs Kaelen's soot/fever)"),
	SanctuaryCircleCast        UMETA(DisplayName = "Sanctuary Circle Cast (Consecrates ground at Kaelen's feet)"),
	TacticalWithdrawal         UMETA(DisplayName = "Tactical Withdrawal (Preserves personal safety / expands spacing)")
};

UENUM(BlueprintType)
enum class ERelationalRuptureState : uint8
{
	Harmonious,
	FrictionGuarded,
	ActiveRupture,
	DeepEstrangement,
	RememberedReconciliation
};

UENUM(BlueprintType)
enum class EAuthorIdentity : uint8
{
	Kaelen   UMETA(DisplayName = "Kaelen (Trauma prose & ink scars)"),
	Garrett  UMETA(DisplayName = "Garrett (Tactical charcoal diagrams & cynical notes)"),
	Serafina UMETA(DisplayName = "Serafina (Silverleaf botanical pressings & empathy reflections)")
};

// -----------------------------------------------------------------------------------
// RELATIONAL ECOLOGY STRUCTS
// -----------------------------------------------------------------------------------

/**
 * Historical Pattern Continuity and Repair Matrix.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenRepairMatrix
{
	GENERATED_BODY()

	/** Historical ratio of collective sync finishers vs solitary martyr acts */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Ecology")
	float SynarchyRatio = 0.5f;

	/** Consecutive combat intervals where Kaelen protected companions without dark shortcuts */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Ecology")
	int32 ConsecutiveCohesionBeats = 0;

	/** Computed velocity of relationship repair */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Ecology")
	float ActiveRepairVelocity = 0.0f;

	/** Overall rupture classification */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Ecology")
	ERelationalRuptureState CurrentRuptureState = ERelationalRuptureState::Harmonious;
};

/**
 * Costly Presence Intent Payload.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenCostlyPresenceIntent
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Ecology")
	FGuid IntentId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Ecology")
	FName CompanionName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Ecology")
	ECompanionInterventionType InterventionType = ECompanionInterventionType::CostlyPresenceInterception;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Ecology")
	float ComputedFaithThreshold = 0.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Ecology")
	float CompanionTrustSnapshot = 0.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Ecology")
	bool bInterventionApproved = false;
};

/**
 * Multi-Author Living Journal Marginalia Entry.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenMultiAuthorMarginEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FGuid EntryId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	EAuthorIdentity Author = EAuthorIdentity::Kaelen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FText EntryText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FName AttachedMemorySiteId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	float StainOpacity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	double TimestampSeconds = 0.0;
};

// -----------------------------------------------------------------------------------
// MASTER ECOLOGY MULTICAST DELEGATES
// -----------------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCostlyPresenceTriggered, const FAshenCostlyPresenceIntent&, Intent, const FVector&, TargetLocation);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRelationalRuptureChanged, FName, CompanionName, ERelationalRuptureState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWordlessReconciliationExecuted, FName, CompanionName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEmpathicTransferenceAbsorbed, float, TransferredDysregulation, float, ResidualSootScalar);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMultiAuthorEntryAdded, const FAshenMultiAuthorMarginEntry&, NewEntry);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDynamicFormationOffsetUpdated, FName, CompanionName, float, TargetSpacingUU, float, LerpSpeed);
