// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 437: Ashen Generative World State Component

#include "AshenGenerativeWorldStateComponent.h"

UAshenGenerativeWorldStateComponent::UAshenGenerativeWorldStateComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGenerativeWorldStateComponent::UpdateGenerativeWorldState(const FAshenSoulStateVector& SoulVector)
{
	CalculatedWeatherTension = FMath::Clamp((SoulVector.CorruptionLevel * 0.5f) + (SoulVector.IntegrationDebt * 0.5f), 0.0f, 100.0f);
	CalculatedMusicDissonance = FMath::Clamp((100.0f - SoulVector.Sanity) * 0.8f + (SoulVector.UnchainedVesselLevel * 0.2f), 0.0f, 100.0f);

	OnGenerativeWorldUpdated.Broadcast(CalculatedWeatherTension, CalculatedMusicDissonance);

	UE_LOG(LogTemp, Log, TEXT("UAshenGenerativeWorldStateComponent: GENERATIVE WORLD STATE UPDATED — Weather Tension: %.1f | Music Dissonance: %.1f"),
		CalculatedWeatherTension, CalculatedMusicDissonance);
}


