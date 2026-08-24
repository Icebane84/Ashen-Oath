// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Scenarios/AshenScenario7Types.h"
#include "UBTService_AshenMagmaHazardAvoidance.generated.h"

/**
 * UBTService_AshenMagmaHazardAvoidance
 * 
 * AI Behavior Tree service instructing companions to detect magma fissure telegraphs and route into Garrett's cryo mist.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenMagmaHazardAvoidance : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenMagmaHazardAvoidance();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Scenario7")
	float MagmaEvacuateRadiusUU = 450.0f;
};
