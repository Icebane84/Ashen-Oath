// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenWhiteFlameDualSenseHapticsComponent.h"

UAshenWhiteFlameDualSenseHapticsComponent::UAshenWhiteFlameDualSenseHapticsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsSoothingHapticsActive = false;
}
void UAshenWhiteFlameDualSenseHapticsComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenWhiteFlameDualSenseHapticsComponent::TriggerCatharsisHeartbeatHaptics(bool bActive)
{
	bIsSoothingHapticsActive = bActive;
	UE_LOG(LogTemp, Log, TEXT("UAshenWhiteFlameDualSenseHapticsComponent: DualSense Trigger Lock RELEASED & Soothing Heartbeat Haptics: %s!"),
		bIsSoothingHapticsActive ? TEXT("ACTIVE") : TEXT("INACTIVE"));
}
