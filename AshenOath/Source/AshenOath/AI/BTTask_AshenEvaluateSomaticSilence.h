// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AshenEvaluateSomaticSilence.generated.h"

/**
 * UBTTask_AshenEvaluateSomaticSilence
 * 
 * Behavior Tree Task auditing silence classification and setting recommended
 * companion spacing on the Blackboard.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenEvaluateSomaticSilence : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenEvaluateSomaticSilence();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Silence")
	FName SilenceStateBlackboardKey = FName(TEXT("SilenceState"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Silence")
	FName TargetSpacingBlackboardKey = FName(TEXT("TargetSpacingUU"));
};
