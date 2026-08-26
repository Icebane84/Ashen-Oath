// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenWeatherNarrativeBridge.generated.h"

/**
 * UAshenWeatherNarrativeBridge
 * 
 * Generates contextual companion commentary and survival advice during severe environmental weather hazards.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherNarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeatherNarrativeBridge();

	/** Formats dialogue bark for active weather state */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Weather")
	FText FormatWeatherBark(EWeatherHazardState State, EWeatherShelterType Shelter) const;
};
