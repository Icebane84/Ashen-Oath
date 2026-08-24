// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Scenarios/AshenScenario10Types.h"
#include "UBTService_AshenApotheosisSyncTactics.generated.h"

/**
 * UBTService_AshenApotheosisSyncTactics
 * 
 * AI Behavior Tree service synchronizing companion positioning into dynamic 3-way flanking during apotheosis resonance.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenApotheosisSyncTactics : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenApotheosisSyncTactics();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Scenario10")
	float FlankingSeparationAngleDeg = 120.0f;
};
