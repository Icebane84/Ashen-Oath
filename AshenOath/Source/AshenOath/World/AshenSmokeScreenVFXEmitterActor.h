// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSmokeScreenVFXEmitterActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSmokeScreenVFXTriggeredSignature, FVector, EmitterLocation, float, SmokeDensity);

/**
 * AAshenSmokeScreenVFXEmitterActor
 *
 * World Actor emitting dense volumetric smoke particle and lighting FX (PRS-001 Garrett Slice).
 */
UCLASS()
class ASHENOATH_API AAshenSmokeScreenVFXEmitterActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSmokeScreenVFXEmitterActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SmokeVFX")
	void TriggerSmokeScreenVFX(float Density = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SmokeVFX|Events")
	FOnSmokeScreenVFXTriggeredSignature OnSmokeVFXTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SmokeVFX")
	bool bIsEmitting = false;
};
