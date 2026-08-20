// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenSomaticSilenceTypes.h"
#include "AshenSilenceClassifierComponent.generated.h"

/**
 * UAshenSilenceClassifierComponent
 * 
 * Classifies silence into Contemplative, Traumatic Aftermath, or Destabilizing Crisis.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSilenceClassifierComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSilenceClassifierComponent();

	/** Classifies silence and calculates recommended companion spacing */
	UFUNCTION(BlueprintPure, Category = "Ashen|Silence")
	FSilenceEvaluationSnapshot ClassifySilence(
		float SilenceDuration,
		float CombatRecencySeconds,
		float AccumulatedDysregulation,
		bool bActiveMemoryTrigger) const;
};
