// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenDeterministicMarginaliaFallbackProvider.generated.h"

/**
 * UAshenDeterministicMarginaliaFallbackProvider
 * 
 * Provides pre-authored character-authentic annotations for Garrett and Serafina
 * mapped to trust tiers and memory context.
 */
UCLASS()
class ASHENOATH_API UAshenDeterministicMarginaliaFallbackProvider : public UObject
{
	GENERATED_BODY()

public:
	UAshenDeterministicMarginaliaFallbackProvider();

	/** Generates deterministic multi-author annotations */
	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|Fallback")
	TArray<FMarginaliaEntry> GenerateDeterministicEntries(
		const FCanonicalSoulStateVector& SoulState,
		const FString& TargetMemoryId) const;
};
