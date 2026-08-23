// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenStateTreeReactionDelayEvaluator.generated.h"

/**
 * UAshenStateTreeReactionDelayEvaluator
 * 
 * Computes companion StateTree support hesitation latency (0ms to 600ms) based on relational alignment.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStateTreeReactionDelayEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenStateTreeReactionDelayEvaluator();

	/** Evaluates StateTree execution latency delay in milliseconds */
	UFUNCTION(BlueprintPure, Category = "Ashen|Waystation")
	float EvaluateHesitationLatencyMS(EWaystationRunMode Mode) const;
};
