// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenOathbringerNarrativeComponent.h"

UAshenOathbringerNarrativeComponent::UAshenOathbringerNarrativeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenOathbringerNarrativeComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenOathbringerNarrativeComponent::CalculateDamageBonusMultiplier(int32 RuneCount) const
{
	const float Bonus = 1.0f + (BaseScalingPerRune * (float)RuneCount);
	UE_LOG(LogTemp, Log, TEXT("UAshenOathbringerNarrativeComponent: Damage multiplier for %d runes: %.2fx"), RuneCount, Bonus);
	return Bonus;
}
