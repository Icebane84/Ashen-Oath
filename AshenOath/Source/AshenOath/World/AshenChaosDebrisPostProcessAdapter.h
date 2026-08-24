// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenChaosDebrisPostProcessAdapter.generated.h"

/**
 * UAshenChaosDebrisPostProcessAdapter
 * 
 * Computes camera shake scale (0.0 to 2.0) and environmental dust density during heavy structural collapses.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenChaosDebrisPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenChaosDebrisPostProcessAdapter();

	/** Evaluates camera shake scale based on impact energy [0.0 to 2.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Chaos|PostProcess")
	float EvaluateCollapseCameraShake(float ImpactJoules) const;

	/** Evaluates dust particle spawn density [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Chaos|PostProcess")
	float EvaluateDustParticleDensity(float DebrisMassKg) const;
};
