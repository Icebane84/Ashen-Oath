// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Combat/AshenBossArenaTypes.h"
#include "BTTask_AshenBossSelectPhaseAction.generated.h"

/**
 * UBTTask_AshenBossSelectPhaseAction
 * 
 * Behavior Tree Task directing boss action selection based on active encounter phase.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenBossSelectPhaseAction : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenBossSelectPhaseAction();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Boss")
	EBossEncounterPhase TargetPhase = EBossEncounterPhase::Phase1_Guardian;
};
