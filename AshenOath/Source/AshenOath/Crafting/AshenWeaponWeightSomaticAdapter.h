// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenWeaponWeightSomaticAdapter.generated.h"

/**
 * UAshenWeaponWeightSomaticAdapter
 * 
 * Translates active weapon mass into gamepad somatic friction resistance
 * and animation playrate modifiers.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeaponWeightSomaticAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeaponWeightSomaticAdapter();

	/** Computes the somatic resistance factor (0.0 to 1.0) based on weapon mass */
	UFUNCTION(BlueprintPure, Category = "Ashen|Reliquary|Somatic")
	float EvaluateSomaticResistance(float EffectiveMassKg) const;
};
