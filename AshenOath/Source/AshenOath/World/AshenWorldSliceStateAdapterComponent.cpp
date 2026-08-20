// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenWorldSliceStateAdapterComponent.h"

UAshenWorldSliceStateAdapterComponent::UAshenWorldSliceStateAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWorldSliceStateAdapterComponent::SubmitEnvironmentalImprint(float CorruptionTrauma)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenWorldSliceStateAdapterComponent: World slice submitting imprint (Trauma: %.2f)"), CorruptionTrauma);
}

void UAshenWorldSliceStateAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	WeatherTension = FMath::Clamp((NewState.Corruption * 0.7f) + ((1.0f - NewState.Resolve) * 0.3f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenWorldSliceStateAdapterComponent: Weather tension scalar updated to %.2f"), WeatherTension);
}
