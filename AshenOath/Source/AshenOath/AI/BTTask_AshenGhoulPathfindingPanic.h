// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "BTTask_AshenGhoulPathfindingPanic.generated.h"

/**
 * UBTTask_AshenGhoulPathfindingPanic
 * 
 * Directs enemy AI in failed recovery state to route erratically and fall into ravine hazards.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenGhoulPathfindingPanic : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenGhoulPathfindingPanic();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Scenario2")
	float PanicFleeSpeed = 450.0f;
};
