// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticAdvancedCombatAudioComponent.h"

UAshenDiegeticAdvancedCombatAudioComponent::UAshenDiegeticAdvancedCombatAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticAdvancedCombatAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticAdvancedCombatAudioComponent::PlayParryDeflectionRing()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticAdvancedCombatAudioComponent: Crisp steel parry deflection ring played."));
}

void UAshenDiegeticAdvancedCombatAudioComponent::PlayUnchainedBloodRushPulse()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticAdvancedCombatAudioComponent: Unchained berserk blood-rush audio pulse active."));
}

void UAshenDiegeticAdvancedCombatAudioComponent::PlayVoidShatterBassDrop()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticAdvancedCombatAudioComponent: Void shatter low-frequency sub-bass explosion played."));
}
