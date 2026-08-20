// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenEmpathicReactionTriggerVolume.h"

AAshenEmpathicReactionTriggerVolume::AAshenEmpathicReactionTriggerVolume()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenEmpathicReactionTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenEmpathicReactionTriggerVolume: Empathic trigger volume active."));
}

void AAshenEmpathicReactionTriggerVolume::TriggerZoneEmpathicReaction(FName CompanionID)
{
	if (OnEmpathicReactionTriggered.IsBound())
	{
		OnEmpathicReactionTriggered.Broadcast(CompanionID, ZoneReactionType);
	}
	UE_LOG(LogTemp, Log, TEXT("AAshenEmpathicReactionTriggerVolume: Empathic reaction '%s' triggered for %s"), *ZoneReactionType, *CompanionID.ToString());
}
