// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenWovenStitchJournalMeshAdapter.h"

UAshenWovenStitchJournalMeshAdapter::UAshenWovenStitchJournalMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	StitchEmissiveGlow = 0.0f;
}
void UAshenWovenStitchJournalMeshAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenWovenStitchJournalMeshAdapter::UpdateJournalStitchGlow(int32 ResolvedIncidentsCount)
{
	StitchEmissiveGlow = FMath::Clamp(ResolvedIncidentsCount * 0.5f, 0.0f, 3.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenWovenStitchJournalMeshAdapter: Journal Golden Stitches Emissive: %.2f (Resolved Incidents: %d)"),
		StitchEmissiveGlow, ResolvedIncidentsCount);
}
