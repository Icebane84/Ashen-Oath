// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenVoidWhisperVFXEmitterActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVoidWhisperVFXTriggeredSignature, FVector, EmitterLocation, float, DistortionIntensity);

/**
 * AAshenVoidWhisperVFXEmitterActor
 *
 * World Actor emitting dark void whisper particle/distortion FX in level space (UMB-INT-001 Memory Slice).
 */
UCLASS()
class ASHENOATH_API AAshenVoidWhisperVFXEmitterActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenVoidWhisperVFXEmitterActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VoidVFX")
	void TriggerVoidWhisperVFX(float Distortion = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VoidVFX|Events")
	FOnVoidWhisperVFXTriggeredSignature OnVoidWhisperVFXTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|VoidVFX")
	bool bIsDistorting = false;
};
