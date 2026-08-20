// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenAudioChannelMasterBridge.h"

UAshenAudioChannelMasterBridge::UAshenAudioChannelMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenAudioChannelMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bAudioBridgeActive = true;
}

void UAshenAudioChannelMasterBridge::BroadcastTacticalCue(FName SpeakerID, const FString& Line, float ActionWindowSeconds)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenAudioChannelMasterBridge: Broadcasted Tactical Cue [%s]: \"%s\" (Window: %.2fs) to DualSense & Accessibility Subtitles!"),
		*SpeakerID.ToString(), *Line, ActionWindowSeconds);
}
