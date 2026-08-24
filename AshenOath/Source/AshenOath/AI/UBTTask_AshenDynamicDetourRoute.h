// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "UBTTask_AshenDynamicDetourRoute.generated.h"

/**
 * UBTTask_AshenDynamicDetourRoute
 * 
 * Behavior Tree task that detects dynamic navmesh cuts caused by Chaos debris and recalculates clean detour routes.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenDynamicDetourRoute : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenDynamicDetourRoute();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Chaos")
	float DetourSearchRadiusUU = 1200.0f;
};
