// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaRadiantPurgeAuraDirectorComponent.h"

UAshenSerafinaRadiantPurgeAuraDirectorComponent::UAshenSerafinaRadiantPurgeAuraDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaRadiantPurgeAuraDirectorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSerafinaRadiantPurgeAuraDirectorComponent::DeployRadiantPurgeAura()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaRadiantPurgeAuraDirectorComponent: Serafina deployed Radiant Purge Aura (Radius: %f)."), RadiantPurgeAuraRadius);
}
