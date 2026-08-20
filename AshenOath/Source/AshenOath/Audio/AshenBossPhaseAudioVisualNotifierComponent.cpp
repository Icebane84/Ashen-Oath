// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 208: Ashen Boss Phase AV Notifier Component

#include "AshenBossPhaseAudioVisualNotifierComponent.h"

UAshenBossPhaseAudioVisualNotifierComponent::UAshenBossPhaseAudioVisualNotifierComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenBossPhaseAudioVisualNotifierComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenBossPhaseAudioVisualNotifierComponent::NotifyPhaseTransition(int32 NewPhase, float Intensity)
{
	OnPhaseAVTriggered.Broadcast(NewPhase, Intensity);
	UE_LOG(LogTemp, Warning, TEXT("UAshenBossPhaseAudioVisualNotifierComponent: BOSS PHASE AV SEQUENCE TRIGGERED for Phase %d (Intensity: %.2f)."),
		NewPhase, Intensity);
}
