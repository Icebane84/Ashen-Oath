// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "UBTService_AshenAIElementalHazardReactionAI.generated.h"

/**
 * UBTService_AshenAIElementalHazardReactionAI
 * 
 * AI service detecting superheated slag blades and hazardous acidic clouds, triggering evasive roll-backs to avoid AoE deflagration bursts.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenAIElementalHazardReactionAI : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenAIElementalHazardReactionAI();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Hazard")
	bool bEvadingThermalBlast = false;
};
