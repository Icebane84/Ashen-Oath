// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenUnreliableNeedleHeavyParrySlowMoModulator.h"

UAshenUnreliableNeedleHeavyParrySlowMoModulator::UAshenUnreliableNeedleHeavyParrySlowMoModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenUnreliableNeedleHeavyParrySlowMoModulator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	SlowMoTimeDilation = 0.2f + (NewState.Isolation * 0.3f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableNeedleHeavyParrySlowMoModulator: Slow-mo time dilation set to %.2f"), SlowMoTimeDilation);
}
