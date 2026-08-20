// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "BTDecorator_AshenIntentConfidenceGate.generated.h"

/**
 * UBTDecorator_AshenIntentConfidenceGate
 * 
 * Behavior Tree Decorator checking if intent confidence reaches the required tier.
 */
UCLASS()
class ASHENOATH_API UBTDecorator_AshenIntentConfidenceGate : public UBTDecorator
{
	GENERATED_BODY()

public:
	UBTDecorator_AshenIntentConfidenceGate();

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Gate")
	EIntentConfidenceTier MinimumRequiredConfidence = EIntentConfidenceTier::Confident;
};
