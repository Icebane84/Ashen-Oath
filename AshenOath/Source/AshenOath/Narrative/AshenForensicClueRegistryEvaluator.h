// Copyright Ashen Oath Tactical RPG. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "Narrative/AshenForensicMindscapeBalanceDataAsset.h"
#include "AshenForensicClueRegistryEvaluator.generated.h"

/**
 * UAshenForensicClueRegistryEvaluator
 * 
 * Computes evidence credibility weights based on clue category (Physical autopsy 1.0, Runic stelae 0.85, Companion dogma 0.65)
 * with DataAsset support.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenForensicClueRegistryEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenForensicClueRegistryEvaluator();

	/** Gets baseline credibility weight for clue category */
	UFUNCTION(BlueprintPure, Category = "Ashen|Forensic|Evaluator")
	float GetCategoryReliabilityWeight(EForensicClueCategory Category) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic|Balancing")
	UAshenForensicMindscapeBalanceDataAsset* BalanceDataAsset;
};
