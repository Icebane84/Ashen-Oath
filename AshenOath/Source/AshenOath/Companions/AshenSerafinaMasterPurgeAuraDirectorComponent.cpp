// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaMasterPurgeAuraDirectorComponent.h"

UAshenSerafinaMasterPurgeAuraDirectorComponent::UAshenSerafinaMasterPurgeAuraDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaMasterPurgeAuraDirectorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSerafinaMasterPurgeAuraDirectorComponent::DeployMasterPurgeAura()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaMasterPurgeAuraDirectorComponent: Serafina deployed Master Purge Aura (Radius: %f)."), MasterPurgeAuraRadius);
}
