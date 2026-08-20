// Copyright Phoenix Protocol. All rights reserved.

#include "AshenJsonConverterLibrary.h"
#include "JsonObjectConverter.h"

// Architectural limits to protect against out-of-bounds/stack overflow injections
const int32 MAX_JSON_PAYLOAD_SIZE = 65536; // 64 KB
const int32 MAX_JSON_STRUCTURAL_DEPTH = 32; // Limit nesting levels

static bool ValidateJsonBounds(const FString& JsonString)
{
	int32 Length = JsonString.Len();
	if (Length <= 0 || Length > MAX_JSON_PAYLOAD_SIZE)
	{
		return false;
	}

	// Basic structural depth validation (brace matching and nesting checks)
	int32 Depth = 0;
	for (int32 Index = 0; Index < Length; ++Index)
	{
		TCHAR Char = JsonString[Index];
		if (Char == TEXT('{') || Char == TEXT('['))
		{
			Depth++;
			if (Depth > MAX_JSON_STRUCTURAL_DEPTH)
			{
				return false;
			}
		}
		else if (Char == TEXT('}') || Char == TEXT(']'))
		{
			Depth = FMath::Max(0, Depth - 1);
		}
	}

	return Depth == 0; // Ensure structure is balanced
}

bool UAshenJsonConverterLibrary::ValidateAndParseQuest(const FString& JsonString, FAshenQuestRecord& OutQuestRecord)
{
	if (!ValidateJsonBounds(JsonString))
	{
		return false;
	}

	// STRICT VALIDATOR: Convert string to UStruct. Failing indicates incorrect schema configuration.
	return FJsonObjectConverter::JsonObjectStringToUStruct(JsonString, &OutQuestRecord, 0, 0);
}

bool UAshenJsonConverterLibrary::ValidateAndParseLootTable(const FString& JsonString, FAshenLootTableRecord& OutLootTableRecord)
{
	if (!ValidateJsonBounds(JsonString))
	{
		return false;
	}

	// STRICT VALIDATOR: Convert string to UStruct. Failing indicates incorrect schema configuration.
	return FJsonObjectConverter::JsonObjectStringToUStruct(JsonString, &OutLootTableRecord, 0, 0);
}
