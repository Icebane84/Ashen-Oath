// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaSacredBarrierPincerDirectorComponent.h"

UAshenSerafinaSacredBarrierPincerDirectorComponent::UAshenSerafinaSacredBarrierPincerDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaSacredBarrierPincerDirectorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSerafinaSacredBarrierPincerDirectorComponent::DeploySacredBarrierPincer()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaSacredBarrierPincerDirectorComponent: Serafina deployed Sacred Barrier Pincer Aura (Health: %f)."), SacredBarrierPincerHealth);
}
