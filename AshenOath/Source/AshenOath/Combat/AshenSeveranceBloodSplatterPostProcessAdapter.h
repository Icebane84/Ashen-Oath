// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenSeveranceBloodSplatterPostProcessAdapter.generated.h"

/**
 * UAshenSeveranceBloodSplatterPostProcessAdapter
 * 
 * Directs post-process lens blood mask opacity and chromatic edge flares during high-severity executioner cleaves.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSeveranceBloodSplatterPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSeveranceBloodSplatterPostProcessAdapter();

	/** Evaluates lens blood splatter intensity */
	UFUNCTION(BlueprintPure, Category = "Ashen|Severance|PostProcess")
	float EvaluateLensBloodIntensity(ESeveranceSeverityTier Severity) const;
};
