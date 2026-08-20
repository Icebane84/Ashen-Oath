// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenLivingCodexSaveGameAdapter.h"

UAshenLivingCodexSaveGameAdapter::UAshenLivingCodexSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLivingCodexSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenLivingCodexSaveGameAdapter::SaveCodexArchive(int32 TotalUnlocked, int32 TotalRead)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingCodexSaveGameAdapter: Saved Codex Archive (%d unlocked, %d read) to SaveGame."),
		TotalUnlocked, TotalRead);
	return true;
}
