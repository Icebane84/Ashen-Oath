// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenQuestTypes.h"
#include "QuestSystem.generated.h"

class UDataTable;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestStartedSignature, FName, QuestID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnQuestObjectiveProgressedSignature, FName, QuestID, FName, ObjectiveID, int32, CurrentProgress, int32, TargetProgress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestCompletedSignature, FName, QuestID);

/**
 * UQuestSystem
 * Modular Quest tracking and management system.
 * Translates DataTable quest template records into runtime active states.
 */
UCLASS(BlueprintType, Blueprintable)
class ASHENOATH_API UQuestSystem : public UObject
{
	GENERATED_BODY()

public:
	UQuestSystem();

	/** Start a quest from a configuration DataTable row */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Quests")
	bool StartQuestFromTable(UDataTable* QuestTable, FName QuestRowName);

	/** Add progress to a specific objective within an active quest */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Quests")
	bool ProgressQuestObjective(FName QuestID, FName ObjectiveID, int32 ProgressAmount);

	/** Check if a quest is complete */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Quests")
	bool IsQuestCompleted(FName QuestID) const;

	/** Get list of all currently tracked runtime quests */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Quests")
	TArray<FAshenQuestRuntime> GetActiveQuests() const;

	/** Load quest states dynamically from save game */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Quests")
	void LoadQuestState(const TArray<FAshenQuestRuntime>& InQuests);

public:
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Quests|Events")
	FOnQuestStartedSignature OnQuestStarted;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Quests|Events")
	FOnQuestObjectiveProgressedSignature OnObjectiveProgressed;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Quests|Events")
	FOnQuestCompletedSignature OnQuestCompleted;

private:
	UPROPERTY(VisibleAnywhere, Category = "Quests")
	TMap<FName, FAshenQuestRuntime> ActiveQuests;
};
