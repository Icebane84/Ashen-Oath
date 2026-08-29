// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenOathbringerRunicSeamDirectorComponent.generated.h"

/**
 * UAshenOathbringerRunicSeamDirectorComponent
 * 
 * Directs the visual runic emissive shader parameters along Oathbringer's fuller seam depending on active stance.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerRunicSeamDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerRunicSeamDirectorComponent();

	/** Gets active seam color vector */
	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Visuals")
	FLinearColor GetSeamColorForStance(EOathbringerMartialStance Stance) const;

	/** Gets target emissive multiplier [3.2 to 4.5] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Visuals")
	float GetEmissiveIntensityForStance(EOathbringerMartialStance Stance) const;
};
