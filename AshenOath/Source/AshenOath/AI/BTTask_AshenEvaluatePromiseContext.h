// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AshenEvaluatePromiseContext.generated.h"

/**
 * UBTTask_AshenEvaluatePromiseContext
 * 
 * Behavior Tree Task checking whether an active promise should be reactivated
 * in the current combat encounter.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenEvaluatePromiseContext : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenEvaluatePromiseContext();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Promise")
	FName HasActivePromiseBlackboardKey = FName(TEXT("bHasActivePromise"));
};
