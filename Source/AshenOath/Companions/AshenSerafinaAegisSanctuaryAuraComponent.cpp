// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaAegisSanctuaryAuraComponent.h"

UAshenSerafinaAegisSanctuaryAuraComponent::UAshenSerafinaAegisSanctuaryAuraComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaAegisSanctuaryAuraComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSerafinaAegisSanctuaryAuraComponent::ActivateSanctuaryAura()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaAegisSanctuaryAuraComponent: Serafina activated Aegis Sanctuary Aura (Radius: %f, Mitigation: %f%%)"), SanctuaryAuraRadius, DamageMitigationPercent * 100.0f);
}
