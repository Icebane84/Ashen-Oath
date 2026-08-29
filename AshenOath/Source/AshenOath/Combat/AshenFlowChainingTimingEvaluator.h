// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenFlowChainingTimingEvaluator.generated.h"

/**
 * UAshenFlowChainingTimingEvaluator
 * 
 * Evaluates rhythm-timed recovery cancels, stamina cost reductions (0 stamina on clean glint), and momentum damage bonuses.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFlowChainingTimingEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFlowChainingTimingEvaluator();

	/** Evaluates whether transition timing hits the Flow Glint window */
	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Flow")
	bool IsWithinFlowGlintWindow(float CurrentTime, float WindowStart, float WindowDuration) const;

	/** Evaluates stamina cost for stance transition [0.0 on clean flow, 15.0 on missed] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Flow")
	float EvaluateTransitionStaminaCost(EFlowChainingTimingQuality Quality) const;

	/** Evaluates momentum bonus damage percentage on next attack [+25% on clean flow] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Flow")
	float EvaluateMomentumDamageBonus(EFlowChainingTimingQuality Quality) const;
};
