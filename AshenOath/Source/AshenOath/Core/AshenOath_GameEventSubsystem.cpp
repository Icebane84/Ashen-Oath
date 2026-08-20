// Fill out your copyright notice in the Description page of Project Settings.


#include "AshenOath_GameEventSubsystem.h"
#include "CombatEnemy.h"
#include "Sound/SoundBase.h"

void UAshenOath_GameEventSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UAshenOath_GameEventSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UAshenOath_GameEventSubsystem::BroadcastPlayerDied()
{
	if (OnPlayerDied.IsBound())
	{
		OnPlayerDied.Broadcast();
	}
}

void UAshenOath_GameEventSubsystem::BroadcastItemCollected(FName ItemID)
{
	if (OnItemCollected.IsBound())
	{
		OnItemCollected.Broadcast(ItemID);
	}
}

void UAshenOath_GameEventSubsystem::BroadcastCombatStateChanged(bool bInCombat)
{
	if (OnCombatStateChanged.IsBound())
	{
		OnCombatStateChanged.Broadcast(bInCombat);
	}
}

void UAshenOath_GameEventSubsystem::BroadcastFootstepOccurred(FVector Position, FVector Normal)
{
	if (OnFootstepOccurred.IsBound())
	{
		OnFootstepOccurred.Broadcast(Position, Normal);
	}
}

void UAshenOath_GameEventSubsystem::BroadcastBossSpawned(ACombatEnemy* BossActor)
{
	if (OnBossSpawned.IsBound())
	{
		OnBossSpawned.Broadcast(BossActor);
	}
}

void UAshenOath_GameEventSubsystem::BroadcastBossPhaseChanged(int32 PhaseIndex, float SpeedMultiplier)
{
	if (OnBossPhaseChanged.IsBound())
	{
		OnBossPhaseChanged.Broadcast(PhaseIndex, SpeedMultiplier);
	}
}

void UAshenOath_GameEventSubsystem::BroadcastVfxRequested(FName EffectName, FVector Position, FRotator Rotation)
{
	if (OnVfxRequested.IsBound())
	{
		OnVfxRequested.Broadcast(EffectName, Position, Rotation);
	}
}

void UAshenOath_GameEventSubsystem::BroadcastSpatialSoundRequested(USoundBase* Sound, FVector Position, float VolumeMultiplier, float PitchMultiplier)
{
	if (OnSpatialSoundRequested.IsBound())
	{
		OnSpatialSoundRequested.Broadcast(Sound, Position, VolumeMultiplier, PitchMultiplier);
	}
}

void UAshenOath_GameEventSubsystem::BroadcastManifestationTriggered(FString ManifestationType, float Instability, FString Description)
{
	OnManifestationTriggered.Broadcast(ManifestationType, Instability, Description);
}

void UAshenOath_GameEventSubsystem::BroadcastCombatEventFired(FString EventType, AActor* Source, AActor* Target, float Magnitude)
{
	OnCombatEventFired.Broadcast(EventType, Source, Target, Magnitude);
}

void UAshenOath_GameEventSubsystem::BroadcastPlayerManaChanged(float CurrentMana, float MaxMana)
{
	if (OnPlayerManaChanged.IsBound())
	{
		OnPlayerManaChanged.Broadcast(CurrentMana, MaxMana);
	}
}

void UAshenOath_GameEventSubsystem::BroadcastSanctuaryRested()
{
	if (OnSanctuaryRested.IsBound())
	{
		OnSanctuaryRested.Broadcast();
	}
}

void UAshenOath_GameEventSubsystem::BroadcastInteractionHintShown(const FString& HintText)
{
	if (OnInteractionHintShown.IsBound())
	{
		OnInteractionHintShown.Broadcast(HintText);
	}
}

void UAshenOath_GameEventSubsystem::BroadcastInteractionHintHidden()
{
	if (OnInteractionHintHidden.IsBound())
	{
		OnInteractionHintHidden.Broadcast();
	}
}
