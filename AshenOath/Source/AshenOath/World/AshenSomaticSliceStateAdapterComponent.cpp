// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSomaticSliceStateAdapterComponent.h"

UAshenSomaticSliceStateAdapterComponent::UAshenSomaticSliceStateAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticSliceStateAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	EyeEmissiveIntensity = FMath::Clamp(NewState.Corruption * 5.0f, 0.0f, 5.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticSliceStateAdapterComponent: Eye emissive intensity updated to %.2f"), EyeEmissiveIntensity);
}
