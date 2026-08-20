// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenNovaDialogueAdapter.h"

UAshenNovaDialogueAdapter::UAshenNovaDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNovaDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenNovaDialogueAdapter::TriggerNovaSynchronizedBark(bool bIsFinisherApex)
{
	if (bIsFinisherApex)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenNovaDialogueAdapter: Kaelen & Serafina: \"TOGETHER... INTO THE SUNDERED DAWN!\""));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenNovaDialogueAdapter: Serafina: \"Kaelen, anchor your spirit to mine!\""));
	}
}
