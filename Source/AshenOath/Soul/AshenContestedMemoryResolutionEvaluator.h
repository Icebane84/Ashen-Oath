// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenContestedMemoryResolutionEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryResolutionEvaluatedSignature, FName, MemoryNodeTag, bool, bIsStabilizedTruth);

/**
 * UAshenContestedMemoryResolutionEvaluator
 *
 * Subsystem determining whether a memory becomes Stabilized Truth vs Fragmented Doubt (UMB-INT-001 Memory Slice).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenContestedMemoryResolutionEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenContestedMemoryResolutionEvaluator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MemoryResolution")
	bool EvaluateMemoryResolution(FName MemoryTag, float GraceLensWeight, float AccountabilityLensWeight);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MemoryResolution|Events")
	FOnMemoryResolutionEvaluatedSignature OnResolutionEvaluated;
};
