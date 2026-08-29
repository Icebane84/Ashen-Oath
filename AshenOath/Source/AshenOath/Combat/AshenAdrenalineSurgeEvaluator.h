// Copyright Ashen Oath Tactical RPG. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenSeveranceTypes.h"
#include "Combat/AshenSeveranceBalanceDataAsset.h"
#include "AshenAdrenalineSurgeEvaluator.generated.h"

/**
 * UAshenAdrenalineSurgeEvaluator
 * 
 * Computes somatic adrenaline gains, stamina recovery scaling, and hyper-armor duration
 * based on dismemberment severity with DataAsset support.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAdrenalineSurgeEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAdrenalineSurgeEvaluator();

	/** Evaluates adrenaline points granted for severity tier */
	UFUNCTION(BlueprintPure, Category = "Ashen|Severance|Evaluator")
	float EvaluateAdrenalineGain(ESeveranceSeverityTier Severity) const;

	/** Evaluates stamina refill amount */
	UFUNCTION(BlueprintPure, Category = "Ashen|Severance|Evaluator")
	float EvaluateStaminaRefill(float CurrentAdrenaline) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Severance|Balancing")
	UAshenSeveranceBalanceDataAsset* BalanceDataAsset;
};
