// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 203: Ashen Audio Reverb Subsystem

#include "AshenAudioReverbSubsystem.h"

void UAshenAudioReverbSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentPreset = EAshenReverbPreset::OpenAir;
	UE_LOG(LogTemp, Log, TEXT("UAshenAudioReverbSubsystem: Initialized — default OpenAir preset."));
}

void UAshenAudioReverbSubsystem::SetReverbPreset(EAshenReverbPreset Preset)
{
	if (Preset == CurrentPreset) return;

	CurrentPreset = Preset;
	OnReverbPresetChanged.Broadcast(CurrentPreset);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAudioReverbSubsystem: Audio Reverb Preset CHANGED to %d."), (int32)CurrentPreset);
}
