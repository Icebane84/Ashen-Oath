// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMassKineticTypes.h"
#include "AshenMassKineticCleaveComponent.generated.h"

/**
 * UAshenMassKineticCleaveComponent
 * 
 * Calculates kinetic energy across weapon blade sockets:
 * - Light Mode: 45kg mass
 * - Dark Mode: 180kg mass with 2.5x kinetic multiplier
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMassKineticCleaveComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMassKineticCleaveComponent();

	/** Calculates kinetic payload from stance and tip velocity */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Kinetic")
	FKineticSwingSnapshot CalculateKineticPayload(
		EKineticCleaveStance Stance,
		float BladeTipVelocityMetersPerSec) const;
};
