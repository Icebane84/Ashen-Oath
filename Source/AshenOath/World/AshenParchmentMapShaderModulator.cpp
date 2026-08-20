// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenParchmentMapShaderModulator.h"

UAshenParchmentMapShaderModulator::UAshenParchmentMapShaderModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenParchmentMapShaderModulator::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenParchmentMapShaderModulator::UpdateMapParchmentShaderParameters(float Soot, float InkBleed)
{
	ParchmentSootScalar = FMath::Clamp(Soot, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenParchmentMapShaderModulator: Updated map parchment MPC shader parameters (Soot: %f, Ink Bleed: %f)"), ParchmentSootScalar, InkBleed);
}
