// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "BTTask_AshenCompanionInspectForge.generated.h"

/**
 * UBTTask_AshenCompanionInspectForge
 * 
 * Behavior Tree Task directing companion to approach anvil and inspect newly socketed runes.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenCompanionInspectForge : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenCompanionInspectForge();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Forge")
	float InspectionDurationSeconds = 3.0f;
};
