// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/Ashen3DJournalMeshAdapter.h"

UAshen3DJournalMeshAdapter::UAshen3DJournalMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	GoldFoilLeafGlow = 0.0f;
}
void UAshen3DJournalMeshAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshen3DJournalMeshAdapter::UpdateJournalFoilLeafing(int32 TotalInkedRegions)
{
	GoldFoilLeafGlow = FMath::Clamp(TotalInkedRegions * 0.4f, 0.0f, 2.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshen3DJournalMeshAdapter: Gold Foil Leafing Glow: %.2f (Total Inked Regions: %d)"),
		GoldFoilLeafGlow, TotalInkedRegions);
}
