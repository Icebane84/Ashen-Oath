// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenCampfireHearthTypes.generated.h"

// -----------------------------------------------------------------------------------
// CAMPFIRE HEARTH & INTEGRATION ENUMS (CAMPFIRE-SPEC-062)
// -----------------------------------------------------------------------------------

UENUM(BlueprintType)
enum class ECampfireRestTier : uint8
{
	MinorRest            UMETA(DisplayName = "Minor Rest (<0.30 Debt: Quick recovery & +5% Stamina Regen)"),
	ReflectiveTransmute  UMETA(DisplayName = "Reflective Transmutation (0.30-0.70 Debt: Permanent +10% Poise/Faith trait)"),
	SolemnVigil          UMETA(DisplayName = "Solemn Vigil (>0.70 Debt: Deep catharsis & dysregulation reset)")
};

UENUM(BlueprintType)
enum class ECompanionHearthSeating : uint8
{
	IntimateProximity    UMETA(DisplayName = "Intimate Proximity (250uu - High Trust & Low Dysregulation)"),
	StandardFireside     UMETA(DisplayName = "Standard Fireside (450uu - Balanced Trust)"),
	GuardedStandoff      UMETA(DisplayName = "Guarded Standoff (800uu - High Dysregulation / Standoff)")
};

// -----------------------------------------------------------------------------------
// CAMPFIRE HEARTH & INTEGRATION STRUCTS
// -----------------------------------------------------------------------------------

/**
 * Snapshot of a campfire rest session and integration progression.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FCampfireIntegrationSnapshot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Hearth")
	FString SessionId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Hearth")
	ECampfireRestTier RestTier = ECampfireRestTier::MinorRest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Hearth")
	float InitialIntegrationDebt = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Hearth")
	float InitialDysregulation = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Hearth")
	float TransmutedTraitBonus = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Hearth")
	bool bCatharsisDialogueTriggered = false;
};

/**
 * Permanent psychological trait unlocked through campfire trauma transmutation.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FTransmutedTraitReward
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Hearth")
	FString TraitId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Hearth")
	FName TraitName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Hearth")
	FGameplayTag TraitTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Hearth")
	float StatBonusScalar = 0.10f; // +10%

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Hearth")
	FString FlavorDescription;
};

// -----------------------------------------------------------------------------------
// MULTICAST DELEGATES
// -----------------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCampfireRestStarted, const FCampfireIntegrationSnapshot&, Snapshot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTraumaTransmuted, const FString&, TraitId, float, BonusValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionSeatingStaged, FName, CompanionName, ECompanionHearthSeating, Seating);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSolemnVigilCompleted, float, CleansedDysregulation);
