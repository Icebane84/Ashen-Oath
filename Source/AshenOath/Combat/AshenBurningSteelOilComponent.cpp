// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenBurningSteelOilComponent.h"

UAshenBurningSteelOilComponent::UAshenBurningSteelOilComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsBladesIgnited = false;
	PostureDamageBonus = 35.0f;
	ArmorStripPercentage = 0.15f;
}
void UAshenBurningSteelOilComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenBurningSteelOilComponent::ApplyOilToBlades(float DurationSeconds)
{
	bIsBladesIgnited = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenBurningSteelOilComponent: BURNING STEEL OIL APPLIED TO CUTLASSES! (+%.1f Posture DMG, -%.1f%% Armor for %.1fs)!"),
		PostureDamageBonus, ArmorStripPercentage * 100.0f, DurationSeconds);
}
