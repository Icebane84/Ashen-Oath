// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenMindscapeSpectralPostProcessAdapter.generated.h"

/**
 * UAshenMindscapeSpectralPostProcessAdapter
 * 
 * Drives post-process spectral distortions inside the Memory Palace: Holographic chromatic aberration, scanline grids, and radiant White Flame illumination.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMindscapeSpectralPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMindscapeSpectralPostProcessAdapter();

	/** Evaluates post-process parameters */
	UFUNCTION(BlueprintPure, Category = "Ashen|Mindscape|PostProcess")
	void EvaluateSpectralPostProcess(
		bool bInsideMindscape,
		float SynthesisScore,
		float& OutSpectralAberrationIntensity,
		float& OutHolographicScanlineIntensity) const;
};
