// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenUserWidget_DialogueOverlay.h"

UAshenUserWidget_DialogueOverlay::UAshenUserWidget_DialogueOverlay(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UAshenUserWidget_DialogueOverlay::DisplayDialogueLine(const FText& SpeakerName, const FText& LineText, const TArray<FDialogueChoiceRecord>& Choices)
{
	ActiveSpeakerName = SpeakerName;
	ActiveLineText = LineText;
	ActiveChoices = Choices;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DialogueOverlay: Displaying dialogue for '%s' with %d choices."),
		*SpeakerName.ToString(), Choices.Num());
}

void UAshenUserWidget_DialogueOverlay::SelectChoice(int32 ChoiceIndex)
{
	if (!ActiveChoices.IsValidIndex(ChoiceIndex))
	{
		return;
	}

	OnChoiceClicked.Broadcast(ChoiceIndex);
	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_DialogueOverlay: Choice index %d selected!"), ChoiceIndex);
}
