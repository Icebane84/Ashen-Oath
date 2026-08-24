// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Scenarios/AshenScenario8Types.h"
#include "UBTService_AshenAbyssLurkerStalk.generated.h"

/**
 * UBTService_AshenAbyssLurkerStalk
 * 
 * AI Behavior Tree service instructing subterranean lurkers to stalk outside light perimeters and flee radiant flares.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenAbyssLurkerStalk : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenAbyssLurkerStalk();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Scenario8")
	float StalkingDistanceThresholdUU = 600.0f;
};
