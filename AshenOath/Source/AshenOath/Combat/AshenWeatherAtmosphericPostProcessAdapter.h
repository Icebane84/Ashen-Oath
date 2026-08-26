// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenWeatherAtmosphericPostProcessAdapter.generated.h"

/**
 * UAshenWeatherAtmosphericPostProcessAdapter
 * 
 * Drives peripheral screen frost dither, volcanic soot particle fogging, and lightning strike lens flare overexposure.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherAtmosphericPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeatherAtmosphericPostProcessAdapter();

	/** Evaluates post-process parameters for active weather hazard */
	UFUNCTION(BlueprintPure, Category = "Ashen|Weather|PostProcess")
	void EvaluateWeatherPostProcess(
		EWeatherHazardState State,
		float& OutFrostVignetteDensity,
		float& OutAshFogDensity,
		float& OutLightningFlashBloom);
};
