// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AshenExecuteComboFollowup.generated.h"

/**
 * UBTTask_AshenExecuteComboFollowup
 * 
 * Behavior Tree Task directing Garrett or Serafina to execute their respective
 * Step 2 (Wire Snare) or Step 3 (Holy Burst) combo action.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenExecuteComboFollowup : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenExecuteComboFollowup();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Trio")
	float MaxComboDistanceUU = 800.0f;
};
