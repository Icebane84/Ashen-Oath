// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenRubbleClearingDirectorComponent.generated.h"

/**
 * UAshenRubbleClearingDirectorComponent
 * 
 * Coordinates trio demolition abilities, thermal shock durability decay (-60%), and explosive scatter physics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRubbleClearingDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRubbleClearingDirectorComponent();

	/** Evaluates rubble clearing efficiency bonus based on thermal shock */
	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble|Demolition")
	float EvaluateDemolitionEfficiency(bool bThermalShockActive) const;

	/** Calculates explosive debris scatter velocity from breaching charges */
	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble|Demolition")
	FVector EvaluateScatterVelocity(const FVector& ImpactNormal, float ExplosiveYield) const;
};
