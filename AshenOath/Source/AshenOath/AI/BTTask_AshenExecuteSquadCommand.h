// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "BTTask_AshenExecuteSquadCommand.generated.h"

/**
 * UBTTask_AshenExecuteSquadCommand
 * 
 * Directs companion AI to orient toward marked tactical target location and execute ability.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenExecuteSquadCommand : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenExecuteSquadCommand();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Tactics")
	ETacticalCommandType CommandToExecute = ETacticalCommandType::GarrettWireSnare;
};
