// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticBestiaryFinisherAudioComponent.h"

UAshenDiegeticBestiaryFinisherAudioComponent::UAshenDiegeticBestiaryFinisherAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticBestiaryFinisherAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticBestiaryFinisherAudioComponent::PlayBestiaryAudioStinger(EAshenPartyFinisherType FinisherType)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticBestiaryFinisherAudioComponent: Playing bespoke bestiary audio stinger for Finisher Type %d."), (int32)FinisherType);
}
