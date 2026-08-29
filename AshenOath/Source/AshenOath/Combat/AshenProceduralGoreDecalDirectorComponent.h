// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenProceduralGoreDecalDirectorComponent.generated.h"

/**
 * UAshenProceduralGoreDecalDirectorComponent
 * 
 * Directs directional blood splatter decal transforms, volume scaling, and arterial spray splatters upon severance.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenProceduralGoreDecalDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenProceduralGoreDecalDirectorComponent();

	/** Evaluates decal orientation and scale */
	UFUNCTION(BlueprintPure, Category = "Ashen|Severance|Visuals")
	FTransform EvaluateDecalTransform(const FVector& Origin, const FVector& Normal, float SplatterVolume) const;
};
