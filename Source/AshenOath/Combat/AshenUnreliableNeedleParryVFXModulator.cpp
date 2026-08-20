// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenUnreliableNeedleParryVFXModulator.h"

UAshenUnreliableNeedleParryVFXModulator::UAshenUnreliableNeedleParryVFXModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenUnreliableNeedleParryVFXModulator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	SparkParticleScaleMultiplier = 1.0f + (NewState.Isolation * 1.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableNeedleParryVFXModulator: Spark particle scale multiplier set to %.2f"), SparkParticleScaleMultiplier);
}
