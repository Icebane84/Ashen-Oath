// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenMoltenTemperingEvaluator.generated.h"

/**
 * UAshenMoltenTemperingEvaluator
 * 
 * Computes weapon fire damage bonus and stability duration based on molten blade temperature.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMoltenTemperingEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMoltenTemperingEvaluator();

	/** Evaluates fire damage bonus percentage based on blade temperature [0.0 to 0.40] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario7|Tempering")
	float EvaluateFireDamageBonus(float BladeTempC) const;

	/** Classifies blade state based on blade temperature */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario7|Tempering")
	ETemperedBladeState ClassifyBladeState(float BladeTempC) const;
};
