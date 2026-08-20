// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticAlchemicalAudioComponent.h"

UAshenDiegeticAlchemicalAudioComponent::UAshenDiegeticAlchemicalAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticAlchemicalAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticAlchemicalAudioComponent::PlayAlchemicalSound(EAlchemicalMatrixType Type)
{
	switch (Type)
	{
	case EAlchemicalMatrixType::BurningSteelOil:
		UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticAlchemicalAudioComponent: Thermal Oil Blade Ignition WHOOSH SFX."));
		break;
	case EAlchemicalMatrixType::GhostbloomFlashFlare:
		UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticAlchemicalAudioComponent: High-Frequency Magnesium Flash BANG SFX."));
		break;
	default:
		UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticAlchemicalAudioComponent: Glass Reagent Vial Clink SFX."));
		break;
	}
}
