// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenRunicSeamEmissivePostProcessAdapter.generated.h"

/**
 * UAshenRunicSeamEmissivePostProcessAdapter
 * 
 * Directs post-process bloom and chromatic flare intensifications as Oathbringer's fuller seam glows during high-tier ascensions and flow resonance strikes.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRunicSeamEmissivePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRunicSeamEmissivePostProcessAdapter();

	/** Evaluates bloom and flare intensities */
	UFUNCTION(BlueprintPure, Category = "Ashen|RunicForge|PostProcess")
	void EvaluateSeamBloom(
		EOathbringerAscensionTier Tier,
		bool bResonating,
		float& OutBloomIntensity,
		float& OutLensFlareIntensity) const;
};
