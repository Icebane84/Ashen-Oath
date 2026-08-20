// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenUnreliableNeedlePerceptionNoiseModulator.h"

UAshenUnreliableNeedlePerceptionNoiseModulator::UAshenUnreliableNeedlePerceptionNoiseModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenUnreliableNeedlePerceptionNoiseModulator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	NeedleNoiseIntensity = FMath::Clamp((NewState.Isolation * 0.6f) + (NewState.Corruption * 0.4f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableNeedlePerceptionNoiseModulator: Needle noise intensity updated to %.2f"), NeedleNoiseIntensity);
}
