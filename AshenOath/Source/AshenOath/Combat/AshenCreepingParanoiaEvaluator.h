// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenCreepingParanoiaEvaluator.generated.h"

/**
 * UAshenCreepingParanoiaEvaluator
 * 
 * Computes peripheral hallucination spawn angles (>= 45 deg), chromatic jitter, and eye-contact grounding decay (-0.15/s).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCreepingParanoiaEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCreepingParanoiaEvaluator();

	/** Evaluates whether a peripheral phantom is visible given camera angle relative to phantom direction */
	UFUNCTION(BlueprintPure, Category = "Ashen|Paranoia")
	bool IsPeripheralPhantomVisible(float AngleToCameraDegrees) const;

	/** Calculates chromatic aberration jitter scalar [0.0 to 4.5] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Paranoia")
	float EvaluateChromaticJitter(float Infection01) const;

	/** Evaluates dark oily vignette intensity [0.0 to 0.85] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Paranoia")
	float EvaluateParanoiaVignette(float Infection01) const;

	/** Evaluates grounding decay rate from companion eye contact */
	UFUNCTION(BlueprintPure, Category = "Ashen|Paranoia")
	float EvaluateGroundingDecayRate(bool bHasCompanionEyeContact) const;
};
