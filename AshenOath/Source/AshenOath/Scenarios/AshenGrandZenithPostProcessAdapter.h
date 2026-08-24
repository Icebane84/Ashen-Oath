// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenGrandZenithPostProcessAdapter.generated.h"

/**
 * UAshenGrandZenithPostProcessAdapter
 * 
 * Computes iridescent celestial bloom, chromatic convergence rays, and apex altar gold aura emission.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGrandZenithPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGrandZenithPostProcessAdapter();

	/** Evaluates iridescent bloom intensity [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario10|PostProcess")
	float EvaluateApotheosisBloomIntensity(float Resonance01) const;

	/** Evaluates chromatic convergence ray sharpness [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario10|PostProcess")
	float EvaluateChromaticRayIntensity(EApotheosisResonanceStage Stage) const;
};
