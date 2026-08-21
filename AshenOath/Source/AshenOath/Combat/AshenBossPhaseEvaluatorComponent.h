// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossArenaTypes.h"
#include "AshenBossPhaseEvaluatorComponent.generated.h"

/**
 * UAshenBossPhaseEvaluatorComponent
 * 
 * Evaluates boss health percentages and determines phase transitions.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossPhaseEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBossPhaseEvaluatorComponent();

	/** Evaluates boss health and returns true if phase changed */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss|Combat")
	bool EvaluateHealth(float HealthPercent, EBossEncounterPhase& OutCurrentPhase);

	UFUNCTION(BlueprintPure, Category = "Ashen|Boss|Combat")
	EBossEncounterPhase GetCurrentPhase() const { return CurrentPhase; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Boss|Combat")
	EBossEncounterPhase CurrentPhase = EBossEncounterPhase::Phase1_Guardian;
};
