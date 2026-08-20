// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenEcosystemSaveGameAdapter.h"

UAshenEcosystemSaveGameAdapter::UAshenEcosystemSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEcosystemSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenEcosystemSaveGameAdapter::SaveEcosystemMetrics(float HistoricalConsistency, int32 MasteredBossesCount, bool bStarStriderDiscovered)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenEcosystemSaveGameAdapter: Saved Ecosystem Metrics -> Consistency: %.2f, Mastered: %d, Star-Strider: %s"),
		HistoricalConsistency, MasteredBossesCount, bStarStriderDiscovered ? TEXT("YES") : TEXT("NO"));
	return true;
}
