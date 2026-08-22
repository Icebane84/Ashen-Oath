// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenMassKineticNiagaraBridgeComponent.generated.h"

/**
 * UAshenMassKineticNiagaraBridgeComponent
 * 
 * Computes geometry back-face exit coordinates and directional shear vectors for planar particle instantiation.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMassKineticNiagaraBridgeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMassKineticNiagaraBridgeComponent();

	/** Calculates exit coordinate and velocity shear trajectory for Niagara dust sheets */
	UFUNCTION(BlueprintCallable, Category = "Ashen|KineticBerserk")
	FAshenNiagaraShearTraceData ComputeExitShearVector(
		const FVector& EntryPoint,
		const FVector& SwingTrajectory,
		float ObjectDepthCentimeters,
		float KineticJoules) const;
};
