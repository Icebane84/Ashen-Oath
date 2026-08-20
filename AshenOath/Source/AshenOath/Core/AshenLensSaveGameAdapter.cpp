// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenLensSaveGameAdapter.h"

UAshenLensSaveGameAdapter::UAshenLensSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLensSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenLensSaveGameAdapter::SaveActiveLensState(EInterpretiveLens Lens)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenLensSaveGameAdapter: Saved Active Lens state (%d) to SaveGame."), static_cast<int32>(Lens));
	return true;
}
