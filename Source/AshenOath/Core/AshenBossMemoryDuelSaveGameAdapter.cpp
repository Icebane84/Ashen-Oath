// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenBossMemoryDuelSaveGameAdapter.h"

UAshenBossMemoryDuelSaveGameAdapter::UAshenBossMemoryDuelSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenBossMemoryDuelSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenBossMemoryDuelSaveGameAdapter::SerializeBossDefeatToSave(FName BossID, bool bDefeated, int32 MemoryFragmentsGained)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenBossMemoryDuelSaveGameAdapter: Boss %s defeat status (%s) and %d memory fragments serialized to save file."),
		*BossID.ToString(), bDefeated ? TEXT("DEFEATED") : TEXT("ACTIVE"), MemoryFragmentsGained);
	return true;
}
