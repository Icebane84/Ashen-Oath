// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AshenExecuteWordlessSupport.generated.h"

/**
 * UBTTask_AshenExecuteWordlessSupport
 * 
 * Behavior Tree Task directing companion to clear civilian rubble/obstacles
 * ahead of Kaelen's path.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenExecuteWordlessSupport : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenExecuteWordlessSupport();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Support")
	FName ObstacleLocationBlackboardKey = FName(TEXT("TargetObstacleLocation"));
};
