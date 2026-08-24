// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenChaosSpatialAudioEvaluator.generated.h"

/**
 * UAshenChaosSpatialAudioEvaluator
 * 
 * Computes acoustic resonant frequency and sound occlusion based on debris cluster size and structural material.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenChaosSpatialAudioEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenChaosSpatialAudioEvaluator();

	/** Computes acoustic impact resonance frequency in Hz [120Hz to 4500Hz] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Chaos|Audio")
	float EvaluateImpactResonanceFrequency(EStructuralMaterialType Material, float ImpactJoules) const;

	/** Computes acoustic occlusion filter percentage [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Chaos|Audio")
	float EvaluateRubbleSoundOcclusion(float DebrisMassKg) const;
};
