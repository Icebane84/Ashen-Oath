// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenWeatherAudioSpatializerAdapter.h"

UAshenWeatherAudioSpatializerAdapter::UAshenWeatherAudioSpatializerAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWeatherAudioSpatializerAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	ThunderAttenuationRadiusScalar = 1.0f + (NewState.IntegrationDebt * 1.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenWeatherAudioSpatializerAdapter: Thunder audio attenuation radius scalar set to %.2f"), ThunderAttenuationRadiusScalar);
}
