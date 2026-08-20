// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 187: Ashen Quest Journal Subsystem

#include "AshenQuestJournalSubsystem.h"

void UAshenQuestJournalSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Quests.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenQuestJournalSubsystem: Initialized — Quest Journal active."));
}

void UAshenQuestJournalSubsystem::RegisterQuest(FName QuestID, const FString& QuestTitle)
{
	if (QuestID.IsNone() || Quests.Contains(QuestID)) return;

	FQuestRecord Record;
	Record.QuestTitle = QuestTitle;
	Record.State = EAshenQuestState::NotStarted;
	Quests.Add(QuestID, Record);

	UE_LOG(LogTemp, Log, TEXT("UAshenQuestJournalSubsystem: Registered quest '%s' ('%s')."), *QuestID.ToString(), *QuestTitle);
}

bool UAshenQuestJournalSubsystem::StartQuest(FName QuestID)
{
	FQuestRecord* Record = Quests.Find(QuestID);
	if (!Record) return false;

	Record->State = EAshenQuestState::Active;
	OnQuestStateChanged.Broadcast(QuestID, EAshenQuestState::Active);

	UE_LOG(LogTemp, Warning, TEXT("UAshenQuestJournalSubsystem: QUEST STARTED — '%s' ('%s')."), *QuestID.ToString(), *Record->QuestTitle);
	return true;
}

bool UAshenQuestJournalSubsystem::CompleteQuest(FName QuestID)
{
	FQuestRecord* Record = Quests.Find(QuestID);
	if (!Record || Record->State != EAshenQuestState::Active) return false;

	Record->State = EAshenQuestState::Completed;
	OnQuestStateChanged.Broadcast(QuestID, EAshenQuestState::Completed);

	UE_LOG(LogTemp, Warning, TEXT("UAshenQuestJournalSubsystem: QUEST COMPLETED — '%s'!"), *QuestID.ToString());
	return true;
}

bool UAshenQuestJournalSubsystem::FailQuest(FName QuestID)
{
	FQuestRecord* Record = Quests.Find(QuestID);
	if (!Record || Record->State != EAshenQuestState::Active) return false;

	Record->State = EAshenQuestState::Failed;
	OnQuestStateChanged.Broadcast(QuestID, EAshenQuestState::Failed);

	UE_LOG(LogTemp, Warning, TEXT("UAshenQuestJournalSubsystem: QUEST FAILED — '%s'."), *QuestID.ToString());
	return true;
}

void UAshenQuestJournalSubsystem::AddObjective(FName QuestID, FName ObjectiveID, const FString& Description)
{
	FQuestRecord* Record = Quests.Find(QuestID);
	if (!Record) return;

	FAshenQuestObjectiveData Obj;
	Obj.ObjectiveID = ObjectiveID;
	Obj.ObjectiveDescription = Description;
	Obj.bIsCompleted = false;

	Record->Objectives.Add(Obj);
	UE_LOG(LogTemp, Log, TEXT("UAshenQuestJournalSubsystem: Added objective '%s' to quest '%s'."), *ObjectiveID.ToString(), *QuestID.ToString());
}

bool UAshenQuestJournalSubsystem::CompleteObjective(FName QuestID, FName ObjectiveID)
{
	FQuestRecord* Record = Quests.Find(QuestID);
	if (!Record) return false;

	for (FAshenQuestObjectiveData& Obj : Record->Objectives)
	{
		if (Obj.ObjectiveID == ObjectiveID)
		{
			if (Obj.bIsCompleted) return true;

			Obj.bIsCompleted = true;
			OnObjectiveUpdated.Broadcast(QuestID, ObjectiveID);

			UE_LOG(LogTemp, Warning, TEXT("UAshenQuestJournalSubsystem: OBJECTIVE COMPLETED — '%s' in quest '%s'."),
				*ObjectiveID.ToString(), *QuestID.ToString());
			return true;
		}
	}

	return false;
}

EAshenQuestState UAshenQuestJournalSubsystem::GetQuestState(FName QuestID) const
{
	const FQuestRecord* Record = Quests.Find(QuestID);
	return Record ? Record->State : EAshenQuestState::NotStarted;
}
