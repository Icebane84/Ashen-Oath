// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenHarmonizedFinisherOrchestratorComponent.generated.h"

/**
 * UAshenHarmonizedFinisherOrchestratorComponent
 * 
 * Orchestrates the 3-person cinematic finisher, scaling damage and catharsis.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHarmonizedFinisherOrchestratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenHarmonizedFinisherOrchestratorComponent();

	/** Calculates scaled finisher damage based on tier */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Trio")
	float CalculateFinisherDamage(float BaseDamage, EHarmonizedFinisherTier Tier) const;
};
