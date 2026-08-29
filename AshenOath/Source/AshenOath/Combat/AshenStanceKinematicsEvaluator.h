// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenStanceKinematicsEvaluator.generated.h"

/**
 * UAshenStanceKinematicsEvaluator
 * 
 * Computes stance-specific kinetic multipliers, poise damage bonuses, parry windows, and armor penetration percentages.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStanceKinematicsEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenStanceKinematicsEvaluator();

	/** Evaluates raw damage multiplier [1.0x to 1.40x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Evaluator")
	float EvaluateDamageMultiplier(EOathbringerMartialStance Stance) const;

	/** Evaluates poise damage multiplier [0.90x to 1.75x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Evaluator")
	float EvaluatePoiseDamageMultiplier(EOathbringerMartialStance Stance) const;

	/** Evaluates parry frame duration [0.08s to 0.22s] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Evaluator")
	float EvaluateParryWindowSeconds(EOathbringerMartialStance Stance) const;

	/** Evaluates physical armor penetration [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Evaluator")
	float EvaluateArmorPenetration(EOathbringerMartialStance Stance) const;
};
