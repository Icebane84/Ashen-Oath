// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "UBTService_AshenAIStanceReactionTactics.generated.h"

/**
 * UBTService_AshenAIStanceReactionTactics
 * 
 * AI service detecting Kaelen's active Oathbringer guard (e.g. bracing against Vom Tag overheads, feinting around Ochs crown parries).
 */
UCLASS()
class ASHENOATH_API UBTService_AshenAIStanceReactionTactics : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenAIStanceReactionTactics();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Stance")
	bool bBracingAgainstHeavyCleave = false;
};
