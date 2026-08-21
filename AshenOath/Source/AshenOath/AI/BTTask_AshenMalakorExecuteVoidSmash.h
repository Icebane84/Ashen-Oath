// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "BTTask_AshenMalakorExecuteVoidSmash.generated.h"

/**
 * UBTTask_AshenMalakorExecuteVoidSmash
 * 
 * Directs Brother Malakor's AI to execute a downward void smash at the ritual altar.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenMalakorExecuteVoidSmash : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenMalakorExecuteVoidSmash();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Scenario1")
	float WindupDurationSeconds = 1.20f;
};
