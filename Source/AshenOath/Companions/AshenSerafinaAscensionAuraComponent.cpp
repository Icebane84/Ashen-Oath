// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaAscensionAuraComponent.h"

UAshenSerafinaAscensionAuraComponent::UAshenSerafinaAscensionAuraComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaAscensionAuraComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSerafinaAscensionAuraComponent::DeployAscensionAura()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaAscensionAuraComponent: Serafina deployed Ascension Aura (Radius: %f)."), AscensionAuraRadius);
}
