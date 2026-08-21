// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenWeaponAttunementEvaluatorComponent.generated.h"

/**
 * UAshenWeaponAttunementEvaluatorComponent
 * 
 * Computes kinetic damage bonuses, poise break potential, and stamina cost
 * adjustments based on active runic socket configurations.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeaponAttunementEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeaponAttunementEvaluatorComponent();

	/** Evaluates total effective kinetic strike energy (Joules) */
	UFUNCTION(BlueprintPure, Category = "Ashen|Reliquary")
	float EvaluateKineticEnergy(const FSoulForgeWeaponState& State, float SwingVelocity) const;

	/** Evaluates stamina drain scalar for melee swings */
	UFUNCTION(BlueprintPure, Category = "Ashen|Reliquary")
	float EvaluateStaminaCostScalar(const FSoulForgeWeaponState& State) const;
};
