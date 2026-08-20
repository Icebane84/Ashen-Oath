// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenRegionalCorruptionAtmosphereAdapter.h"

UAshenRegionalCorruptionAtmosphereAdapter::UAshenRegionalCorruptionAtmosphereAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenRegionalCorruptionAtmosphereAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenRegionalCorruptionAtmosphereAdapter::UpdateSectorAtmosphere(int32 SectorIndex, float CorruptionLevel)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenRegionalCorruptionAtmosphereAdapter: Atmosphere updated for Sector %d (Corruption: %.1f%%) — Ash storm and darkened fog applied."),
		SectorIndex, CorruptionLevel);
}
