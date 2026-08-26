// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenMasonryCollapsePostProcessAdapter.generated.h"

/**
 * UAshenMasonryCollapsePostProcessAdapter
 * 
 * Drives impact camera shake, localized dust particle fog density, and radial blur pulses during masonry collapses.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMasonryCollapsePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMasonryCollapsePostProcessAdapter();

	/** Evaluates post-process parameters for masonry collapse */
	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble|PostProcess")
	void EvaluateCollapsePostProcess(
		EMasonryCollapseState CollapseState,
		float& OutCameraShakeAmplitude,
		float& OutDustFogDensity,
		float& OutRadialBlur);
};
