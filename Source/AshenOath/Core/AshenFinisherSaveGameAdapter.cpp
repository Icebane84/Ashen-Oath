// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenFinisherSaveGameAdapter.h"

UAshenFinisherSaveGameAdapter::UAshenFinisherSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenFinisherSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenFinisherSaveGameAdapter::SerializeFinisherStatsToSave(EAshenPartyFinisherType FinisherType, int32 LifetimeExecutions)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenFinisherSaveGameAdapter: Finisher Type %d (%d lifetime executions) serialized to save game."),
		(int32)FinisherType, LifetimeExecutions);
	return true;
}
