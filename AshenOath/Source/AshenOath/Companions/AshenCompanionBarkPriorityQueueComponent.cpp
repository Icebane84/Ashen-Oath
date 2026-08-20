// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionBarkPriorityQueueComponent.h"

UAshenCompanionBarkPriorityQueueComponent::UAshenCompanionBarkPriorityQueueComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionBarkPriorityQueueComponent::QueueBark(FName CompanionID, FName BarkID, int32 Priority)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionBarkPriorityQueueComponent: Queued bark '%s' for %s (Priority: %d)"),
		*BarkID.ToString(), *CompanionID.ToString(), Priority);
}
