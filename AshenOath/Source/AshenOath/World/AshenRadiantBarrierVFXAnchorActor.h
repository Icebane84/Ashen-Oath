// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenRadiantBarrierVFXAnchorActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRadiantBarrierVFXTriggeredSignature, FVector, BarrierCenterLocation, float, GoldenLuminance);

/**
 * AAshenRadiantBarrierVFXAnchorActor
 *
 * World Actor anchoring volumetric golden light barrier VFX in level space (PRS-001 Serafina Slice).
 */
UCLASS()
class ASHENOATH_API AAshenRadiantBarrierVFXAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenRadiantBarrierVFXAnchorActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BarrierVFX")
	void TriggerRadiantBarrierVFX(float Luminance = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BarrierVFX|Events")
	FOnRadiantBarrierVFXTriggeredSignature OnBarrierVFXTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BarrierVFX")
	bool bIsLuminanceActive = false;
};
