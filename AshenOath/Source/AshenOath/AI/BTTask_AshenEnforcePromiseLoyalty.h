// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AshenEnforcePromiseLoyalty.generated.h"

/**
 * UBTTask_AshenEnforcePromiseLoyalty
 * 
 * Behavior Tree Task locking companion to Kaelen's side when a sacred promise is active.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenEnforcePromiseLoyalty : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenEnforcePromiseLoyalty();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Promise")
	float EnforcedSpacingUU = 200.0f;
};
