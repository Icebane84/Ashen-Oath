// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenAudioSliceStateAdapterComponent.h"

UAshenAudioSliceStateAdapterComponent::UAshenAudioSliceStateAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenAudioSliceStateAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	WhisperVolumeMultiplier = FMath::Clamp(NewState.Corruption, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenAudioSliceStateAdapterComponent: Whisper volume multiplier updated to %.2f"), WhisperVolumeMultiplier);
}
