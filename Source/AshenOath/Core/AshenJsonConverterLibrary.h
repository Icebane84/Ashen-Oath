// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AshenQuestTypes.h"
#include "AshenLootTypes.h"
#include "AshenJsonConverterLibrary.generated.h"

/**
 * UAshenJsonConverterLibrary
 * Static C++ utility library leveraging FJsonObjectConverter to strictly parse
 * JSON strings into strongly-typed C++ USTRUCTs with run-time validation checks.
 */
UCLASS()
class ASHENOATH_API UAshenJsonConverterLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Validates and parses raw JSON string into FAshenQuestRecord. Returns true on success. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|JSON")
	static bool ValidateAndParseQuest(const FString& JsonString, FAshenQuestRecord& OutQuestRecord);

	/** Validates and parses raw JSON string into FAshenLootTableRecord. Returns true on success. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|JSON")
	static bool ValidateAndParseLootTable(const FString& JsonString, FAshenLootTableRecord& OutLootTableRecord);
};
