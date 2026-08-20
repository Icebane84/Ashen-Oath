// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_InquisitorialPurgeLunge.generated.h"

/**
 * UBTTask_InquisitorialPurgeLunge
 * Behavior Tree task executing high-velocity purge thrusts toward the target.
 */
UCLASS()
class ASHENOATH_API UBTTask_InquisitorialPurgeLunge : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTask_InquisitorialPurgeLunge();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	float LungeSpeed = 1200.0f;
};
