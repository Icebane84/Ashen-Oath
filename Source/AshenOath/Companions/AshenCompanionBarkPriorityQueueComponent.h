// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionBarkPriorityQueueComponent.generated.h"

/**
 * UAshenCompanionBarkPriorityQueueComponent
 * Priority queue managing companion dialogue barks during high-intensity combat.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionBarkPriorityQueueComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionBarkPriorityQueueComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	void QueueBark(FName CompanionID, FName BarkID, int32 Priority);
};
