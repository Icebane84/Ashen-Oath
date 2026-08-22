// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "UBTTask_AshenGarrettBoundaryDefense.generated.h"

/**
 * UBTTask_AshenGarrettBoundaryDefense
 * 
 * Directs Garrett's companion AI to form a defensive perimeter around Kaelen during post-Unchained exhaustion.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenGarrettBoundaryDefense : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenGarrettBoundaryDefense();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Scenario5")
	float GuardRadiusCentimeters = 400.0f;
};
