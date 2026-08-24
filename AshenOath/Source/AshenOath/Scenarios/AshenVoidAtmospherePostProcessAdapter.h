// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenVoidAtmospherePostProcessAdapter.generated.h"

/**
 * UAshenVoidAtmospherePostProcessAdapter
 * 
 * Computes celestial void horizon bloom, wind streak motion blur intensity, and bridge resonance emission.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenVoidAtmospherePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenVoidAtmospherePostProcessAdapter();

	/** Evaluates wind streak motion blur intensity [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario9|PostProcess")
	float EvaluateWindStreakIntensity(float WindSpeedMps) const;

	/** Evaluates telekinetic bridge resonance glow brightness [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario9|PostProcess")
	float EvaluateBridgeResonanceGlow(float BridgeStability01) const;
};
