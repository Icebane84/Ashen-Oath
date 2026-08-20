// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AAshenAshenAuraEmberParticleActor.generated.h"

/**
 * AAshenAshenAuraEmberParticleActor
 * World actor spawning atmospheric embers around Kaelen when Corruption > 0.5.
 */
UCLASS()
class ASHENOATH_API AAshenAshenAuraEmberParticleActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenAshenAuraEmberParticleActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	float GetEmberSpawnRateMultiplier() const { return EmberSpawnRateMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|VFX")
	float EmberSpawnRateMultiplier = 0.0f;
};
