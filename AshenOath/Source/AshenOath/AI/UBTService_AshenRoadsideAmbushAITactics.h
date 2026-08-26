// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "World/AshenTacticalMapTypes.h"
#include "UBTService_AshenRoadsideAmbushAITactics.generated.h"

/**
 * UBTService_AshenRoadsideAmbushAITactics
 * 
 * AI Behavior Tree service coordinating flanking encirclement and pincer strikes during travel ambush skirmishes.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenRoadsideAmbushAITactics : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenRoadsideAmbushAITactics();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Ambush")
	float PincerEncirclementAngle = 60.0f;
};
