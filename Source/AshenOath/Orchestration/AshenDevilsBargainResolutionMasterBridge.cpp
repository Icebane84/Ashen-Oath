// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 833: Ashen Devil's Bargain Resolution Master Bridge

#include "AshenDevilsBargainResolutionMasterBridge.h"

void UAshenDevilsBargainResolutionMasterBridge::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bIsBridgeActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenDevilsBargainResolutionMasterBridge: Initialized — Devil's Bargain Resolution Master Bridge ONLINE."));
}

void UAshenDevilsBargainResolutionMasterBridge::SynchronizeResolutionPass(bool bSurrenderChosen)
{
	bIsBridgeActive = true;
	const FName ResolutionTag = bSurrenderChosen ? FName(TEXT("Resolution.SurrenderDarkUnchained")) : FName(TEXT("Resolution.ResistWhiteFlameUnbroken"));

	OnResolutionBridgeSynchronized.Broadcast(ResolutionTag, bIsBridgeActive);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDevilsBargainResolutionMasterBridge: RESOLUTION PASS SYNCHRONIZED -> Choice: '%s' | Visual/Haptic/Audio Layers Fused."),
		*ResolutionTag.ToString());
}
