// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "BTTask_AshenRelationalIntercept.generated.h"

/**
 * UBTTask_AshenRelationalIntercept
 * 
 * Behavior Tree Task executing a high-priority relational intercept:
 * - Overrides standard combat pathfinding when Kaelen is staggered
 * - Forces sprint velocity at 1.45x
 * - Positions companion directly between Kaelen and the attacking threat
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenRelationalIntercept : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenRelationalIntercept();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Intercept")
	float InterceptArrivalDistance = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Intercept")
	float MaxInterceptSprintSpeedMultiplier = 1.45f;
};
