// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenEntropyOfMeaningSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNarrativeEntropyUpdatedSignature, float, ActiveEntropyLevel, float, MeaningErosionVelocity);

/**
 * UAshenEntropyOfMeaningSubsystem
 *
 * World Subsystem tracking overall Nyx Narrative Entropy in the active level.
 */
UCLASS()
class ASHENOATH_API UAshenEntropyOfMeaningSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|EntropyOfMeaning")
	void AccrueNarrativeEntropy(float DeltaEntropy);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|EntropyOfMeaning|Events")
	FOnNarrativeEntropyUpdatedSignature OnEntropyUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|EntropyOfMeaning")
	float ActiveNarrativeEntropy = 0.0f;
};
