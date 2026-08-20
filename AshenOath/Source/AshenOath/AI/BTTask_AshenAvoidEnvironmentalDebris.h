// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AshenAvoidEnvironmentalDebris.generated.h"

/**
 * UBTTask_AshenAvoidEnvironmentalDebris
 * 
 * Behavior Tree Task ordering companion agents to clear the zone when stone
 * structures or pillars fracture into falling Chaos debris.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenAvoidEnvironmentalDebris : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenAvoidEnvironmentalDebris();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Chaos")
	float EvadeRadiusUU = 400.0f;
};
