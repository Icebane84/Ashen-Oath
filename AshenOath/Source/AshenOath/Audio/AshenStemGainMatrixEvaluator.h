// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenStemGainMatrixEvaluator.generated.h"

/**
 * UAshenStemGainMatrixEvaluator
 * 
 * Computes individual stem gains [0.0 to 1.0] for the 6 Quartz stems according to WLF-AUD-001 specification.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStemGainMatrixEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenStemGainMatrixEvaluator();

	/** Calculates volume gain for a specific stem */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Quartz")
	float EvaluateStemGain(
		EQuartzAudioStem Stem,
		float Corruption01,
		float Burnout01,
		ECombatFlowState FlowState) const;
};
