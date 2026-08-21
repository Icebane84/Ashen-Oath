// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "AshenProximitySeatingStagingComponent.generated.h"

/**
 * UAshenProximitySeatingStagingComponent
 * 
 * Computes companion seating spacing (250uu to 800uu) based on trust and dysregulation.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenProximitySeatingStagingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenProximitySeatingStagingComponent();

	/** Calculates companion seating arrangement */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Hearth")
	ECompanionHearthSeating CalculateSeating(float Trust, float Dysregulation) const;

	/** Calculates radial distance in Unreal Units */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Hearth")
	float GetSeatingDistanceUU(ECompanionHearthSeating Seating) const;
};
