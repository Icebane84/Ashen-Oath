// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "BTTask_AshenEvaluatePlayerIntent.generated.h"

/**
 * UBTTask_AshenEvaluatePlayerIntent
 * 
 * Behavior Tree Task querying the intent subsystem to write the selected
 * tactical response enum into the companion's Blackboard.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenEvaluatePlayerIntent : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenEvaluatePlayerIntent();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Intent")
	FName CompanionId = FName(TEXT("Garrett"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Intent")
	FName ResponseBlackboardKey = FName(TEXT("TacticalResponse"));
};
