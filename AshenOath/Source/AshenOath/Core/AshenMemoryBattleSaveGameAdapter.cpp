// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenMemoryBattleSaveGameAdapter.h"

UAshenMemoryBattleSaveGameAdapter::UAshenMemoryBattleSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMemoryBattleSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenMemoryBattleSaveGameAdapter::SerializeResolvedMemoryToSave(FName EchoID, bool bVictory, float HarmonyReward)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryBattleSaveGameAdapter: Serialized Echo '%s' (Victory: %s, Harmony: +%.1f) to SaveGame."),
		*EchoID.ToString(), bVictory ? TEXT("YES") : TEXT("NO"), HarmonyReward);
	return true;
}
