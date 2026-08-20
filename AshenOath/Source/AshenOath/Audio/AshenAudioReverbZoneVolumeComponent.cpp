// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 268: Ashen Audio Reverb Zone Volume Component

#include "AshenAudioReverbZoneVolumeComponent.h"
#include "Engine/World.h"

UAshenAudioReverbZoneVolumeComponent::UAshenAudioReverbZoneVolumeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	EnvironmentPreset = EAshenReverbPreset::CaveCathedral;
	FadeTimeSeconds = 2.0f;
}

void UAshenAudioReverbZoneVolumeComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenAudioReverbZoneVolumeComponent::TriggerReverbTransition()
{
	if (GetWorld())
	{
		UAshenAudioReverbSubsystem* ReverbSub = GetWorld()->GetSubsystem<UAshenAudioReverbSubsystem>();
		if (ReverbSub)
		{
			ReverbSub->SetReverbPreset(EnvironmentPreset);
		}
	}

	OnReverbZoneEntered.Broadcast(EnvironmentPreset, FadeTimeSeconds);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAudioReverbZoneVolumeComponent: REVERB ZONE ENTERED -> Preset %d (Fade: %.1fs)."),
		(int32)EnvironmentPreset, FadeTimeSeconds);
}
