// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenDiegeticStaminaRecoveryRateModulator.h"

UAshenDiegeticStaminaRecoveryRateModulator::UAshenDiegeticStaminaRecoveryRateModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticStaminaRecoveryRateModulator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	RechargeDelayMultiplier = FMath::Clamp(1.5f - (NewState.Resolve * 0.8f), 0.7f, 2.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticStaminaRecoveryRateModulator: Stamina recharge delay multiplier set to %.2f"), RechargeDelayMultiplier);
}
