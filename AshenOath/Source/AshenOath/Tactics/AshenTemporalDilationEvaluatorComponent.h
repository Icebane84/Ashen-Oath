// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenTemporalDilationEvaluatorComponent.generated.h"

/**
 * UAshenTemporalDilationEvaluatorComponent
 * 
 * Computes smoothed target time dilation values during tactical bullet-time states.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTemporalDilationEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTemporalDilationEvaluatorComponent();

	/** Evaluates target world time dilation factor */
	UFUNCTION(BlueprintPure, Category = "Ashen|Tactics")
	float EvaluateTargetDilation(ETemporalDilationState State) const;
};
