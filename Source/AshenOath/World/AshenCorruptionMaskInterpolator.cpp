// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenCorruptionMaskInterpolator.h"

UAshenCorruptionMaskInterpolator::UAshenCorruptionMaskInterpolator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCorruptionMaskInterpolator::BeginPlay()
{
	Super::BeginPlay();
}

FAshenCorruptionMaskValues UAshenCorruptionMaskInterpolator::CalculateCorruptionMaskChannelValues(float CorruptionAmount)
{
	FAshenCorruptionMaskValues MaskValues;

	float t1 = FMath::Clamp((CorruptionAmount - 0.00f) / 0.55f, 0.0f, 1.0f);
	float t2 = FMath::Clamp((CorruptionAmount - 0.35f) / 0.65f, 0.0f, 1.0f);

	MaskValues.SeamGrimeG = t1;
	MaskValues.ArmorSootR = t2;
	MaskValues.TabardRaggednessB = t2;
	MaskValues.EyeBladeEmissiveA = t2;

	UE_LOG(LogTemp, Log, TEXT("UAshenCorruptionMaskInterpolator: Interpolated RGBA mask values (R: %f, G: %f, B: %f, A: %f)"), MaskValues.ArmorSootR, MaskValues.SeamGrimeG, MaskValues.TabardRaggednessB, MaskValues.EyeBladeEmissiveA);
	return MaskValues;
}
