// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "BTTask_AshenCompanionMarginaliaQuery.generated.h"

/**
 * UBTTask_AshenCompanionMarginaliaQuery
 * 
 * Behavior Tree Task querying recent inner voice compilations to select
 * companion contextual barks and tactical remarks.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenCompanionMarginaliaQuery : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenCompanionMarginaliaQuery();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Marginalia")
	FName CompanionName = FName(TEXT("Garrett"));
};
