// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenStanceCameraTraumaAdapter.generated.h"

/**
 * UAshenStanceCameraTraumaAdapter
 * 
 * Drives dynamic camera trauma kick and FoV punch parameters depending on the active stance strike.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStanceCameraTraumaAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenStanceCameraTraumaAdapter();

	/** Evaluates camera shake trauma for active stance strike */
	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Camera")
	void EvaluateStanceCameraShake(
		EOathbringerMartialStance Stance,
		float& OutTraumaKick,
		float& OutFoVPunchDegrees) const;
};
