// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBossPhaseCameraShakeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBossCameraShakeTriggeredSignature, float, Intensity, float, Duration);

/**
 * UAshenBossPhaseCameraShakeComponent
 *
 * Drives directional camera shake impulses during heavy boss impacts, land slams, and phase shifts.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossPhaseCameraShakeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBossPhaseCameraShakeComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CameraShake")
	void TriggerCameraShake(float Intensity = 1.0f, float Duration = 0.5f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|CameraShake")
	float BaseShakeScale = 1.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CameraShake|Events")
	FOnBossCameraShakeTriggeredSignature OnCameraShakeTriggered;
};
