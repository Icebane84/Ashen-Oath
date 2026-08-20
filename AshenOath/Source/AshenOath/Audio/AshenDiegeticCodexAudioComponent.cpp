// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticCodexAudioComponent.h"

UAshenDiegeticCodexAudioComponent::UAshenDiegeticCodexAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticCodexAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticCodexAudioComponent::PlayCodexUnlockAudio(ECodexFaction Faction)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticCodexAudioComponent: Played Codex Unlock Audio for Faction %d."),
		static_cast<int32>(Faction));
}

void UAshenDiegeticCodexAudioComponent::PlayWhisperEchoCue()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticCodexAudioComponent: Played ANCIENT LORE WHISPER ECHO CUE."));
}
