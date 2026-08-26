// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenCookingPotSimmerPostProcessAdapter.generated.h"

/**
 * UAshenCookingPotSimmerPostProcessAdapter
 * 
 * Drives simmering steam heat haze, warm cauldron amber glow, and soft vignette around the cooking pot.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCookingPotSimmerPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCookingPotSimmerPostProcessAdapter();

	/** Evaluates post-process parameters for simmering cauldron */
	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking|PostProcess")
	void EvaluateSimmerPostProcess(
		ECookingPotState PotState,
		float TemperatureCelsius,
		float& OutHeatHazeIntensity,
		float& OutCauldronAmberBloom,
		float& OutSteamVignette);
};
