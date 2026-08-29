// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenWeatherPerceptionClampEvaluator.generated.h"

/**
 * UAshenWeatherPerceptionClampEvaluator
 * 
 * Evaluates dynamic lock-on range, AI sight distance, and stealth ambush damage multipliers based on atmospheric visibility.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherPerceptionClampEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeatherPerceptionClampEvaluator();

	/** Evaluates lock-on range clamp [500uu to 1500uu] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Evaluator")
	float EvaluateLockOnRangeClamp(EAtmosphericVisibilityTier Tier) const;

	/** Evaluates AI sight radius [600uu to 2000uu] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Evaluator")
	float EvaluateAISightRadius(EAtmosphericVisibilityTier Tier) const;

	/** Evaluates AI vision cone angle [45 deg to 90 deg] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Evaluator")
	float EvaluateAIVisionConeDegrees(EAtmosphericVisibilityTier Tier) const;

	/** Evaluates stealth ambush critical damage multiplier [1.0x to 1.50x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Evaluator")
	float EvaluateStealthAmbushMultiplier(EAtmosphericVisibilityTier Tier) const;
};
