// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AshenSerafinaTransferenceTriage.generated.h"

/**
 * UBTTask_AshenSerafinaTransferenceTriage
 * 
 * Behavior Tree Task auditing Serafina's burnout severity before committing
 * to an emergency heal cast.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenSerafinaTransferenceTriage : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenSerafinaTransferenceTriage();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Triage")
	float MaxSafeBurnoutThreshold = 80.0f;
};
