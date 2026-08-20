// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDualSenseSpeakerControllerComponent.h"

UAshenDualSenseSpeakerControllerComponent::UAshenDualSenseSpeakerControllerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SpeakerVolume = 1.0f;
}
void UAshenDualSenseSpeakerControllerComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenDualSenseSpeakerControllerComponent::PlayControllerVoiceCue(const FString& Line, float HapticStrength)
{
	if (SpeakerVolume <= 0.0f || Line.IsEmpty()) return false;

	UE_LOG(LogTemp, Warning, TEXT("UAshenDualSenseSpeakerControllerComponent: DualSense Speaker Broadcast -> \"%s\" (Volume: %.2f, Haptic: %.2f)"),
		*Line, SpeakerVolume, HapticStrength);

	return true;
}
