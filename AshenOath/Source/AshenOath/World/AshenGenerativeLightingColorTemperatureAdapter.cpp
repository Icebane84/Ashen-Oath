// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenGenerativeLightingColorTemperatureAdapter.h"

UAshenGenerativeLightingColorTemperatureAdapter::UAshenGenerativeLightingColorTemperatureAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGenerativeLightingColorTemperatureAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	SunColorTemperatureKelvin = 6500.0f - (NewState.IntegrationDebt * 2500.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGenerativeLightingColorTemperatureAdapter: Sun color temperature Kelvin set to %.1fK"), SunColorTemperatureKelvin);
}
