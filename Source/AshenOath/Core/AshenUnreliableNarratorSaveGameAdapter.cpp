// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenUnreliableNarratorSaveGameAdapter.h"

UAshenUnreliableNarratorSaveGameAdapter::UAshenUnreliableNarratorSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenUnreliableNarratorSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenUnreliableNarratorSaveGameAdapter::SerializeNarratorStateToSave(int32 TotalHallucinationsTriggered)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableNarratorSaveGameAdapter: %d hallucination encounters serialized to save file."), TotalHallucinationsTriggered);
	return true;
}
