// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenSymbioticFlowPostProcessAdapter.generated.h"

/**
 * UAshenSymbioticFlowPostProcessAdapter
 * 
 * Drives golden radiant bloom, lens flare warmth, and chromatic aberration cancellation during Symbiotic Flow.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSymbioticFlowPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSymbioticFlowPostProcessAdapter();

	/** Evaluates golden bloom intensity [0.0 to 1.5] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|PostProcess")
	float EvaluateGoldenBloomIntensity(ECombatFlowState FlowState) const;

	/** Evaluates chromatic aberration damping multiplier [0.0 (fully damped) to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|PostProcess")
	float EvaluateChromaticDamping(ECombatFlowState FlowState) const;
};
