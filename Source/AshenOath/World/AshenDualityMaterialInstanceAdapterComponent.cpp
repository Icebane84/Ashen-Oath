// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenDualityMaterialInstanceAdapterComponent.h"

UAshenDualityMaterialInstanceAdapterComponent::UAshenDualityMaterialInstanceAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDualityMaterialInstanceAdapterComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDualityMaterialInstanceAdapterComponent::UpdateMaterialInstanceParameters(FName ParameterName, float Value)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDualityMaterialInstanceAdapterComponent: Material parameter '%s' set to %.2f"), *ParameterName.ToString(), Value);
}
