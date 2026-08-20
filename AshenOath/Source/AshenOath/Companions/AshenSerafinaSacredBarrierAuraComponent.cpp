// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaSacredBarrierAuraComponent.h"

UAshenSerafinaSacredBarrierAuraComponent::UAshenSerafinaSacredBarrierAuraComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaSacredBarrierAuraComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSerafinaSacredBarrierAuraComponent::DeploySacredBarrierAura()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaSacredBarrierAuraComponent: Serafina deployed Sacred Barrier Aura (Barrier HP: %f)."), SacredBarrierHealth);
}
