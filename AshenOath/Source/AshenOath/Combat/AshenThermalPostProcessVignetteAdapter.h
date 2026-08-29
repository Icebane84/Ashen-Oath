// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenThermalPostProcessVignetteAdapter.generated.h"

/**
 * UAshenThermalPostProcessVignetteAdapter
 * 
 * Drives post-process thermal shader effects: Frosty ice-crystal screen border vignettes during hypothermia and warm golden chromatic glow inside sanctuaries.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenThermalPostProcessVignetteAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenThermalPostProcessVignetteAdapter();

	/** Evaluates post-process parameters */
	UFUNCTION(BlueprintPure, Category = "Ashen|Survival|PostProcess")
	void EvaluateThermalPostProcess(
		EThermalShelterTier Tier,
		float BodyTempC,
		float& OutFrostVignetteIntensity,
		float& OutWarmHearthGlowIntensity) const;
};
