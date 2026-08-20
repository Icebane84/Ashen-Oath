// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTrustAccumulationComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionTrustChangedSignature, FName, CompanionName, float, NewTrustScore);

/**
 * UAshenTrustAccumulationComponent
 *
 * Tracks dynamic companion trust scores (0.0 to 100.0) between Kaelen, Garrett, and Serafina.
 * Unlocks companion combo multipliers and joint synergy abilities as trust accumulates.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTrustAccumulationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTrustAccumulationComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Trust")
	void AddTrust(FName CompanionName, float TrustDelta);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Trust")
	float GetTrustScore(FName CompanionName) const;

	UFUNCTION(BlueprintPure, Category = "AshenOath|Trust")
	float GetSynergyDamageMultiplier(FName CompanionName) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Trust")
	float MaxTrustScore = 100.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Trust|Events")
	FOnCompanionTrustChangedSignature OnTrustChanged;

private:
	TMap<FName, float> CompanionTrustMap;
};
