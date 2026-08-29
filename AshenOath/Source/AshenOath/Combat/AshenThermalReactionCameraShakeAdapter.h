// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenThermalReactionCameraShakeAdapter.generated.h"

/**
 * UAshenThermalReactionCameraShakeAdapter
 * 
 * Drives dynamic camera trauma kick and radial blur distortion during large thermal reactions (Conflagration 0.50 kick, Thermal Shock 0.35 kick).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenThermalReactionCameraShakeAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenThermalReactionCameraShakeAdapter();

	/** Evaluates camera trauma kick for thermal reaction */
	UFUNCTION(BlueprintPure, Category = "Ashen|AlchemicalSlag|Camera")
	void EvaluateReactionCameraShake(
		EThermalReactionType Reaction,
		float& OutTraumaKick,
		float& OutRadialBlurIntensity) const;
};
