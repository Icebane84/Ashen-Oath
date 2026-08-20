// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticGarrettGadgetAudioComponent.h"

UAshenDiegeticGarrettGadgetAudioComponent::UAshenDiegeticGarrettGadgetAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticGarrettGadgetAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticGarrettGadgetAudioComponent::PlayGrappleFireSound()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticGarrettGadgetAudioComponent: Grapple pneumatic fire & cable whir sound played."));
}

void UAshenDiegeticGarrettGadgetAudioComponent::PlayTripwireArmSound()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticGarrettGadgetAudioComponent: Tripwire ratchet arm sound played."));
}

void UAshenDiegeticGarrettGadgetAudioComponent::PlaySmokeHissSound()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticGarrettGadgetAudioComponent: Smoke canister explosive hiss sound played."));
}
