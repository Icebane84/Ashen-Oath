// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "UBTService_AshenCompanionDissonanceAI.generated.h"

/**
 * UBTService_AshenCompanionDissonanceAI
 * 
 * Modifies companion flank spacing, guard assist responsiveness, and moral voice barks based on party cognitive dissonance.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenCompanionDissonanceAI : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenCompanionDissonanceAI();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|CSE")
	float AssistHesitationDelaySeconds = 0.0f;
};
