// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AAshenFlameBladeHeatDistortionActor.generated.h"

/**
 * AAshenFlameBladeHeatDistortionActor
 * World actor emitting heat haze distortion around Kaelen's weapon based on Dissonance.
 */
UCLASS()
class ASHENOATH_API AAshenFlameBladeHeatDistortionActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenFlameBladeHeatDistortionActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	float GetHeatHazeStrength() const { return HeatHazeStrength; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|VFX")
	float HeatHazeStrength = 1.0f;
};
