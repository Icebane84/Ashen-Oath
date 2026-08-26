// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenFallingMasonryHazardEvaluator.generated.h"

/**
 * UAshenFallingMasonryHazardEvaluator
 * 
 * Computes warning telegraph radius (150-450uu), crushing damage (250-1200 Dmg), and structural strain dynamics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFallingMasonryHazardEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFallingMasonryHazardEvaluator();

	/** Calculates crushing impact damage from falling masonry mass [250 to 1200 Dmg] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble|Hazard")
	float EvaluateCrushingDamage(float MasonryMassKg, float FallHeightMeters) const;

	/** Calculates hazard telegraph circle radius [150 to 450uu] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble|Hazard")
	float EvaluateTelegraphRadius(float MasonryMassKg) const;

	/** Calculates dust particle pre-warning duration in seconds */
	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble|Hazard")
	float GetTelegraphWarningDurationSeconds() const { return 1.2f; }
};
