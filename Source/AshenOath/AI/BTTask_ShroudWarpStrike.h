// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_ShroudWarpStrike.generated.h"

/**
 * UBTTask_ShroudWarpStrike
 * Behavior Tree task executing spectral teleport ambush strikes behind the player.
 */
UCLASS()
class ASHENOATH_API UBTTask_ShroudWarpStrike : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTask_ShroudWarpStrike();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	float WarpDistanceBehind = 200.0f;
};
