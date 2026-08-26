// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenSanctuaryFastTravelDirectorComponent.generated.h"

/**
 * UAshenSanctuaryFastTravelDirectorComponent
 * 
 * Directs fast travel channel durations, travel stamina costs, and teleportation fade sequences.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuaryFastTravelDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanctuaryFastTravelDirectorComponent();

	/** Gets the required channel time to initiate fast travel */
	UFUNCTION(BlueprintPure, Category = "Ashen|Map|Travel")
	float GetFastTravelChannelDurationSeconds() const { return 3.0f; }

	/** Calculates stamina cost for fast travel */
	UFUNCTION(BlueprintPure, Category = "Ashen|Map|Travel")
	float EvaluateFastTravelStaminaCost(float DistanceKm) const;
};
