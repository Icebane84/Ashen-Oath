// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "UBTService_AshenAIPoiseBreakPunishAI.generated.h"

/**
 * UBTService_AshenAIPoiseBreakPunishAI
 * 
 * AI Behavior Tree service detecting target guard shatter and switching AI blackboards to aggressive punish execution branches.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenAIPoiseBreakPunishAI : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenAIPoiseBreakPunishAI();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Kinematics")
	float PunishGapCloseSpeedMultiplier = 1.35f;
};
