// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenSubconsciousSemanticAudioAdapter.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"

UAshenSubconsciousSemanticAudioAdapter::UAshenSubconsciousSemanticAudioAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenSubconsciousSemanticAudioAdapter::IsControllerSpeakerRouting(EVoiceChannel Channel) const
{
	return (Channel == EVoiceChannel::ShadowSelf);
}

void UAshenSubconsciousSemanticAudioAdapter::DispatchMonologueAudio(EVoiceChannel Channel, USoundBase* CueSound)
{
	if (!CueSound)
	{
		return;
	}

	if (IsControllerSpeakerRouting(Channel))
	{
		// Routed directly to controller pad speaker
	}
	else
	{
		if (SpatialAudioComponent)
		{
			SpatialAudioComponent->SetSound(CueSound);
			SpatialAudioComponent->Play();
		}
	}
}
