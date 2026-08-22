// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenAngularCounterComponent.generated.h"

/**
 * UAshenAngularCounterComponent
 * 
 * Inverts incoming strike vectors and computes 2D clock-face angles to drive matching counter-riposte montages.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAngularCounterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAngularCounterComponent();

	/** Calculates 4-zone counter trajectory and blend angle from incoming strike */
	UFUNCTION(BlueprintCallable, Category = "Ashen|KineticBerserk")
	EAshenCounterAttackZone CalculateCounterTrajectory(
		const FVector& AttackerLocation,
		const FVector& AttackDirection,
		float& OutTargetBlendAngleDegrees) const;
};
