// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaRadiantPurgePincerDirectorComponent.h"

UAshenSerafinaRadiantPurgePincerDirectorComponent::UAshenSerafinaRadiantPurgePincerDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaRadiantPurgePincerDirectorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSerafinaRadiantPurgePincerDirectorComponent::DeployRadiantPurgePincerAura()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaRadiantPurgePincerDirectorComponent: Serafina deployed Radiant Purge Pincer Aura (Radius: %f)."), RadiantPurgePincerRadius);
}
