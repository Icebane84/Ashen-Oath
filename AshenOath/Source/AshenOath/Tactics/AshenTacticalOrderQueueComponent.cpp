// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Tactics/AshenTacticalOrderQueueComponent.h"

UAshenTacticalOrderQueueComponent::UAshenTacticalOrderQueueComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenTacticalOrderQueueComponent::EnqueueOrder(const FSquadCommandEntry& Order)
{
	if (Order.CommandType == ETacticalCommandType::None)
	{
		return false;
	}

	if (OrderQueue.Num() >= 4)
	{
		// Maximum 4 queued tactical orders allowed
		return false;
	}

	OrderQueue.Add(Order);
	return true;
}

bool UAshenTacticalOrderQueueComponent::DequeueNextOrder(FSquadCommandEntry& OutOrder)
{
	if (OrderQueue.Num() == 0)
	{
		return false;
	}

	OutOrder = OrderQueue[0];
	OrderQueue.RemoveAt(0);
	return true;
}

void UAshenTacticalOrderQueueComponent::ClearQueue()
{
	OrderQueue.Empty();
}
