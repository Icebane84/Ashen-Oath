// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenGlassShatterSilverDustVFXEmitterActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSilverDustShatterTriggeredSignature, FVector, ShatterLocation, float, ParticleBurstCount);

/**
 * AAshenGlassShatterSilverDustVFXEmitterActor
 *
 * World Actor emitting silver dust particles & glass shatter FX when resisting the Devil's Bargain (PRS-001-UI-006).
 */
UCLASS()
class ASHENOATH_API AAshenGlassShatterSilverDustVFXEmitterActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenGlassShatterSilverDustVFXEmitterActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SilverDustVFX")
	void TriggerSilverDustShatterVFX(float BurstScale = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SilverDustVFX|Events")
	FOnSilverDustShatterTriggeredSignature OnSilverDustShatterTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SilverDustVFX")
	bool bIsShatterActive = false;
};
