// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "BTTask_AshenCampfireJournalAudit.generated.h"

/**
 * UBTTask_AshenCampfireJournalAudit
 * 
 * Behavior Tree Task triggering companion sketching/writing animations at camp.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenCampfireJournalAudit : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenCampfireJournalAudit();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Campfire")
	EMarginaliaAuthor CompanionAuthor = EMarginaliaAuthor::Garrett;
};
