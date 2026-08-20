// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AshenEvaluateStaggerChoice.generated.h"

/**
 * UBTTask_AshenEvaluateStaggerChoice
 * 
 * Behavior Tree Task querying companion evaluation on staggered enemy target,
 * setting the suggested tactical action on the Blackboard.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenEvaluateStaggerChoice : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenEvaluateStaggerChoice();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Morality")
	FName CompanionId = FName(TEXT("Garrett"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Morality")
	FName StaggerChoiceBlackboardKey = FName(TEXT("SuggestedStaggerChoice"));
};
