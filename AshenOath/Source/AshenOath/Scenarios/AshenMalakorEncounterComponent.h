// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenMalakorEncounterComponent.generated.h"

/**
 * UAshenMalakorEncounterComponent
 * 
 * Manages Brother Malakor's boss phase thresholds, Void Smash damage, and Null Zone activation.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMalakorEncounterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMalakorEncounterComponent();

	/** Evaluates current boss phase based on remaining health percentage */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario1")
	EMalakorBossPhase EvaluatePhase(float HealthPercent) const;

	/** Evaluates void smash damage scaled by active phase */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario1")
	float EvaluateVoidSmashDamage(EMalakorBossPhase Phase, float BaseDamage) const;
};
