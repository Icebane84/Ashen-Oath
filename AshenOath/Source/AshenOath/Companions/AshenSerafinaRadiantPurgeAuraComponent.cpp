// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaRadiantPurgeAuraComponent.h"

UAshenSerafinaRadiantPurgeAuraComponent::UAshenSerafinaRadiantPurgeAuraComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaRadiantPurgeAuraComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSerafinaRadiantPurgeAuraComponent::EmitRadiantPurgePulse()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaRadiantPurgeAuraComponent: Emitted radiant purge pulse (Radius: %f)."), RadiantPurgeRadius);
}
