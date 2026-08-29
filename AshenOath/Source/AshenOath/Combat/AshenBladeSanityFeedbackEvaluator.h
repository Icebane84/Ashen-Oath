// Copyright Ashen Oath Tactical RPG. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "Combat/AshenBladeSanityBalanceDataAsset.h"
#include "AshenBladeSanityFeedbackEvaluator.generated.h"

/**
 * UAshenBladeSanityFeedbackEvaluator
 * 
 * Computes blade strike damage amplification (+45%), parry window reduction (-35%),
 * and dodge stamina multipliers (1.0x to 1.5x) based on sanity and hunger, with DataAsset support.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBladeSanityFeedbackEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBladeSanityFeedbackEvaluator();

	/** Evaluates blade strike damage multiplier [1.00x to 1.45x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Feedback")
	float EvaluateBladeDamageMultiplier(float BladeHunger01) const;

	/** Evaluates parry window reduction percentage [0.0 to 0.35] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Feedback")
	float EvaluateParryWindowPenalty(float CurrentSanity) const;

	/** Evaluates dodge stamina cost multiplier [1.00x to 1.50x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Feedback")
	float EvaluateDodgeStaminaMultiplier(float CurrentSanity) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence|Balancing")
	UAshenBladeSanityBalanceDataAsset* BalanceDataAsset;
};
