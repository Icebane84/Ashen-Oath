// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenForensicMindscapeMasterBridge.h"

UAshenForensicMindscapeMasterBridge::UAshenForensicMindscapeMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenForensicMindscapeMasterBridge::BroadcastDeductionUpdate(
	FName CaseId,
	float SynthesisScore)
{
	OnDeductionBroadcaster.Broadcast(CaseId, SynthesisScore);
}
