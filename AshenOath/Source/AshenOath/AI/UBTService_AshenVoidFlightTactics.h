// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Scenarios/AshenScenario9Types.h"
#include "UBTService_AshenVoidFlightTactics.generated.h"

/**
 * UBTService_AshenVoidFlightTactics
 * 
 * AI Behavior Tree service guiding floating citadel automatons along low-gravity flight paths while evading violent gale shears.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenVoidFlightTactics : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenVoidFlightTactics();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Scenario9")
	float FlightHoverHeightUU = 300.0f;
};
