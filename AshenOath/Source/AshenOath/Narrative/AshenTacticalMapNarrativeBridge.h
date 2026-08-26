// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenTacticalMapNarrativeBridge.generated.h"

/**
 * UAshenTacticalMapNarrativeBridge
 * 
 * Generates companion dialogue barks during overland map travel, beacon attunement, and travel hazard encounters.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalMapNarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTacticalMapNarrativeBridge();

	/** Formats dialogue bark for travel events */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Map")
	FText FormatTravelBark(EWaypointBeaconState BeaconState, ETravelHazardType HazardType) const;
};
