// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUnreliableNeedleParryVFXModulator.generated.h"

/**
 * UAshenUnreliableNeedleParryVFXModulator
 * Modulates parry impact spark particle intensity based on Isolation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliableNeedleParryVFXModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenUnreliableNeedleParryVFXModulator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetSparkParticleScaleMultiplier() const { return SparkParticleScaleMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float SparkParticleScaleMultiplier = 1.0f;
};
