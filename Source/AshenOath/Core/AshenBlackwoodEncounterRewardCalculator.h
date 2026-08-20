// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenBlackwoodEncounterRewardCalculator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEncounterRewardCalculatedSignature, float, SanctuaryResourceBonus, float, WillpowerEXP);

/**
 * UAshenBlackwoodEncounterRewardCalculator
 *
 * Calculator computing sanctuary resources and exp rewards upon clearing the bridge encounter (Where Light Fades Act 01).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenBlackwoodEncounterRewardCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|BlackwoodReward")
	void CalculateEncounterRewards(float ClearTimeSeconds, float RemainingPartyHealthPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BlackwoodReward|Events")
	FOnEncounterRewardCalculatedSignature OnRewardCalculated;
};
