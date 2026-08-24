// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "UBTTask_AshenTripartiteEQSRoute.generated.h"

/**
 * UBTTask_AshenTripartiteEQSRoute
 * 
 * Behavior Tree task instructing companion AI to query and route along optimal EQS flank and support coordinates.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenTripartiteEQSRoute : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenTripartiteEQSRoute();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Tripartite")
	ETripartiteBehaviorMode TargetMode = ETripartiteBehaviorMode::CombatEngagement;
};
