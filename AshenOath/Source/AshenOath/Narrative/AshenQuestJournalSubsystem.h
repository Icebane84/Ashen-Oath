// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenQuestJournalSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenQuestState : uint8
{
	NotStarted  UMETA(DisplayName = "NotStarted"),
	Active      UMETA(DisplayName = "Active"),
	Completed   UMETA(DisplayName = "Completed"),
	Failed      UMETA(DisplayName = "Failed")
};

USTRUCT(BlueprintType)
struct FAshenQuestObjectiveData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Quest")
	FName ObjectiveID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Quest")
	FString ObjectiveDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Quest")
	bool bIsCompleted = false;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestStateChangedSignature, FName, QuestID, EAshenQuestState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestObjectiveUpdatedSignature, FName, QuestID, FName, ObjectiveID);

/**
 * UAshenQuestJournalSubsystem
 *
 * World Subsystem for managing quest progression, active objectives,
 * and completion state.
 */
UCLASS()
class ASHENOATH_API UAshenQuestJournalSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Quest")
	void RegisterQuest(FName QuestID, const FString& QuestTitle);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Quest")
	bool StartQuest(FName QuestID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Quest")
	bool CompleteQuest(FName QuestID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Quest")
	bool FailQuest(FName QuestID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Quest")
	void AddObjective(FName QuestID, FName ObjectiveID, const FString& Description);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Quest")
	bool CompleteObjective(FName QuestID, FName ObjectiveID);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Quest")
	EAshenQuestState GetQuestState(FName QuestID) const;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Quest|Events")
	FOnQuestStateChangedSignature OnQuestStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Quest|Events")
	FOnQuestObjectiveUpdatedSignature OnObjectiveUpdated;

private:
	struct FQuestRecord
	{
		FString QuestTitle;
		EAshenQuestState State = EAshenQuestState::NotStarted;
		TArray<FAshenQuestObjectiveData> Objectives;
	};

	TMap<FName, FQuestRecord> Quests;
};
