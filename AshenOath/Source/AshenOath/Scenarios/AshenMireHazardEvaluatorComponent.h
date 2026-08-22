// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenMireHazardEvaluatorComponent.generated.h"

/**
 * UAshenMireHazardEvaluatorComponent
 * 
 * Computes terrain movement drag in deep mire mud and flammable gas pocket blast radii.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMireHazardEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMireHazardEvaluatorComponent();

	/** Evaluates player movement speed in mud */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario5")
	float EvaluateMudSpeedMultiplier(bool bInDeepMud, bool bIsUnchained) const;

	/** Evaluates gas pocket blast damage falloff */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario5")
	float EvaluateGasBlastDamage(float BaseDamage, float DistanceCentimeters, float MaxRadiusCentimeters) const;
};
