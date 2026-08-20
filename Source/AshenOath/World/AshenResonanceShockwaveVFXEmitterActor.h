// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenResonanceShockwaveVFXEmitterActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResonanceShockwaveTriggeredSignature, FVector, WaveLocation, float, WaveScale);

/**
 * AAshenResonanceShockwaveVFXEmitterActor
 *
 * World Actor emitting golden wave particle FX during Resonance Cleave (PRS-001 Oathbringer Slice).
 */
UCLASS()
class ASHENOATH_API AAshenResonanceShockwaveVFXEmitterActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenResonanceShockwaveVFXEmitterActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ResonanceVFX")
	void TriggerResonanceShockwaveVFX(float Scale = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ResonanceVFX|Events")
	FOnResonanceShockwaveTriggeredSignature OnResonanceShockwaveTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ResonanceVFX")
	bool bIsWaveActive = false;
};
