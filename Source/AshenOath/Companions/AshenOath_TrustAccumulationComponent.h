// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathTrustTypes.h"
#include "AshenOath_TrustAccumulationComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTrustAccumulatedSignature, FName, CompanionID, float, AccumulatorScore);

/**
 * UAshenOath_TrustAccumulationComponent
 *
 * Component accumulating relational trust deltas for Garrett and Serafina.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_TrustAccumulationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_TrustAccumulationComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Trust")
	void AccumulateTrustDelta(FName CompanionID, float Delta);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Trust")
	float GetTrust(const FAshenOathTrustPairKey& Key) const;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Trust")
	EAshenOathTrustBand GetTrustBand(const FAshenOathTrustPairKey& Key) const;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Trust")
	void InitializePairTrust(const FAshenOathTrustPairKey& Key, float InitialValue);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Trust")
	float UpdateTrust(const FAshenOathTrustPairKey& Key, float Penalty, float Weight, double Timestamp);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Trust|Events")
	FOnTrustAccumulatedSignature OnTrustAccumulated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Trust")
	float GarrettTrustAccumulator = 50.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Trust")
	float SerafinaTrustAccumulator = 50.0f;

private:
	TMap<FAshenOathTrustPairKey, FAshenOathTrustPairState> PairStates;
};
