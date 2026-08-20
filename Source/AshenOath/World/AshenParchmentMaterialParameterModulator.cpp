// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenParchmentMaterialParameterModulator.h"

UAshenParchmentMaterialParameterModulator::UAshenParchmentMaterialParameterModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenParchmentMaterialParameterModulator::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenParchmentMaterialParameterModulator::ModulateParchmentMaterialParameters(float AshCoverage, float VeinCreep)
{
	AshStainCoverageScalar = FMath::Clamp(AshCoverage, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenParchmentMaterialParameterModulator: Modulated parchment MPC parameters (AshCoverage: %f)."), AshStainCoverageScalar);
}
