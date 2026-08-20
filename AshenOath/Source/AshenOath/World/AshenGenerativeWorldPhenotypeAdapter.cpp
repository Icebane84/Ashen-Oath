// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenGenerativeWorldPhenotypeAdapter.h"

UAshenGenerativeWorldPhenotypeAdapter::UAshenGenerativeWorldPhenotypeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGenerativeWorldPhenotypeAdapter::UpdateWorldTension(const FSoulStateVector& SoulState)
{
	WeatherTensionScalar = FMath::Clamp((SoulState.Corruption * 0.7f) + ((1.0f - SoulState.Resolve) * 0.3f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGenerativeWorldPhenotypeAdapter: Weather tension scalar updated to %.2f"), WeatherTensionScalar);
}
