// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_PsychologicalOSDashboard.h"

void UAshenUserWidget_PsychologicalOSDashboard::DisplayQualitativeMindState(FAshenQualitativeMindState MindState)
{
	ActiveQualitativeMindState = MindState;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PsychologicalOSDashboard: Displayed qualitative mind state on top layer of Psychological OS Dashboard."));
}
