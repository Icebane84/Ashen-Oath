// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSomaticVeilPhaseFilterComponent.h"

UAshenSomaticVeilPhaseFilterComponent::UAshenSomaticVeilPhaseFilterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticVeilPhaseFilterComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSomaticVeilPhaseFilterComponent::ApplyVeilPhaseFilterDamage(float Amount)
{
	VeilPhaseFilterResistance = FMath::Clamp(VeilPhaseFilterResistance - (Amount / 100.0f), 0.0f, 2.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticVeilPhaseFilterComponent: Veil phase filter resistance is now %f"), VeilPhaseFilterResistance);
}
