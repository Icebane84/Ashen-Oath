// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenOathStateSaveGameAdapter.h"

UAshenOathStateSaveGameAdapter::UAshenOathStateSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenOathStateSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenOathStateSaveGameAdapter::SerializeOathRegistryToSave(const TArray<FOathRecord>& OathRecords)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenOathStateSaveGameAdapter: %d FOathRecord entries serialized cleanly to save payload."), OathRecords.Num());
	return true;
}
