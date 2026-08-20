// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSlagSerpentThermalVentComponent.h"

UAshenSlagSerpentThermalVentComponent::UAshenSlagSerpentThermalVentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSlagSerpentThermalVentComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenSlagSerpentThermalVentComponent::ApplyCryoQuench()
{
	bIsVentCarapaceCracked = true;
	InternalFurnaceTemp = 200.0f;
	UE_LOG(LogTemp, Warning, TEXT("UAshenSlagSerpentThermalVentComponent: Flash Cryo-Quench applied! Basalt carapace fractured; soft throat vents exposed."));
}

void UAshenSlagSerpentThermalVentComponent::ExtinguishFurnaceHeart()
{
	InternalFurnaceTemp = 0.0f;
	UE_LOG(LogTemp, Warning, TEXT("UAshenSlagSerpentThermalVentComponent: BASALT VENT CAUTERIZATION! Elemental core extinguished; heat aura purged."));
}
