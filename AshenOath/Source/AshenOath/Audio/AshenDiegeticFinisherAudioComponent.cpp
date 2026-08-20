// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticFinisherAudioComponent.h"

UAshenDiegeticFinisherAudioComponent::UAshenDiegeticFinisherAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticFinisherAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticFinisherAudioComponent::PlayFinisherAudioStinger(EAshenPartyFinisherType FinisherType)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticFinisherAudioComponent: Playing synchronized finisher audio stinger for Type %d."), (int32)FinisherType);
}
