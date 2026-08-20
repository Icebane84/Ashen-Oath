// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 233: Ashen Audio Spatial Voice Component

#include "AshenAudioSpatialVoiceComponent.h"

UAshenAudioSpatialVoiceComponent::UAshenAudioSpatialVoiceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxVoiceDistance = 1500.0f;
}

void UAshenAudioSpatialVoiceComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenAudioSpatialVoiceComponent::PlaySpatialDialogueBark(FName VoiceLineID, float Duration)
{
	OnDialogueBarkPlayed.Broadcast(VoiceLineID, Duration);

	const FVector Location = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;

	UE_LOG(LogTemp, Warning, TEXT("UAshenAudioSpatialVoiceComponent: SPATIAL BARK '%s' played at (%.0f, %.0f, %.0f) — Duration: %.1fs, MaxDist: %.0fu."),
		*VoiceLineID.ToString(), Location.X, Location.Y, Location.Z, Duration, MaxVoiceDistance);
}
