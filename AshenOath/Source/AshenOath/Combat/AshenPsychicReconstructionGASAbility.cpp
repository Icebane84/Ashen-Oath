// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenPsychicReconstructionGASAbility.h"

UAshenPsychicReconstructionGASAbility::UAshenPsychicReconstructionGASAbility()
{
	ReconstructionRadius = 1200.0f;
	ResolveCostPerSecond = 15.0f;
}

bool UAshenPsychicReconstructionGASAbility::ChannelReconstruction(AActor* InstigatorActor, float ChannelDuration)
{
	if (!InstigatorActor) return false;
	const float TotalCost = ResolveCostPerSecond * ChannelDuration;
	UE_LOG(LogTemp, Log, TEXT("UAshenPsychicReconstructionGASAbility: Channeled psychic reconstruction for %.1fs (Total Cost: %.1f Resolve, Radius: %.1fuu)."),
		ChannelDuration, TotalCost, ReconstructionRadius);
	return true;
}
