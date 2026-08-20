// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenLivingCodexMasterBridge.h"

UAshenLivingCodexMasterBridge::UAshenLivingCodexMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenLivingCodexMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bCodexBridgeActive = true;
}

void UAshenLivingCodexMasterBridge::BroadcastCodexUnlocked(FName EntryID, ECodexFaction Faction)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingCodexMasterBridge: Broadcasted Codex Unlocked Event (ID: '%s', Faction: %d)."),
		*EntryID.ToString(), static_cast<int32>(Faction));
}

void UAshenLivingCodexMasterBridge::BroadcastPsychologicalToneChanged(EPsychologicalTone NewTone)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingCodexMasterBridge: Broadcasted Psychological Tone Shift -> %d."),
		static_cast<int32>(NewTone));
}
