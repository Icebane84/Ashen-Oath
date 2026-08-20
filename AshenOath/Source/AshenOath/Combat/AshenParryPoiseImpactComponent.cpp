// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenParryPoiseImpactComponent.h"

UAshenParryPoiseImpactComponent::UAshenParryPoiseImpactComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenParryPoiseImpactComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenParryPoiseImpactComponent::CalculatePostureDamageDealt(float PoiseMultiplier) const
{
	const float FinalPostureDamage = BasePostureDamage * PoiseMultiplier;
	UE_LOG(LogTemp, Log, TEXT("UAshenParryPoiseImpactComponent: Posture damage calculated: %.1f (Multiplier: %.2fx)"),
		FinalPostureDamage, PoiseMultiplier);
	return FinalPostureDamage;
}
