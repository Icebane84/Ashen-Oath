// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AshenLootTypes.generated.h"

USTRUCT(BlueprintType)
struct FAshenLootItemRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot")
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot", meta = (ClampMin = 0.0, ClampMax = 1.0))
	float DropChance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot", meta = (ClampMin = 0))
	int32 MinQuantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot", meta = (ClampMin = 0))
	int32 MaxQuantity;

	FAshenLootItemRecord()
		: ItemID(NAME_None)
		, DropChance(1.0f)
		, MinQuantity(1)
		, MaxQuantity(1)
	{}
};

USTRUCT(BlueprintType)
struct FAshenLootTableRecord : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot")
	FName TableID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot")
	TArray<FAshenLootItemRecord> LootItems;

	FAshenLootTableRecord()
		: TableID(NAME_None)
	{}
};
