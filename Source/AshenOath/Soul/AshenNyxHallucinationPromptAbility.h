// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenNyxHallucinationPromptAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHallucinationPromptExecutedSignature, FText, HallucinationPromptText, float, EntropyImpact);

/**
 * UAshenNyxHallucinationPromptAbility
 *
 * Ability triggering psychological hallucination choices during contested memory weaving (UMB-INT-001 Memory Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenNyxHallucinationPromptAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|NyxAbilities")
	void TriggerHallucinationPrompt(FText PromptText, float EntropyImpact = 15.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|NyxAbilities|Events")
	FOnHallucinationPromptExecutedSignature OnPromptExecuted;
};
