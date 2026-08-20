// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenCompanionTrustDivergenceSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionDivergenceRiskChangedSignature, FName, CompanionID, float, DivergenceRiskPercentage);

/**
 * UAshenCompanionTrustDivergenceSubsystem
 *
 * World Subsystem tracking companion divergence/betrayal risk when Oathbond falls below critical thresholds.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionTrustDivergenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CompanionTrust")
	void EvaluateCompanionDivergenceRisk(FName CompanionID, float CurrentOathbondTrust);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CompanionTrust")
	void RecordTrustShift(FName CompanionID, float TrustDelta);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CompanionTrust|Events")
	FOnCompanionDivergenceRiskChangedSignature OnDivergenceRiskChanged;

private:
	TMap<FName, float> DivergenceRisks;
};
