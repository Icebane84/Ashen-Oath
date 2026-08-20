// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenUnreliableNeedleHeavyAttackCameraShakeModulator.h"

UAshenUnreliableNeedleHeavyAttackCameraShakeModulator::UAshenUnreliableNeedleHeavyAttackCameraShakeModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenUnreliableNeedleHeavyAttackCameraShakeModulator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	CameraShakeMagnitudeMultiplier = 1.0f + (NewState.Isolation * 1.8f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableNeedleHeavyAttackCameraShakeModulator: Heavy attack camera shake multiplier set to %.2f"), CameraShakeMagnitudeMultiplier);
}
