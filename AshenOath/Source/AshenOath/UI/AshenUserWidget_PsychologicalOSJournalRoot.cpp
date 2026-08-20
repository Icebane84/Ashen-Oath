// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_PsychologicalOSJournalRoot.h"

void UAshenUserWidget_PsychologicalOSJournalRoot::DisplayQualitativeSummary(const FAshenPsychologicalOSQualitativeSummary& Summary)
{
	CurrentMindStateText = Summary.MindStateDescription;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PsychologicalOSJournalRoot: Displaying MindState '%s'"), *CurrentMindStateText.ToString());
}
