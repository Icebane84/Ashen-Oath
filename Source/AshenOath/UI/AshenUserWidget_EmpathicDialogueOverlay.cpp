// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_EmpathicDialogueOverlay.h"

void UAshenUserWidget_EmpathicDialogueOverlay::DisplayEmpathicDialogue(FText Speaker, FText Text)
{
	ActiveSpeakerName = Speaker;
	ActiveDialogueText = Text;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_EmpathicDialogueOverlay: [%s]: %s"), *ActiveSpeakerName.ToString(), *ActiveDialogueText.ToString());
}
