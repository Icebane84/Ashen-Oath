// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenDestructionWeatherAINarrativeBridge.generated.h"

/**
 * UAshenDestructionWeatherAINarrativeBridge
 * 
 * Formats companion tactical voice barks for conductive lightning hazards, blizzard whiteout flanking, and collapsing stone cover.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDestructionWeatherAINarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDestructionWeatherAINarrativeBridge();

	/** Formats dialogue bark for tactical weather/destruction events */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Convergence")
	FText FormatTacticalBark(bool bConductiveHazard, bool bBlizzardAmbush, bool bCoverCollapse) const;
};
