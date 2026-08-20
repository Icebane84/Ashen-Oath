// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenVoidRiftVFXEmitterActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVoidRiftTriggeredSignature, FVector, RiftLocation, float, RiftScale);

/**
 * AAshenVoidRiftVFXEmitterActor
 *
 * World Actor emitting dark void rift geometry & lighting FX beneath Malakor (Where Light Fades Act 01).
 */
UCLASS()
class ASHENOATH_API AAshenVoidRiftVFXEmitterActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenVoidRiftVFXEmitterActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VoidRift")
	void TriggerVoidRiftVFX(float Scale = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VoidRift|Events")
	FOnVoidRiftTriggeredSignature OnVoidRiftTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|VoidRift")
	bool bIsRiftOpen = false;
};
