// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenEpistemicSaveGameAdapter.h"

UAshenEpistemicSaveGameAdapter::UAshenEpistemicSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEpistemicSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenEpistemicSaveGameAdapter::SaveEpistemicHistory(int32 TotalEventsCount, int32 MilestoneEventsCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenEpistemicSaveGameAdapter: Saved Epistemic History (Total Events: %d, Milestones: %d) to SaveGame."),
		TotalEventsCount, MilestoneEventsCount);
	return true;
}
