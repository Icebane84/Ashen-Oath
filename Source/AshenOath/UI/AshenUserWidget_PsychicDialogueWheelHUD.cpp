// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_PsychicDialogueWheelHUD.h"

void UAshenUserWidget_PsychicDialogueWheelHUD::UpdateDialogueWheel(EPsychologicalTone InTone, int32 InChoices)
{
	DisplayedTone = InTone;
	AvailableChoiceCount = InChoices;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PsychicDialogueWheelHUD: Dialogue Wheel -> Tone: %d, Choices: %d"),
		static_cast<int32>(DisplayedTone), AvailableChoiceCount);
}
