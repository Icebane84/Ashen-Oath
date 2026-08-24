// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "UBTService_AshenShroudKnightAITactics.generated.h"

/**
 * UBTService_AshenShroudKnightAITactics
 * 
 * AI Behavior Tree service driving the Shroud-Knight's glitch-lurch locomotion, wall-phasing strafing, and paranoia threat targeting.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenShroudKnightAITactics : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenShroudKnightAITactics();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Boss")
	float GlitchLurchIntervalSeconds = 1.5f;
};
