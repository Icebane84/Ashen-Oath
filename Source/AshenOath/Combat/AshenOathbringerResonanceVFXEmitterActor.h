// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenOathbringerResonanceVFXEmitterActor.generated.h"

/**
 * AAshenOathbringerResonanceVFXEmitterActor
 * Spawns Oathbringer sword resonance particle FX on corruption spikes.
 */
UCLASS()
class ASHENOATH_API AAshenOathbringerResonanceVFXEmitterActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenOathbringerResonanceVFXEmitterActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void TriggerSwordResonanceVFX(float Intensity);
};
