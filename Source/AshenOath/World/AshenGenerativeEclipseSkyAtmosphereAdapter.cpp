// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenGenerativeEclipseSkyAtmosphereAdapter.h"

UAshenGenerativeEclipseSkyAtmosphereAdapter::UAshenGenerativeEclipseSkyAtmosphereAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGenerativeEclipseSkyAtmosphereAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	RayleighScatteringScale = 1.0f + (NewState.Corruption * 3.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGenerativeEclipseSkyAtmosphereAdapter: Rayleigh scattering scale set to %.2f"), RayleighScatteringScale);
}
