// Copyright Phoenix Protocol. All rights reserved.

#include "AshenAudioSubsystem.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

void UAshenAudioSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UGameInstance* GI = GetGameInstance();
	if (GI)
	{
		if (UAshenOath_GameEventSubsystem* GameEvents = GI->GetSubsystem<UAshenOath_GameEventSubsystem>())
		{
			GameEvents->OnSpatialSoundRequested.AddDynamic(this, &UAshenAudioSubsystem::HandleSpatialSoundRequested);
		}
	}
}

void UAshenAudioSubsystem::PlaySpatialSound(USoundBase* Sound, FVector Position, float VolumeMultiplier, float PitchMultiplier)
{
	UWorld* World = GetWorld();
	if (World && Sound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			World,
			Sound,
			Position,
			VolumeMultiplier,
			PitchMultiplier
		);
	}
}

void UAshenAudioSubsystem::PlayStaticSound(USoundBase* Sound, float VolumeMultiplier, float PitchMultiplier)
{
	UWorld* World = GetWorld();
	if (World && Sound)
	{
		UGameplayStatics::PlaySound2D(
			World,
			Sound,
			VolumeMultiplier,
			PitchMultiplier
		);
	}
}

void UAshenAudioSubsystem::HandleSpatialSoundRequested(USoundBase* Sound, FVector Position, float VolumeMultiplier, float PitchMultiplier)
{
	PlaySpatialSound(Sound, Position, VolumeMultiplier, PitchMultiplier);
}
