// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenTrialOfWillDialogueAdapter.h"

UAshenTrialOfWillDialogueAdapter::UAshenTrialOfWillDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenTrialOfWillDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenTrialOfWillDialogueAdapter::TriggerStaggerDialogueBark(ETrialOfWillChoice Choice)
{
	switch (Choice)
	{
	case ETrialOfWillChoice::Defiance:
		UE_LOG(LogTemp, Warning, TEXT("UAshenTrialOfWillDialogueAdapter: Garrett: \"Hold the line, Kaelen! I'm sweeping the flanks!\""));
		break;
	case ETrialOfWillChoice::Wrath:
		UE_LOG(LogTemp, Error, TEXT("UAshenTrialOfWillDialogueAdapter: Serafina: \"Kaelen, no! You're letting the void consume you!\""));
		break;
	case ETrialOfWillChoice::Trust:
		UE_LOG(LogTemp, Warning, TEXT("UAshenTrialOfWillDialogueAdapter: Serafina: \"I have you, Kaelen! Stand with me!\""));
		break;
	default:
		break;
	}
}
