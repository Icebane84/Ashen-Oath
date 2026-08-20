// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMassKineticTypes.h"
#include "AshenAngularCounterComponent.generated.h"

/**
 * UAshenAngularCounterComponent
 * 
 * Maps 3D attack vectors to 2D local plane angles (0 to 360 deg) for precision
 * directional counter-slashing.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAngularCounterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAngularCounterComponent();

	/** Calculates local counter angle from incoming strike direction */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Kinetic")
	float CalculateCounterAngle(const FVector& ForwardVector, const FVector& IncomingVector) const;
};
