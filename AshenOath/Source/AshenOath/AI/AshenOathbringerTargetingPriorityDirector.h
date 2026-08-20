// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenOathbringerTargetingPriorityDirector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCleaveTargetSelectedSignature, AActor*, TargetEnemy, float, CleavePriorityScore);

/**
 * UAshenOathbringerTargetingPriorityDirector
 *
 * AI Director computing high-value targets for Oathbringer's Cleave attacks (PRS-001 Oathbringer Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenOathbringerTargetingPriorityDirector : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|OathbringerAI")
	AActor* SelectHighPriorityCleaveTarget(TArray<AActor*> NearbyEnemies);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|OathbringerAI|Events")
	FOnCleaveTargetSelectedSignature OnCleaveTargetSelected;
};
