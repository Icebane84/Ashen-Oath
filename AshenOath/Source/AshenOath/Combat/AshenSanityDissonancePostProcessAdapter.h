// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenSanityDissonancePostProcessAdapter.generated.h"

/**
 * UAshenSanityDissonancePostProcessAdapter
 * 
 * Drives chromatic aberration distortion (0.0 to 0.85), peripheral shadow vignetting, and eldritch eye dithering during mental collapse.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanityDissonancePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanityDissonancePostProcessAdapter();

	/** Evaluates post-process parameters for current mental state */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|PostProcess")
	void EvaluateSanityPostProcess(
		float CurrentSanity,
		bool bFlowStateActive,
		float& OutChromaticAberration,
		float& OutVignetteIntensity,
		float& OutEldritchDistortion);
};
