// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenEliteInquisitionDialogueAdapter.h"

UAshenEliteInquisitionDialogueAdapter::UAshenEliteInquisitionDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEliteInquisitionDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenEliteInquisitionDialogueAdapter::TriggerEliteEncounterCallout(FName CompanionID, FName EnemyType)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenEliteInquisitionDialogueAdapter: %s calls out ('Careful Kaelen, the %s can phase straight through the stones!')"),
		*CompanionID.ToString(), *EnemyType.ToString());
}
