// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenCognitiveFracturePostProcessAdapter.generated.h"

/**
 * UAshenCognitiveFracturePostProcessAdapter
 * 
 * Adapts screen-space post-processing during high cognitive dissonance (D > 0.75): applies spectral chromatic ghosting, memory static film grain, and edge darkening.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCognitiveFracturePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCognitiveFracturePostProcessAdapter();

	/** Evaluates post-process parameters for current cognitive dissonance */
	UFUNCTION(BlueprintPure, Category = "Ashen|CSE|PostProcess")
	void EvaluateFracturePostProcess(
		float DissonanceIndex,
		float& OutSpectralGhosting,
		float& OutMemoryFilmGrain,
		float& OutEdgeDarkening) const;
};
