// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenChaosDebrisObstructionEvaluator.generated.h"

/**
 * UAshenChaosDebrisObstructionEvaluator
 * 
 * Computes dynamic navmesh blocking dimensions and determines whether pathfinding requires a detour or allows a vault.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenChaosDebrisObstructionEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenChaosDebrisObstructionEvaluator();

	/** Computes navmesh blocking radius in UU based on debris mass in kg [150uu to 800uu] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Chaos|Navmesh")
	float EvaluateNavmeshBlockingRadius(float DebrisMassKg) const;

	/** Classifies obstruction state based on debris height in UU */
	UFUNCTION(BlueprintPure, Category = "Ashen|Chaos|Navmesh")
	ENavmeshObstructionState ClassifyObstructionState(float DebrisHeightUU) const;
};
