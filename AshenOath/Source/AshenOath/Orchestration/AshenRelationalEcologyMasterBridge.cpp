// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenRelationalEcologyMasterBridge.h"

UAshenRelationalEcologyMasterBridge::UAshenRelationalEcologyMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenRelationalEcologyMasterBridge::BroadcastCostlyPresenceTriggered(
	const FAshenCostlyPresenceIntent& Intent,
	const FVector& TargetLocation)
{
	OnCostlyPresenceTriggered.Broadcast(Intent, TargetLocation);
}

void UAshenRelationalEcologyMasterBridge::BroadcastWordlessReconciliation(FName CompanionName)
{
	OnWordlessReconciliationExecuted.Broadcast(CompanionName);
}

void UAshenRelationalEcologyMasterBridge::BroadcastFormationSpacingUpdate(
	FName CompanionName,
	float TargetSpacingUU,
	float LerpSpeed)
{
	OnDynamicFormationOffsetUpdated.Broadcast(CompanionName, TargetSpacingUU, LerpSpeed);
}
