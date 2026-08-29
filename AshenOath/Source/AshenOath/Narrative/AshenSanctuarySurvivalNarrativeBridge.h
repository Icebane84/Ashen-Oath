// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenSanctuarySurvivalNarrativeBridge.generated.h"

/**
 * UAshenSanctuarySurvivalNarrativeBridge
 * 
 * Formats companion dialogue barks when finding shelter in natural caverns or igniting ancient sanctuary beacons.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuarySurvivalNarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanctuarySurvivalNarrativeBridge();

	/** Formats dialogue bark for sanctuary and survival events */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Survival")
	FText FormatSurvivalBark(EThermalShelterTier Tier, ECookedMealBuffType Meal) const;
};
