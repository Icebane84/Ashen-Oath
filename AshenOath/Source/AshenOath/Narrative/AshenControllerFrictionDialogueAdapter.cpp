// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenControllerFrictionDialogueAdapter.h"

UAshenControllerFrictionDialogueAdapter::UAshenControllerFrictionDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenControllerFrictionDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenControllerFrictionDialogueAdapter::TriggerStruggleDialogueBark(EStrugglePhase Phase)
{
	switch (Phase)
	{
	case EStrugglePhase::Phase1_DiscordantHum:
		UE_LOG(LogTemp, Warning, TEXT("UAshenControllerFrictionDialogueAdapter: Serafina: \"Kaelen, breathe! Don't let the whispers cloud your sight!\""));
		break;
	case EStrugglePhase::Phase2_MartyrsPivot:
		UE_LOG(LogTemp, Warning, TEXT("UAshenControllerFrictionDialogueAdapter: Garrett: \"Kaelen, damn it, don't take that hit for me!\""));
		break;
	case EStrugglePhase::Phase3_ReclamationCrash:
		UE_LOG(LogTemp, Error, TEXT("UAshenControllerFrictionDialogueAdapter: Serafina: \"Hold him down! He's fracturing the bone!\""));
		break;
	default:
		break;
	}
}
