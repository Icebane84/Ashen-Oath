// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "UAshenStateTreeTask_GarrettDeployTrap.generated.h"

/**
 * UUAshenStateTreeTask_GarrettDeployTrap
 * 
 * Directs Garrett's companion AI to survey enemy patrol lines and deploy a tactical trap.
 */
UCLASS()
class ASHENOATH_API UUAshenStateTreeTask_GarrettDeployTrap : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UUAshenStateTreeTask_GarrettDeployTrap();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Scenario2")
	EGarrettTrapType TrapToDeploy = EGarrettTrapType::TensionWireSnare;
};
