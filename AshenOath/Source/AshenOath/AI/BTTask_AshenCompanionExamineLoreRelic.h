// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "BTTask_AshenCompanionExamineLoreRelic.generated.h"

/**
 * UBTTask_AshenCompanionExamineLoreRelic
 * 
 * Directs companion AI to inspect a discovered historical relic and deliver commentary.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenCompanionExamineLoreRelic : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenCompanionExamineLoreRelic();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Archive")
	FName RelicToInspect = NAME_None;
};
