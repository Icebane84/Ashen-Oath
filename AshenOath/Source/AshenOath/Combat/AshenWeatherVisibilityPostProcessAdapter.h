// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenWeatherVisibilityPostProcessAdapter.generated.h"

/**
 * UAshenWeatherVisibilityPostProcessAdapter
 * 
 * Adapts screen-space post-processing during storms: drives volumetric fog density, blizzard whiteout depth clamping, and electro-static lightning glare flashes.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherVisibilityPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeatherVisibilityPostProcessAdapter();

	/** Evaluates post-process parameters for current weather visibility */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|PostProcess")
	void EvaluateWeatherPostProcess(
		EAtmosphericVisibilityTier VisibilityTier,
		float& OutVolumetricFogDensity,
		float& OutDepthWhiteoutFactor,
		float& OutVignetteDarkening) const;
};
