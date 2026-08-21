// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenSanityChromaticEvaluatorComponent.generated.h"

/**
 * UAshenSanityChromaticEvaluatorComponent
 * 
 * Maps player Sanity (0.0 to 1.0) to post-process chromatic aberration intensity.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanityChromaticEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanityChromaticEvaluatorComponent();

	/** Computes Chromatic Aberration intensity (0.0 to 5.0) from Sanity */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario4")
	float EvaluateChromaticAberration(float Sanity) const;
};
