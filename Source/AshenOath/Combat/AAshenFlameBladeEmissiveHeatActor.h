// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AAshenFlameBladeEmissiveHeatActor.generated.h"

/**
 * AAshenFlameBladeEmissiveHeatActor
 * World actor driving weapon heat emissive glow decay over time.
 */
UCLASS()
class ASHENOATH_API AAshenFlameBladeEmissiveHeatActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenFlameBladeEmissiveHeatActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	float GetHeatEmissiveIntensity() const { return HeatEmissiveIntensity; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|VFX")
	float HeatEmissiveIntensity = 2.0f;
};
