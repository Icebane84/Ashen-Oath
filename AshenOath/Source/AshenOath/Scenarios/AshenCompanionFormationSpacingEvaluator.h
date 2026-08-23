// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenCompanionFormationSpacingEvaluator.generated.h"

/**
 * UAshenCompanionFormationSpacingEvaluator
 * 
 * Computes dynamic combat formation perimeter distances (300uu to 1200uu) based on active run mode and trust.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionFormationSpacingEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionFormationSpacingEvaluator();

	/** Evaluates Serafina's combat formation distance from Kaelen */
	UFUNCTION(BlueprintPure, Category = "Ashen|Waystation")
	float EvaluateSerafinaFormationDistance(EWaystationRunMode Mode) const;

	/** Evaluates Garrett's combat flank distance */
	UFUNCTION(BlueprintPure, Category = "Ashen|Waystation")
	float EvaluateGarrettFormationDistance(EWaystationRunMode Mode) const;
};
