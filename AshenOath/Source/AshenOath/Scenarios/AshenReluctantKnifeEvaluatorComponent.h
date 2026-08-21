// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenReluctantKnifeEvaluatorComponent.generated.h"

/**
 * UAshenReluctantKnifeEvaluatorComponent
 * 
 * Evaluates Elder Valerius's Reluctant Knife ethos and emotional exhaustion levels.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenReluctantKnifeEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenReluctantKnifeEvaluatorComponent();

	/** Evaluates Elder Valerius's dialogue stance and emotional exhaustion */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario1")
	EReluctantKnifeEthos EvaluateValeriusStance(float BattleDurationSeconds, float RitualHealthLost) const;

	/** Generates Valerius's dialogue bark conveying strategic exhaustion */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario1")
	FText EvaluateValeriusDialogueBark(EReluctantKnifeEthos Ethos) const;
};
