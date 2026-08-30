// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenSoulTypes.h"
#include "AshenCompanionTrustDivergenceSubsystem.generated.h"

class UAshenSoulPublisher;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionDivergenceRiskChangedSignature, FName, CompanionID, float, DivergenceRiskPercentage);

/**
 * UAshenCompanionTrustDivergenceSubsystem
 *
 * World Subsystem evaluating companion divergence/betrayal risk directly
 * derived from UAshenSoulPublisher's FRelationalMatrix_V2 (TAM-001).
 * Eliminates private state maps and provides zero-entropy relational evaluation.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionTrustDivergenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Derives companion divergence risk directly from FRelationalMatrix_V2 */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CompanionTrust")
	float EvaluateCompanionDivergenceRisk(FName CompanionID);

	/** Records trust shift, committing normalized delta to UAshenSoulPublisher */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CompanionTrust")
	void RecordTrustShift(FName CompanionID, float NormalizedTrustDelta);

	UFUNCTION(BlueprintPure, Category = "AshenOath|CompanionTrust")
	float GetDivergenceRisk(FName CompanionID) const;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CompanionTrust|Events")
	FOnCompanionDivergenceRiskChangedSignature OnDivergenceRiskChanged;

private:
	UAshenSoulPublisher* GetSoulPublisher() const;
};
