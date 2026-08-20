// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenEpistemicAIDirectorComponent.h"

UAshenEpistemicAIDirectorComponent::UAshenEpistemicAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEpistemicAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenEpistemicAIDirectorComponent::AdaptTacticalState(EConsequenceProfileTier Tier, bool bIsSynarchy)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenEpistemicAIDirectorComponent: Adapted AI Tactical State -> Tier: %d, Synarchy: %s"),
		static_cast<int32>(Tier), bIsSynarchy ? TEXT("TRUE") : TEXT("FALSE"));
}
