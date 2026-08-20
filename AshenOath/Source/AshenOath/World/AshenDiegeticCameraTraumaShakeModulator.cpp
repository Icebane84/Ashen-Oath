// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenDiegeticCameraTraumaShakeModulator.h"

UAshenDiegeticCameraTraumaShakeModulator::UAshenDiegeticCameraTraumaShakeModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticCameraTraumaShakeModulator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	CameraTraumaScalar = FMath::Clamp((NewState.Corruption * 0.6f) + ((1.0f - NewState.Resolve) * 0.4f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticCameraTraumaShakeModulator: Camera trauma micro-shake scalar updated to %.2f"), CameraTraumaScalar);
}
