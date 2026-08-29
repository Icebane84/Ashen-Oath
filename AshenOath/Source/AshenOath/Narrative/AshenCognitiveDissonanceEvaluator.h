// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenCognitiveDissonanceEvaluator.generated.h"

/**
 * UAshenCognitiveDissonanceEvaluator
 * 
 * Computes party synergy damage bonuses (+30% during harmony) and tandem stamina penalties (+20% during fracture).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCognitiveDissonanceEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCognitiveDissonanceEvaluator();

	/** Evaluates tandem synergy damage bonus [0.0 to +0.30] */
	UFUNCTION(BlueprintPure, Category = "Ashen|CSE|Evaluator")
	float EvaluateSynergyDamageBonus(float DissonanceIndex) const;

	/** Evaluates tandem stamina drain penalty [1.0x to 1.20x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|CSE|Evaluator")
	float EvaluateTandemStaminaMultiplier(float DissonanceIndex) const;

	/** Evaluates companion assist reaction delay in seconds [0.0s to 0.60s] */
	UFUNCTION(BlueprintPure, Category = "Ashen|CSE|Evaluator")
	float EvaluateCompanionAssistDelaySeconds(float DissonanceIndex) const;
};
