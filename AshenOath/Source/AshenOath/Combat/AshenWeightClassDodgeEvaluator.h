// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenWeightClassDodgeEvaluator.generated.h"

/**
 * UAshenWeightClassDodgeEvaluator
 * 
 * Computes roll duration, i-frame duration, stamina cost, and launch impulse force based on current equipment weight class.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeightClassDodgeEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeightClassDodgeEvaluator();

	/** Returns complete dodge scaling parameters for the given weight class */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Dodge")
	FDodgeScalingParameters GetDodgeParametersForWeightClass(EAshenWeightClass WeightClass) const;

	/** Evaluates current weight class given weight and max load */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Dodge")
	EAshenWeightClass EvaluateWeightClass(float WeightKg, float MaxLoadKg) const;
};
