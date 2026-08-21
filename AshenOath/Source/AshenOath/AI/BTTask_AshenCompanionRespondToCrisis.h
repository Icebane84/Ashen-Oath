// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Combat/AshenBossArenaTypes.h"
#include "BTTask_AshenCompanionRespondToCrisis.generated.h"

/**
 * UBTTask_AshenCompanionRespondToCrisis
 * 
 * Behavior Tree Task ordering unpinned companion to provide covering fire
 * or prepare defensive barrier during a pinning crisis.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenCompanionRespondToCrisis : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenCompanionRespondToCrisis();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Crisis")
	bool bProvideCoveringFire = true;
};
