// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "UBTService_AshenGarrettStabilizerTactics.generated.h"

/**
 * UBTService_AshenGarrettStabilizerTactics
 * 
 * AI Behavior Tree service monitoring Kaelen's corruption and guiding Garrett to inject Gloomwood Sap Needles at crisis thresholds (>0.70).
 */
UCLASS()
class ASHENOATH_API UBTService_AshenGarrettStabilizerTactics : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenGarrettStabilizerTactics();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Garrett")
	float StabilizationThreshold01 = 0.70f;
};
