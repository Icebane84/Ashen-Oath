// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "AI/AshenLiechtenauerMatrixDataAsset.h"
#include "AshenAIStateTreeEvaluator_Liechtenauer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLiechtenauerCounterSelected, EAshenMasterCutType, CounterCut, float, PostureMultiplier);

/**
 * UAshenAIStateTreeEvaluator_Liechtenauer
 *
 * Evaluates target stance gameplay tags, distance, and combat context at 60Hz
 * to select the optimal Liechtenauer Master Cut counter.
 * (PATCH v158.19.0 / PRS-001-SPEC-AI-109)
 */
UCLASS(ClassGroup = (AshenAI), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAIStateTreeEvaluator_Liechtenauer : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAIStateTreeEvaluator_Liechtenauer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Matrix")
	TObjectPtr<UAshenLiechtenauerMatrixDataAsset> LiechtenauerMatrix;

	/** Evaluates target pawn stance and determines the recommended counter cut */
	UFUNCTION(BlueprintCallable, Category = "Ashen|AI|StateTree")
	bool EvaluateCounterDecision(AActor* TargetActor, FLiechtenauerCounterRule& OutSelectedRule);

	UFUNCTION(BlueprintPure, Category = "Ashen|AI|StateTree")
	const FLiechtenauerCounterRule& GetCurrentSelectedRule() const { return CurrentRule; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|AI|StateTree")
	FOnLiechtenauerCounterSelected OnLiechtenauerCounterSelected;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|AI|StateTree")
	FLiechtenauerCounterRule CurrentRule;
};
