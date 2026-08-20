// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenEpistemicCompanionReactionAdapter.h"

UAshenEpistemicCompanionReactionAdapter::UAshenEpistemicCompanionReactionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEpistemicCompanionReactionAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenEpistemicCompanionReactionAdapter::UpdateCompanionCampAttitude(EConsequenceProfileTier Tier, bool bIsSynarchy)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenEpistemicCompanionReactionAdapter: Updated Companion Camp Attitude -> Tier: %d, Synarchy: %s"),
		static_cast<int32>(Tier), bIsSynarchy ? TEXT("TRUSTING/CLOSE") : TEXT("GUARDED/DISTANCE"));
}
