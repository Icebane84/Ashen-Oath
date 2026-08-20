// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenGenerativeFogDensityPhenotypeAdapter.h"

UAshenGenerativeFogDensityPhenotypeAdapter::UAshenGenerativeFogDensityPhenotypeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGenerativeFogDensityPhenotypeAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	VolumetricFogDensity = FMath::Clamp(0.02f + (NewState.Corruption * 0.18f), 0.02f, 0.20f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGenerativeFogDensityPhenotypeAdapter: Volumetric fog density updated to %.3f"), VolumetricFogDensity);
}
