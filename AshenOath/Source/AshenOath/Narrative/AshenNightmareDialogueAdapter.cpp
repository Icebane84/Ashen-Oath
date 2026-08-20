// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenNightmareDialogueAdapter.h"

UAshenNightmareDialogueAdapter::UAshenNightmareDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNightmareDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenNightmareDialogueAdapter::TriggerIncursionPanicBark(FName SpeakerID, ETransferenceStrainStage StrainStage)
{
	FString Bark = TEXT("The walls... they're bleeding into the void!");
	if (StrainStage == ETransferenceStrainStage::Catastrophic)
	{
		Bark = TEXT("I can't tell what is memory and what is blade anymore!");
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenNightmareDialogueAdapter: %s: \"%s\" (Strain Stage: %d)"),
		*SpeakerID.ToString(), *Bark, static_cast<int32>(StrainStage));
}
