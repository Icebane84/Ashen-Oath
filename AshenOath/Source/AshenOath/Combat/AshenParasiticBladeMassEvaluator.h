// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenParasiticBladeMassEvaluator.generated.h"

/**
 * UAshenParasiticBladeMassEvaluator
 * 
 * Computes dynamic blade mass scaling, kinetic impact energy (Joules), and swing play-rate drag floors.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParasiticBladeMassEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenParasiticBladeMassEvaluator();

	/** Calculates blade mass in kg [45.0 to 220.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Blade|Mass")
	float EvaluateBladeMass(float Corruption01, bool bGloomwoodFrozen) const;

	/** Calculates kinetic impact damage multiplier [1.0x to 2.5x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Blade|Mass")
	float EvaluateKineticImpactMultiplier(float MassKg) const;

	/** Calculates animation swing drag play-rate floor [0.45 to 1.00] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Blade|Mass")
	float EvaluateSwingPlayRate(float MassKg) const;
};
