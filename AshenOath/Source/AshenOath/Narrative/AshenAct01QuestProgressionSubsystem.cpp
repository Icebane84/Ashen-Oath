// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 766: Ashen Act 01 Quest Progression Subsystem

#include "AshenAct01QuestProgressionSubsystem.h"

void UAshenAct01QuestProgressionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentQuestStage = FName(TEXT("Stage.ReachBlackwoodBridge"));
	UE_LOG(LogTemp, Log, TEXT("UAshenAct01QuestProgressionSubsystem: Initialized — Act 01 Quest Progression Subsystem ONLINE."));
}

void UAshenAct01QuestProgressionSubsystem::AdvanceAct01QuestStage(FName StageTag)
{
	CurrentQuestStage = StageTag;
	const bool bComplete = CurrentQuestStage.IsEqual(FName(TEXT("Stage.Act01Complete")));

	OnQuestStageAdvanced.Broadcast(CurrentQuestStage, bComplete);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAct01QuestProgressionSubsystem: QUEST STAGE ADVANCED -> Stage: '%s' | Act 01 Complete: %s."),
		*CurrentQuestStage.ToString(), bComplete ? TEXT("TRUE") : TEXT("FALSE"));
}
