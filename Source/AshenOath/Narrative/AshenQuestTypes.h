// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AshenQuestTypes.generated.h"

USTRUCT(BlueprintType)
struct FAshenObjectiveRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FName ObjectiveID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest", meta = (ClampMin = 1))
	int32 TargetCount;

	FAshenObjectiveRecord()
		: ObjectiveID(NAME_None)
		, Description(TEXT(""))
		, TargetCount(1)
	{}
};

USTRUCT(BlueprintType)
struct FAshenQuestRecord : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FName QuestID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FString QuestName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	TArray<FAshenObjectiveRecord> Objectives;

	FAshenQuestRecord()
		: QuestID(NAME_None)
		, QuestName(TEXT(""))
		, Description(TEXT(""))
	{}
};

USTRUCT(BlueprintType)
struct FAshenObjectiveRuntime
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FName ObjectiveID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	int32 CurrentCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	int32 TargetCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	bool bIsCompleted;

	FAshenObjectiveRuntime()
		: ObjectiveID(NAME_None)
		, Description(TEXT(""))
		, CurrentCount(0)
		, TargetCount(1)
		, bIsCompleted(false)
	{}

	FAshenObjectiveRuntime(const FAshenObjectiveRecord& Record)
		: ObjectiveID(Record.ObjectiveID)
		, Description(Record.Description)
		, CurrentCount(0)
		, TargetCount(Record.TargetCount)
		, bIsCompleted(false)
	{}
};

USTRUCT(BlueprintType)
struct FAshenQuestRuntime
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FName QuestID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FString QuestName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	TArray<FAshenObjectiveRuntime> Objectives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	bool bIsCompleted;

	FAshenQuestRuntime()
		: QuestID(NAME_None)
		, QuestName(TEXT(""))
		, Description(TEXT(""))
		, bIsCompleted(false)
	{}

	FAshenQuestRuntime(const FAshenQuestRecord& Record)
		: QuestID(Record.QuestID)
		, QuestName(Record.QuestName)
		, Description(Record.Description)
		, bIsCompleted(false)
	{
		for (const FAshenObjectiveRecord& ObjRecord : Record.Objectives)
		{
			Objectives.Add(FAshenObjectiveRuntime(ObjRecord));
		}
	}
};
