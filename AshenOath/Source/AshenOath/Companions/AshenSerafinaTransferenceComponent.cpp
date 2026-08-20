// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenSerafinaTransferenceComponent.h"

UAshenSerafinaTransferenceComponent::UAshenSerafinaTransferenceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSerafinaTransferenceComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenSerafinaTransferenceComponent::CalculateTransferenceToll(float RawHealingAmount, float KaelenCorruption) const
{
	// Toll = RawHealing * (1.0 + (e^Corruption - 1.0)) = RawHealing * e^Corruption
	const float ExpFactor = FMath::Exp(KaelenCorruption);
	return RawHealingAmount * ExpFactor;
}

bool UAshenSerafinaTransferenceComponent::ExecuteTransferencePulse(float HealingAmount, float KaelenCorruption)
{
	bIsChannelingActive = true;
	const float BurnoutToll = CalculateTransferenceToll(HealingAmount, KaelenCorruption);
	if (OnTransferencePulse.IsBound())
	{
		OnTransferencePulse.Broadcast(HealingAmount, BurnoutToll);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaTransferenceComponent: Transference pulse executed — Healed: %.1f | Burnout Toll: %.1f (Corruption: %.2f)"),
		HealingAmount, BurnoutToll, KaelenCorruption);
	bIsChannelingActive = false;
	return true;
}
