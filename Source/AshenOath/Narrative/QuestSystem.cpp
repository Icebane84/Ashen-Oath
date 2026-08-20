// Copyright Phoenix Protocol. All rights reserved.

#include "QuestSystem.h"
#include "Engine/DataTable.h"

UQuestSystem::UQuestSystem()
{
}

bool UQuestSystem::StartQuestFromTable(UDataTable* QuestTable, FName QuestRowName)
{
	if (!QuestTable) return false;

	FAshenQuestRecord* Record = QuestTable->FindRow<FAshenQuestRecord>(QuestRowName, TEXT("StartQuestLookup"));
	if (!Record) return false;

	if (ActiveQuests.Contains(Record->QuestID))
	{
		return false; // Already active/completed
	}

	FAshenQuestRuntime RuntimeQuest(*Record);
	ActiveQuests.Add(Record->QuestID, RuntimeQuest);

	OnQuestStarted.Broadcast(Record->QuestID);
	return true;
}

bool UQuestSystem::ProgressQuestObjective(FName QuestID, FName ObjectiveID, int32 ProgressAmount)
{
	if (ProgressAmount <= 0) return false;

	FAshenQuestRuntime* Quest = ActiveQuests.Find(QuestID);
	if (!Quest || Quest->bIsCompleted) return false;

	bool bObjectiveFound = false;

	for (FAshenObjectiveRuntime& Obj : Quest->Objectives)
	{
		if (Obj.ObjectiveID == ObjectiveID)
		{
			bObjectiveFound = true;
			if (Obj.bIsCompleted) return false;

			Obj.CurrentCount = FMath::Clamp(Obj.CurrentCount + ProgressAmount, 0, Obj.TargetCount);
			if (Obj.CurrentCount >= Obj.TargetCount)
			{
				Obj.bIsCompleted = true;
			}

			OnObjectiveProgressed.Broadcast(QuestID, ObjectiveID, Obj.CurrentCount, Obj.TargetCount);
			break;
		}
	}

	if (!bObjectiveFound) return false;

	// Check if all objectives are complete to trigger quest completion
	bool bAllComplete = true;
	for (const FAshenObjectiveRuntime& Obj : Quest->Objectives)
	{
		if (!Obj.bIsCompleted)
		{
			bAllComplete = false;
			break;
		}
	}

	if (bAllComplete)
	{
		Quest->bIsCompleted = true;
		OnQuestCompleted.Broadcast(QuestID);
	}

	return true;
}

bool UQuestSystem::IsQuestCompleted(FName QuestID) const
{
	const FAshenQuestRuntime* Quest = ActiveQuests.Find(QuestID);
	return Quest ? Quest->bIsCompleted : false;
}

TArray<FAshenQuestRuntime> UQuestSystem::GetActiveQuests() const
{
	TArray<FAshenQuestRuntime> Result;
	ActiveQuests.GenerateValueArray(Result);
	return Result;
}

void UQuestSystem::LoadQuestState(const TArray<FAshenQuestRuntime>& InQuests)
{
	ActiveQuests.Empty();
	for (const FAshenQuestRuntime& Q : InQuests)
	{
		ActiveQuests.Add(Q.QuestID, Q);
	}
}
