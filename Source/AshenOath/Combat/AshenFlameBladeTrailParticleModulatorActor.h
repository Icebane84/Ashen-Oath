// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenFlameBladeTrailParticleModulatorActor.generated.h"

/**
 * AAshenFlameBladeTrailParticleModulatorActor
 * World actor scaling Flame Blade ribbon trail length based on Corruption.
 */
UCLASS()
class ASHENOATH_API AAshenFlameBladeTrailParticleModulatorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenFlameBladeTrailParticleModulatorActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	float GetRibbonTrailLengthScalar() const { return RibbonTrailLengthScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|VFX")
	float RibbonTrailLengthScalar = 1.0f;
};
