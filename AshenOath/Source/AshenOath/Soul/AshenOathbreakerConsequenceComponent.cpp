// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenOathbreakerConsequenceComponent.h"

UAshenOathbreakerConsequenceComponent::UAshenOathbreakerConsequenceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenOathbreakerConsequenceComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenOathbreakerConsequenceComponent::ApplyOathbreakerConsequences()
{
	bIsSwordRebelling = true;
	const float CorruptionDelta = 0.20f;
	const float PoisePenalty = 30.0f;

	if (OnOathbreakerPenaltyApplied.IsBound())
	{
		OnOathbreakerPenaltyApplied.Broadcast(CorruptionDelta, PoisePenalty);
	}
	UE_LOG(LogTemp, Error, TEXT("UAshenOathbreakerConsequenceComponent: OATHBREAKER CONSEQUENCES! +%.2f Corruption, -%.0f Poise, Sword Rebelling."),
		CorruptionDelta, PoisePenalty);
}
