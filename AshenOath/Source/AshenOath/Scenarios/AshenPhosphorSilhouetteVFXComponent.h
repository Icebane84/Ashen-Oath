// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenPhosphorSilhouetteVFXComponent.generated.h"

/**
 * UAshenPhosphorSilhouetteVFXComponent
 * 
 * Modulates high-contrast shadow silhouettes against White Flame phosphor emitters.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPhosphorSilhouetteVFXComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPhosphorSilhouetteVFXComponent();

	/** Evaluates silhouette contrast intensity */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario2|VFX")
	float EvaluateSilhouetteContrast(float FlareIntensity, float AmbientDarkness) const;
};
