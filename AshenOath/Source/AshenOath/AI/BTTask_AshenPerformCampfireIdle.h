// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AshenPerformCampfireIdle.generated.h"

/**
 * UBTTask_AshenPerformCampfireIdle
 * 
 * Behavior Tree Task driving companion campfire idle actions (cleaning weapon,
 * reading journal, tending fire).
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenPerformCampfireIdle : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenPerformCampfireIdle();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Hearth")
	FName IdleActionName = TEXT("SharpenBlade");
};
