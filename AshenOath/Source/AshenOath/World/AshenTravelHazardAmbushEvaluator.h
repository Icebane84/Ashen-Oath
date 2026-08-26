// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenTravelHazardAmbushEvaluator.generated.h"

/**
 * UAshenTravelHazardAmbushEvaluator
 * 
 * Computes overland travel risk, roadside ambush encounters, and surprise penalty modifiers.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTravelHazardAmbushEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTravelHazardAmbushEvaluator();

	/** Evaluates ambush chance percent [0.0 to 75.0%] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Map|Hazards")
	float EvaluateAmbushProbability(float DistanceKm, float RegionCorruption01, bool bUsedEmberSaltProvisions) const;

	/** Evaluates surprise posture penalty multiplier [0.85x to 1.00x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Map|Hazards")
	float EvaluateSurprisePosturePenalty(bool bAmbushTriggered) const;
};
