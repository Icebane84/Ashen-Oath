// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenTacticalOrderQueueComponent.generated.h"

/**
 * UAshenTacticalOrderQueueComponent
 * 
 * Manages a FIFO queue of ordered companion actions, enforcing order limits and execution state.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalOrderQueueComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTacticalOrderQueueComponent();

	/** Pushes an order into the queue */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Tactics")
	bool EnqueueOrder(const FSquadCommandEntry& Order);

	/** Pops the next pending order */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Tactics")
	bool DequeueNextOrder(FSquadCommandEntry& OutOrder);

	/** Clears all pending orders */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Tactics")
	void ClearQueue();

	UFUNCTION(BlueprintPure, Category = "Ashen|Tactics")
	int32 GetQueueCount() const { return OrderQueue.Num(); }

private:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Tactics")
	TArray<FSquadCommandEntry> OrderQueue;
};
