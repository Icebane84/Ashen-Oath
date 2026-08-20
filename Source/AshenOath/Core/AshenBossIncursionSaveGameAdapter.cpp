// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenBossIncursionSaveGameAdapter.h"

UAshenBossIncursionSaveGameAdapter::UAshenBossIncursionSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenBossIncursionSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenBossIncursionSaveGameAdapter::SaveBossClearRecord(FName BossId, float ClearTimeSeconds, int32 TotalStaggers)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenBossIncursionSaveGameAdapter: Saved Boss Clear Record -> %s (Time: %.1fs, Staggers: %d)"),
		*BossId.ToString(), ClearTimeSeconds, TotalStaggers);
	return true;
}
