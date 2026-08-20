// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AshenShoulderToShoulderSprint.generated.h"

/**
 * UBTTask_AshenShoulderToShoulderSprint
 * 
 * Behavior Tree Task directing companion to match Kaelen's sprint trajectory
 * within tight 200uu offset.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenShoulderToShoulderSprint : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenShoulderToShoulderSprint();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Formation")
	float TargetOffsetDistance = 200.0f;
};
