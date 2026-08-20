// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticCompanionFatigueAudioComponent.h"

UAshenDiegeticCompanionFatigueAudioComponent::UAshenDiegeticCompanionFatigueAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticCompanionFatigueAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticCompanionFatigueAudioComponent::PlayFatigueBreathingCue(FName CompanionID, float FatigueLevel)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticCompanionFatigueAudioComponent: Played fatigue breathing audio for %s (Fatigue: %.2f)."),
		*CompanionID.ToString(), FatigueLevel);
}

void UAshenDiegeticCompanionFatigueAudioComponent::PlayResonanceHarmonicChime()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticCompanionFatigueAudioComponent: Played RESONANCE HARMONIC CHIME audio cue."));
}
