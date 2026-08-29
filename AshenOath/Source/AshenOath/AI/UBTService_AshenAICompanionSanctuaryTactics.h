// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "UBTService_AshenAICompanionSanctuaryTactics.generated.h"

/**
 * UBTService_AshenAICompanionSanctuaryTactics
 * 
 * Companion AI service transitioning Garrett & Serafina between defensive survival awareness (open storms) and relaxed rest postures (caverns and sanctuary hearths).
 */
UCLASS()
class ASHENOATH_API UBTService_AshenAICompanionSanctuaryTactics : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenAICompanionSanctuaryTactics();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Survival")
	bool bInSanctuaryRestState = false;
};
