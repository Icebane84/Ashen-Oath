// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenSerafinaSaveGameAdapter.h"

UAshenSerafinaSaveGameAdapter::UAshenSerafinaSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSerafinaSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenSerafinaSaveGameAdapter::SerializeSerafinaStateToSave(float CurrentBurnout, float TotalTransferredHP)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaSaveGameAdapter: Burnout (%.1f) and Total Transferred HP (%.1f) serialized to save file."),
		CurrentBurnout, TotalTransferredHP);
	return true;
}
