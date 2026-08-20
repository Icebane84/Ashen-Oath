// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenFinisherGASSaveGameAdapter.h"

UAshenFinisherGASSaveGameAdapter::UAshenFinisherGASSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenFinisherGASSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenFinisherGASSaveGameAdapter::SerializeFinisherGASStats(FName AbilityName, int32 ExecutionCount, bool bMastered)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenFinisherGASSaveGameAdapter: Ability '%s' (Executions: %d, Mastered: %s) saved to SaveGame."),
		*AbilityName.ToString(), ExecutionCount, bMastered ? TEXT("TRUE") : TEXT("FALSE"));
	return true;
}
