// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Haptics/AshenControllerSpeakerWhisperComponent.h"

UAshenControllerSpeakerWhisperComponent::UAshenControllerSpeakerWhisperComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bSpeakerEnabled = true;
}

FTactileWhisperPayload UAshenControllerSpeakerWhisperComponent::PrepareWhisper(
	ETactileWhisperChannel Channel,
	const FString& DialogueLine,
	float Volume)
{
	FTactileWhisperPayload Payload;
	Payload.Channel = Channel;
	Payload.DialogueLine = DialogueLine;
	Payload.VolumeMultiplier = FMath::Clamp(Volume, 0.0f, 1.5f);
	Payload.bIncludeHapticTick = true;
	return Payload;
}
