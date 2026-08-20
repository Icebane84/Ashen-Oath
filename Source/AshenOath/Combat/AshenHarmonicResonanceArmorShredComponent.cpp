// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenHarmonicResonanceArmorShredComponent.h"

UAshenHarmonicResonanceArmorShredComponent::UAshenHarmonicResonanceArmorShredComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bArmorFractured = false;
}
void UAshenHarmonicResonanceArmorShredComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenHarmonicResonanceArmorShredComponent::ShatterCrystallinePlates(float BaseArmor)
{
	bArmorFractured = true;
	const float FracturedArmor = BaseArmor * 0.30f; // -70% armor shred on crystalline plates
	UE_LOG(LogTemp, Warning, TEXT("UAshenHarmonicResonanceArmorShredComponent: Serafina Sang Harmonic Note! Crystalline Armor Shredded from %.1f to %.1f!"),
		BaseArmor, FracturedArmor);
	return FracturedArmor;
}
