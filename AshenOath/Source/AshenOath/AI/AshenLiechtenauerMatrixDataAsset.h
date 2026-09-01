// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Combat/AshenMasterCutTypes.h"
#include "AshenLiechtenauerMatrixDataAsset.generated.h"

class UAshenGameplayAbility_CombatStrike;

USTRUCT(BlueprintType)
struct FLiechtenauerCounterRule
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liechtenauer|Rules")
	FGameplayTag TargetGuardTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liechtenauer|Rules")
	EAshenMasterCutType RecommendedCounterCut = EAshenMasterCutType::Zornhau;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liechtenauer|Rules")
	TSubclassOf<UAshenGameplayAbility_CombatStrike> CounterAbilityClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liechtenauer|Rules")
	float PostureDamageMultiplier = 1.75f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liechtenauer|Rules")
	float StaggerDurationSeconds = 1.2f;
};

/**
 * UAshenLiechtenauerMatrixDataAsset
 *
 * Data-driven primary data asset storing the 14th-century Liechtenauer Master Cut counter matrix,
 * posture damage multipliers, and ability bindings.
 * (PATCH v158.19.0 / PRS-001-SPEC-AI-109 / PRS-001-SPEC-COMBAT-106)
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenLiechtenauerMatrixDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UAshenLiechtenauerMatrixDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liechtenauer|Matrix")
	TArray<FLiechtenauerCounterRule> CounterRules;

	/** Queries the counter rule for a given target guard tag */
	UFUNCTION(BlueprintPure, Category = "Liechtenauer|Matrix")
	bool FindCounterRuleForGuard(const FGameplayTag& GuardTag, FLiechtenauerCounterRule& OutRule) const;
};
