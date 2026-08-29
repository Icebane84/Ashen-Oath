// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "UBTService_AshenWeatherPerceptionAITactics.generated.h"

/**
 * UBTService_AshenWeatherPerceptionAITactics
 * 
 * Dynamic AI tactical perception updater: clamps enemy vision distance during blizzards/ash storms and coordinates dual-prong pincer maneuvers around cleaved rubble obstacles.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenWeatherPerceptionAITactics : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenWeatherPerceptionAITactics();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Convergence")
	EAIPincerManeuverState CurrentPincerState = EAIPincerManeuverState::DirectApproach;
};
