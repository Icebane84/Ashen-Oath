// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticVeinCreepModulator.generated.h"

/**
 * UAshenSomaticVeinCreepModulator
 *
 * Scales vein creep MPC material parameters driven by Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticVeinCreepModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticVeinCreepModulator();

	/** Modulates vein creep progress scalar (0.0 - 1.0) */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	void UpdateVeinCreep(float Corruption);

	/** Returns current vein creep progress */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	float GetVeinCreepScalar() const { return VeinCreepScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Somatic")
	float VeinCreepScalar = 0.0f;
};
