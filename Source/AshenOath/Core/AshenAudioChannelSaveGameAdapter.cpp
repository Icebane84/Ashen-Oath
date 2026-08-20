// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenAudioChannelSaveGameAdapter.h"

UAshenAudioChannelSaveGameAdapter::UAshenAudioChannelSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAudioChannelSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenAudioChannelSaveGameAdapter::SaveAudioChannelSettings(bool bSpeakerEnabled, float SpeakerVol, bool bHeadphoneMix)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenAudioChannelSaveGameAdapter: Saved Audio Settings -> Speaker: %s, Vol: %.2f, Downmix: %s"),
		bSpeakerEnabled ? TEXT("ON") : TEXT("OFF"), SpeakerVol, bHeadphoneMix ? TEXT("ON") : TEXT("OFF"));
	return true;
}
