// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenRubbleMassImpulseEvaluator.generated.h"

/**
 * UAshenRubbleMassImpulseEvaluator
 * 
 * Computes kinetic impact impulse (F = m * a), fracture chunk mass distribution, and navmesh traversal cost penalties.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRubbleMassImpulseEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRubbleMassImpulseEvaluator();

	/** Evaluates navmesh traversal cost multiplier [1.0x to 4.5x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble|Physics")
	float EvaluateNavmeshCostModifier(ERubbleFractureTier FractureTier, float TotalMassKg) const;

	/** Evaluates kinetic impulse force from physical impact */
	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble|Physics")
	float EvaluateKineticImpulseForce(float MassKg, float ImpactVelocityMps) const;

	/** Determines if debris mass forms an impassable choke point */
	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble|Physics")
	bool IsChokePointImpassable(float TotalMassKg) const;
};
