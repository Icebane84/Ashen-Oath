// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenEcosystemPostProcessAdapter.h"

UAshenEcosystemPostProcessAdapter::UAshenEcosystemPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEcosystemPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenEcosystemPostProcessAdapter::ApplyCelestialSanctuaryBloom(float Proximity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenEcosystemPostProcessAdapter: Celestial Sanctuary Bloom applied -> Proximity: %.2f"), Proximity);
}
