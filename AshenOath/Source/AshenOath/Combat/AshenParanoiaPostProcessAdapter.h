// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenParanoiaPostProcessAdapter.generated.h"

/**
 * UAshenParanoiaPostProcessAdapter
 * 
 * Drives dark oily vignette, RGB chromatic aberration jitter, and peripheral camera phantom fades.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParanoiaPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenParanoiaPostProcessAdapter();

	/** Evaluates post-process parameters for Creeping Paranoia */
	UFUNCTION(BlueprintPure, Category = "Ashen|Paranoia|PostProcess")
	void EvaluatePostProcessParams(
		float Infection01,
		float& OutVignetteIntensity,
		float& OutChromaticJitter,
		float& OutDesaturation);
};
