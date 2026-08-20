// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticEpistemicAudioComponent.h"

UAshenDiegeticEpistemicAudioComponent::UAshenDiegeticEpistemicAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticEpistemicAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticEpistemicAudioComponent::PlayTierResolutionAudioCue(EConsequenceProfileTier Tier, bool bIsSynarchy)
{
	if (Tier == EConsequenceProfileTier::Milestone)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticEpistemicAudioComponent: Played MILESTONE HARMONIC CHIME (Synarchy: %s)."),
			bIsSynarchy ? TEXT("TRUE") : TEXT("FALSE"));
	}
	else if (Tier == EConsequenceProfileTier::Rare)
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticEpistemicAudioComponent: Played RARE TACTICAL STINGER."));
	}
}
