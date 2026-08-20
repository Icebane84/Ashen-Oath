// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenMemoryPalaceTraversalPriorityDirector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConstellationTraversalEvaluatedSignature, FVector, NextTraversalNodeLocation, float, TraversalSpeedMultiplier);

/**
 * UAshenMemoryPalaceTraversalPriorityDirector
 *
 * AI Director navigating companions along active memory constellation paths (UMB-INT-001 Memory Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenMemoryPalaceTraversalPriorityDirector : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|MemoryTraversal")
	FVector SelectNextConstellationNode(TArray<FVector> ConstellationNodes, FVector CurrentLocation);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MemoryTraversal|Events")
	FOnConstellationTraversalEvaluatedSignature OnTraversalEvaluated;
};
