// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMassKineticTypes.h"
#include "AshenWeaponResistanceWarperComponent.generated.h"

/**
 * UAshenWeaponResistanceWarperComponent
 * 
 * Dynamically slows AnimMontage playback speed down to a 0.08 floor as the blade
 * cuts through solid matter.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeaponResistanceWarperComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeaponResistanceWarperComponent();

	/** Calculates modified play rate based on cutting volume */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Kinetic")
	float CalculatePlayRateForVolume(float SubmergedVolumeCM3) const;
};
