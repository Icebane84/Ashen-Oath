// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSomaticArmorCorrosionComponent.h"

UAshenSomaticArmorCorrosionComponent::UAshenSomaticArmorCorrosionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticArmorCorrosionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSomaticArmorCorrosionComponent::ApplyArmorCorrosionDamage(float Amount)
{
	ArmorCorrosionLevel = FMath::Clamp(ArmorCorrosionLevel + Amount, 0.0f, 100.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticArmorCorrosionComponent: Armor corrosion level is now %f"), ArmorCorrosionLevel);
}

float UAshenSomaticArmorCorrosionComponent::GetCorrosionMitigationScalar() const
{
	return 1.0f - (ArmorCorrosionLevel / 200.0f);
}
