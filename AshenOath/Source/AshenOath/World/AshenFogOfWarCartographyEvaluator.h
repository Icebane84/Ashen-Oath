// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenFogOfWarCartographyEvaluator.generated.h"

/**
 * UAshenFogOfWarCartographyEvaluator
 * 
 * Computes exploration revelation radii based on elevation, torchlight, and high-ground vantage points.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFogOfWarCartographyEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFogOfWarCartographyEvaluator();

	/** Evaluates dynamic fog unveil radius in Unreal Units [500 to 2500 uu] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Map|Fog")
	float EvaluateFogUnveilRadius(float ElevationZ, bool bHasTorchLit, bool bIsLookoutPoint) const;

	/** Checks if a point on the map is unveiled by exploration radius */
	UFUNCTION(BlueprintPure, Category = "Ashen|Map|Fog")
	bool IsLocationUnveiled(const FVector& Center, float UnveilRadius, const FVector& QueryLocation) const;
};
