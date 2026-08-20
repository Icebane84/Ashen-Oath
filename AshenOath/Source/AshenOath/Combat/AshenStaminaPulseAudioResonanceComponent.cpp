// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenStaminaPulseAudioResonanceComponent.h"

UAshenStaminaPulseAudioResonanceComponent::UAshenStaminaPulseAudioResonanceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenStaminaPulseAudioResonanceComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	StaminaPantingPitch = FMath::Clamp(1.0f + (NewState.Corruption * 0.4f) - (NewState.Resolve * 0.2f), 0.7f, 1.6f);
	UE_LOG(LogTemp, Log, TEXT("UAshenStaminaPulseAudioResonanceComponent: Diegetic stamina panting audio pitch updated to %.2f"), StaminaPantingPitch);
}
