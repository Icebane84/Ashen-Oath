// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenProceduralVeinCorruptionEvaluator.generated.h"

/**
 * UAshenProceduralVeinCorruptionEvaluator
 * 
 * Computes procedural shader parameters for subcutaneous vein darkening, pallor, and sclera red-out.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenProceduralVeinCorruptionEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenProceduralVeinCorruptionEvaluator();

	/** Computes procedural vein corruption scalar [0.0, 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Somatics")
	float ComputeVeinCorruption(float IntegrationDebt, float ShadowBurnout) const;

	/** Computes skin pallor desaturation scalar [0.0, 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Somatics")
	float ComputeSkinPallor(float IntegrationDebt) const;

	/** Computes sclera blood vessel dilation scalar [0.0, 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Somatics")
	float ComputeScleraRedness(float IntegrationDebt) const;
};
