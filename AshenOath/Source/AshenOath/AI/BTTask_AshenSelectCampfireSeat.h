// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "BTTask_AshenSelectCampfireSeat.generated.h"

/**
 * UBTTask_AshenSelectCampfireSeat
 * 
 * Behavior Tree Task ordering companion to find and move to their dynamically
 * staged seating location around the campfire.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenSelectCampfireSeat : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenSelectCampfireSeat();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Hearth")
	ECompanionHearthSeating DesiredSeating = ECompanionHearthSeating::StandardFireside;
};
