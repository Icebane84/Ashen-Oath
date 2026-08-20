// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenGarrettTacticalDialogueAdapter.h"

UAshenGarrettTacticalDialogueAdapter::UAshenGarrettTacticalDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenGarrettTacticalDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenGarrettTacticalDialogueAdapter::TriggerTacticalBanter(FString ActionType)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettTacticalDialogueAdapter: Garrett tactical banter triggered for '%s' ('Watch your flank, Kaelen!')"), *ActionType);
}
