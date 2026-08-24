// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenAcousticEcholocationEvaluator.generated.h"

/**
 * UAshenAcousticEcholocationEvaluator
 * 
 * Computes acoustic sonar wave expansion speed, wireframe contour reveal opacity, and echo bounce delays.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAcousticEcholocationEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAcousticEcholocationEvaluator();

	/** Evaluates acoustic pulse propagation maximum radius in UU [350uu to 1800uu] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario8|Echolocation")
	float EvaluateSonarPropagationRadius(EEcholocationPulseType PulseType) const;

	/** Evaluates wireframe contour reveal opacity based on time since pulse [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario8|Echolocation")
	float EvaluateSonarContourOpacity(float TimeSincePulseSeconds, float PulseDurationSeconds) const;
};
