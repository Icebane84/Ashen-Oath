// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenPlausibleDestructivenessEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlausibleDestructivenessEvaluatedSignature, FName, MemoryID, FString, SelectedDestructiveWhisperText, float, PlausibilityScore);

/**
 * UAshenPlausibleDestructivenessEvaluator
 *
 * Evaluator ensuring Nyx presents the most destructive interpretation that remains plausible based on Kaelen's unresolved memories.
 */
UCLASS()
class ASHENOATH_API UAshenPlausibleDestructivenessEvaluator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PlausibleDestructiveness")
	FString SelectMostDestructivePlausibleWhisper(FName MemoryID, float UnresolvedTraumaWeight);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PlausibleDestructiveness|Events")
	FOnPlausibleDestructivenessEvaluatedSignature OnDestructivenessEvaluated;
};
