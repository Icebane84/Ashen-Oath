// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenWhisperingWindsOracleSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOracleHintEvaluatedSignature, FName, OracleHintID, float, TruthClarityPercent);

/**
 * UAshenWhisperingWindsOracleSubsystem
 *
 * Subsystem evaluating psychological oracle hints in wind audio.
 */
UCLASS()
class ASHENOATH_API UAshenWhisperingWindsOracleSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Oracle")
	void EvaluateOracleHint(FName OracleHintID, float SanityPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Oracle|Events")
	FOnOracleHintEvaluatedSignature OnOracleHintEvaluated;
};
