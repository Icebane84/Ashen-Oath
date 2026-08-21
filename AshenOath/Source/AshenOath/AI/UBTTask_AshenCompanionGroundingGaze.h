// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "UBTTask_AshenCompanionGroundingGaze.generated.h"

/**
 * UBTTask_AshenCompanionGroundingGaze
 * 
 * Directs companion AI to orient towards perceived threats, providing physical grounding for Kaelen.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenCompanionGroundingGaze : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenCompanionGroundingGaze();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Scenario4")
	FName TargetThreatKey = FName(TEXT("PerceivedThreat"));
};
