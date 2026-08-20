// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 190: Ashen Quest Tracker UMG Widget

#include "AshenUserWidget_QuestTracker.h"

void UAshenUserWidget_QuestTracker::DisplayActiveQuest(FName QuestID, const FText& QuestTitle, const FText& ActiveObjective)
{
	CurrentQuestID = QuestID;
	CurrentQuestTitle = QuestTitle;
	CurrentObjectiveText = ActiveObjective;

	OnQuestTrackerRefreshed.Broadcast(CurrentQuestID, CurrentObjectiveText);

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_QuestTracker: Displaying quest '%s' ('%s') — Obj: '%s'."),
		*QuestID.ToString(), *QuestTitle.ToString(), *ActiveObjective.ToString());
}

void UAshenUserWidget_QuestTracker::ClearQuestDisplay()
{
	CurrentQuestID = NAME_None;
	CurrentQuestTitle = FText::GetEmpty();
	CurrentObjectiveText = FText::GetEmpty();

	OnQuestTrackerRefreshed.Broadcast(NAME_None, FText::GetEmpty());

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_QuestTracker: Quest display cleared."));
}
