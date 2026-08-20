// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenDualityEngineShaderModulator.h"

UAshenDualityEngineShaderModulator::UAshenDualityEngineShaderModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDualityEngineShaderModulator::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDualityEngineShaderModulator::UpdateDualityShaderParameters(float CorruptionAmount)
{
	CorruptionAmountScalar = FMath::Clamp(CorruptionAmount, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDualityEngineShaderModulator: Updated Duality MPC shader parameters (CorruptionAmount: %f)"), CorruptionAmountScalar);
}
