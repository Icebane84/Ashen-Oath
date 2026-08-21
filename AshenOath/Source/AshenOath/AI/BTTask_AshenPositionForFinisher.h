// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AshenPositionForFinisher.generated.h"

/**
 * UBTTask_AshenPositionForFinisher
 * 
 * Behavior Tree Task ordering companion to position themselves at the 120-degree
 * radial arc around the boss/target for the synchronized finisher.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenPositionForFinisher : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenPositionForFinisher();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Trio")
	float FinisherArcOffsetAngle = 120.0f;
};
