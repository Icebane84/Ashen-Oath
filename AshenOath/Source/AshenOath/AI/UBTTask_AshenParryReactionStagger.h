// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "UBTTask_AshenParryReactionStagger.generated.h"

/**
 * UBTTask_AshenParryReactionStagger
 * 
 * Directs enemy AI to enter a staggered vulnerability state upon receiving a high-precision angular deflection.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenParryReactionStagger : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenParryReactionStagger();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|KineticBerserk")
	float StaggerDurationSeconds = 1.25f;
};
