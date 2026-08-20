// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenEcosystemMasterBridge.h"

UAshenEcosystemMasterBridge::UAshenEcosystemMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenEcosystemMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bEcosystemBridgeActive = true;
}

void UAshenEcosystemMasterBridge::BroadcastResonanceUnlocked()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenEcosystemMasterBridge: Broadcasted Symbiotic Resonance Unlocked across all domains!"));
}

void UAshenEcosystemMasterBridge::BroadcastBossPhaseAdvanced(EBossPuzzlePhase NextPhase)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenEcosystemMasterBridge: Broadcasted Boss Puzzle Phase Transition to Phase %d!"),
		static_cast<int32>(NextPhase));
}
