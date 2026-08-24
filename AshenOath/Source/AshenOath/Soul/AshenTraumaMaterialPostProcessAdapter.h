// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenTraumaMaterialPostProcessAdapter.generated.h"

/**
 * UAshenTraumaMaterialPostProcessAdapter
 * 
 * Drives dynamic material collection scalars and post-process chromatic aberration from somatic state.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraumaMaterialPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTraumaMaterialPostProcessAdapter();

	/** Computes post-process chromatic aberration intensity from somatic stage */
	UFUNCTION(BlueprintPure, Category = "Ashen|Somatics|PostProcess")
	float EvaluateChromaticAberrationIntensity(ETraumaSomaticStage Stage) const;
};
