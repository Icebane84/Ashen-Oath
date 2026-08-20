// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 218: Ashen Boss Phase Camera Shake Component

#include "AshenBossPhaseCameraShakeComponent.h"

UAshenBossPhaseCameraShakeComponent::UAshenBossPhaseCameraShakeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	BaseShakeScale = 1.0f;
}

void UAshenBossPhaseCameraShakeComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenBossPhaseCameraShakeComponent::TriggerCameraShake(float Intensity, float Duration)
{
	const float FinalIntensity = Intensity * BaseShakeScale;
	OnCameraShakeTriggered.Broadcast(FinalIntensity, Duration);

	UE_LOG(LogTemp, Warning, TEXT("UAshenBossPhaseCameraShakeComponent: CAMERA SHAKE TRIGGERED — Intensity: %.2f, Duration: %.2fs."),
		FinalIntensity, Duration);
}
