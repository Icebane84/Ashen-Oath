// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "UBTService_AshenMasonryHazardAIAvoidance.generated.h"

/**
 * UBTService_AshenMasonryHazardAIAvoidance
 * 
 * AI Behavior Tree service instructing companions and enemies to immediately evade falling masonry impact telegraph zones.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenMasonryHazardAIAvoidance : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenMasonryHazardAIAvoidance();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Rubble")
	float EvacuationDistanceBufferUU = 150.0f;
};
