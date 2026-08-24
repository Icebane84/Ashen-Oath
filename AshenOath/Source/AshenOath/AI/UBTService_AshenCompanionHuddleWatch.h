// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Scenarios/AshenScenario6Types.h"
#include "UBTService_AshenCompanionHuddleWatch.generated.h"

/**
 * UBTService_AshenCompanionHuddleWatch
 * 
 * Behavior Tree service monitoring blizzard severity and instructing companions to close formation into a warming huddle.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenCompanionHuddleWatch : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenCompanionHuddleWatch();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Scenario6")
	float MaxHuddleDistanceUU = 350.0f;
};
