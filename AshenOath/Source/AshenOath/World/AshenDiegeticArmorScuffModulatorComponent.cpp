// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenDiegeticArmorScuffModulatorComponent.h"

UAshenDiegeticArmorScuffModulatorComponent::UAshenDiegeticArmorScuffModulatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticArmorScuffModulatorComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	ArmorScuffScalar = FMath::Clamp(NewState.Isolation * 0.9f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticArmorScuffModulatorComponent: Armor scuff weathering scalar updated to %.2f"), ArmorScuffScalar);
}
