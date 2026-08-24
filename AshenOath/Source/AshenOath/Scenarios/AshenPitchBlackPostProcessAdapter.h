// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenPitchBlackPostProcessAdapter.generated.h"

/**
 * UAshenPitchBlackPostProcessAdapter
 * 
 * Computes darkness screen vignette opacity, edge sonar wireframe shader glow, and lantern light attenuation.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPitchBlackPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPitchBlackPostProcessAdapter();

	/** Evaluates darkness vignette opacity [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario8|PostProcess")
	float EvaluateDarknessVignetteOpacity(float LightRadiusUU) const;

	/** Evaluates sonar contour outline brightness [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario8|PostProcess")
	float EvaluateSonarContourGlow(float SonarRadiusUU) const;
};
