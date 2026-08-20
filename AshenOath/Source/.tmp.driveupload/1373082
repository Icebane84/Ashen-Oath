// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenDeterministicVoiceFallbackProvider.generated.h"

/**
 * UAshenDeterministicVoiceFallbackProvider
 * 
 * Provides deterministic, pre-authored inner monologue payloads keyed to
 * Kaelen's active DominantLens and IntegrationDebt stage.
 */
UCLASS()
class ASHENOATH_API UAshenDeterministicVoiceFallbackProvider : public UObject
{
	GENERATED_BODY()

public:
	UAshenDeterministicVoiceFallbackProvider();

	/** Gets deterministic fallback payload */
	UFUNCTION(BlueprintPure, Category = "Ashen|Soul|Fallback")
	FAshenInnerVoicePayload GetFallbackPayload(
		EOntologicalLens DominantLens,
		float IntegrationDebt,
		const FString& CitedMemoryId) const;
};
