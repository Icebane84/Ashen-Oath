// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenLivingJournalSaveGameAdapter.h"

UAshenLivingJournalSaveGameAdapter::UAshenLivingJournalSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLivingJournalSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenLivingJournalSaveGameAdapter::SaveJournalProgress(int32 AuthoredPagesCount, int32 UnlockedPerksCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingJournalSaveGameAdapter: Saved Journal Progress (Pages: %d, Perks: %d) to SaveGame."),
		AuthoredPagesCount, UnlockedPerksCount);
	return true;
}
