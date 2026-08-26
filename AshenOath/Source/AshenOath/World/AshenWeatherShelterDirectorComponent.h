// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenWeatherShelterDirectorComponent.generated.h"

/**
 * UAshenWeatherShelterDirectorComponent
 * 
 * Tracks player shelter status (Exposed, Cavern, Hearth Sanctuary) and applies environmental damage mitigation percentages.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherShelterDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeatherShelterDirectorComponent();

	/** Evaluates hazard damage mitigation percentage [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Weather|Shelter")
	float EvaluateHazardMitigation(EWeatherShelterType ShelterType) const;

	/** Gets weather transition crossfade duration */
	UFUNCTION(BlueprintPure, Category = "Ashen|Weather|Shelter")
	float GetWeatherTransitionDurationSeconds() const { return 10.0f; }
};
