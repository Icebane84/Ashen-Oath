// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 319: Ashen Audio Sanity Break Subsystem

#include "AshenAudioSanityBreakSubsystem.h"

void UAshenAudioSanityBreakSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bAudioMuffled = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenAudioSanityBreakSubsystem: Initialized — Tinnitus & Heartbeat Audio Subsystem active."));
}

void UAshenAudioSanityBreakSubsystem::TriggerSanityBreakAudioEffect(bool bEnableMuffle, float TargetBPM)
{
	bAudioMuffled = bEnableMuffle;
	OnSanityBreakAudioTriggered.Broadcast(bEnableMuffle, TargetBPM);

	if (bEnableMuffle)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenAudioSanityBreakSubsystem: SANITY BREAK AUDIO ENGAGED — Deafening Tinnitus & Heartbeat (%.0f BPM)."), TargetBPM);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenAudioSanityBreakSubsystem: Sanity break audio cleared. Normal acoustics restored."));
	}
}
