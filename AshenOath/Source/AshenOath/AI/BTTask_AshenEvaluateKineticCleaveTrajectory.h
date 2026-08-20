// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AshenEvaluateKineticCleaveTrajectory.generated.h"

/**
 * UBTTask_AshenEvaluateKineticCleaveTrajectory
 * 
 * Behavior Tree Task finding optimal multi-target sweep arcs for heavy cleaving attacks.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenEvaluateKineticCleaveTrajectory : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenEvaluateKineticCleaveTrajectory();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Cleave")
	float CleaveSweepRadiusUU = 350.0f;
};
