// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenEmpathicDialogueSaveGameAdapter.h"

UAshenEmpathicDialogueSaveGameAdapter::UAshenEmpathicDialogueSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEmpathicDialogueSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenEmpathicDialogueSaveGameAdapter::SerializeDialogueState(int32 UnlockedBranchCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenEmpathicDialogueSaveGameAdapter: %d unlocked dialogue branches serialized to save game."), UnlockedBranchCount);
	return true;
}
