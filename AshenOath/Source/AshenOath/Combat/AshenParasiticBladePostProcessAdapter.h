// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenParasiticBladePostProcessAdapter.generated.h"

/**
 * UAshenParasiticBladePostProcessAdapter
 * 
 * Computes peripheral shadow vein vignette, garnet eye lens flare, and frost-chill blue tint during Gloomwood freeze.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParasiticBladePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenParasiticBladePostProcessAdapter();

	/** Evaluates dark oily vignette intensity [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Blade|PostProcess")
	float EvaluateVeinVignetteIntensity(float Corruption01) const;

	/** Evaluates blood-chill frost blue color filter [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Blade|PostProcess")
	float EvaluateFrostChillFilterIntensity(bool bIsFrozen) const;
};
