// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenDiegeticHeartbeatAudioPacerComponent.h"

UAshenDiegeticHeartbeatAudioPacerComponent::UAshenDiegeticHeartbeatAudioPacerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticHeartbeatAudioPacerComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	HeartbeatPitchMultiplier = FMath::Clamp(1.3f - (NewState.Resolve * 0.5f), 0.8f, 1.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticHeartbeatAudioPacerComponent: Heartbeat pitch multiplier set to %.2f"), HeartbeatPitchMultiplier);
}
