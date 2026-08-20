// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenGarrettCrowdControlPriorityDirector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCCPriorityEvaluatedSignature, AActor*, TargetEnemyToCC, float, PriorityScore);

/**
 * UAshenGarrettCrowdControlPriorityDirector
 *
 * Director instructing Garrett's AI to prioritize crowd controlling enemies threatening Serafina or Kaelen (PRS-001 Garrett Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenGarrettCrowdControlPriorityDirector : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|GarrettAIDirector")
	AActor* SelectHighPriorityCCTarget(TArray<AActor*> NearbyEnemies, AActor* ThreatTargetActor);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GarrettAIDirector|Events")
	FOnCCPriorityEvaluatedSignature OnCCPriorityEvaluated;
};
