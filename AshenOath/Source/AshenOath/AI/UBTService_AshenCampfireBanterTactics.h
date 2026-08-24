// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Narrative/AshenJournalTypes.h"
#include "UBTService_AshenCampfireBanterTactics.generated.h"

/**
 * UBTService_AshenCampfireBanterTactics
 * 
 * AI Behavior Tree service driving companion seated posture, campfire gaze alignment, and turn-taking dialogue.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenCampfireBanterTactics : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenCampfireBanterTactics();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Campfire")
	float CampfireGazeProximityUU = 300.0f;
};
