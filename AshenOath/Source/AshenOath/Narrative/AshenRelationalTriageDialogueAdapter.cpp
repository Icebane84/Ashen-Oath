// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenRelationalTriageDialogueAdapter.h"

UAshenRelationalTriageDialogueAdapter::UAshenRelationalTriageDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenRelationalTriageDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenRelationalTriageDialogueAdapter::TriggerTriageBark(EInterpretiveTherapyLens Lens)
{
	switch (Lens)
	{
	case EInterpretiveTherapyLens::Grace:
		UE_LOG(LogTemp, Warning, TEXT("UAshenRelationalTriageDialogueAdapter: Serafina: \"We carried the heat together. The Flame did not burn us.\""));
		break;
	case EInterpretiveTherapyLens::Accountability:
		UE_LOG(LogTemp, Warning, TEXT("UAshenRelationalTriageDialogueAdapter: Kaelen: \"I will bear this silence alone. Stay behind me.\""));
		break;
	case EInterpretiveTherapyLens::Utility:
		UE_LOG(LogTemp, Warning, TEXT("UAshenRelationalTriageDialogueAdapter: Garrett: \"If it bleeds and it keeps us alive, we pay the bill later.\""));
		break;
	}
}
