// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "UBTTask_AshenGarrettWaystationTactics.generated.h"

/**
 * UBTTask_AshenGarrettWaystationTactics
 * 
 * Directs Garrett's companion AI to execute dual-wield responses (Twin-Blade X-Lock, Dagger Peel, or Abort).
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenGarrettWaystationTactics : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenGarrettWaystationTactics();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Waystation")
	EGarrettDualWieldBenchmarkResponse DesiredTactic = EGarrettDualWieldBenchmarkResponse::TwinBladeXLockDeflect;
};
