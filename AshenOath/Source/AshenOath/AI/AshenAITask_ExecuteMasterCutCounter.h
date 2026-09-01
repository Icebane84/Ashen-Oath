// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenLiechtenauerMatrixDataAsset.h"
#include "AshenAITask_ExecuteMasterCutCounter.generated.h"

class UAbilitySystemComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMasterCutCounterExecuted, EAshenMasterCutType, ExecutedCut);

/**
 * UAshenAITask_ExecuteMasterCutCounter
 *
 * StateTree task component executing the evaluated Master Cut ability on the AI's ASC.
 * (PATCH v158.19.0 / PRS-001-SPEC-AI-109)
 */
UCLASS(ClassGroup = (AshenAI), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAITask_ExecuteMasterCutCounter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAITask_ExecuteMasterCutCounter();

	/** Executes the specified counter rule on the AI pawn */
	UFUNCTION(BlueprintCallable, Category = "Ashen|AI|StateTree")
	bool ExecuteCounterStrike(const FLiechtenauerCounterRule& CounterRule);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|AI|StateTree")
	FOnMasterCutCounterExecuted OnMasterCutCounterExecuted;
};
