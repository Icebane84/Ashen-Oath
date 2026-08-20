// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 388: Ashen Geopolitical Faction Merchant Subsystem

#include "AshenGeopoliticalFactionMerchantSubsystem.h"

void UAshenGeopoliticalFactionMerchantSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	FactionUnlockedTiers.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenGeopoliticalFactionMerchantSubsystem: Initialized — Faction Merchant Network ONLINE."));
}

void UAshenGeopoliticalFactionMerchantSubsystem::RefreshFactionMerchantTier(FName FactionID, float CurrentStanding)
{
	if (FactionID.IsNone()) return;

	int32 Tier = 1;
	if (CurrentStanding >= 75.0f) Tier = 3;
	else if (CurrentStanding >= 25.0f) Tier = 2;

	FactionUnlockedTiers.Add(FactionID, Tier);
	OnInventoryUnlocked.Broadcast(FactionID, Tier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGeopoliticalFactionMerchantSubsystem: FACTION '%s' MERCHANT TIER UPDATED -> Tier %d (Standing: %.1f)."),
		*FactionID.ToString(), Tier, CurrentStanding);
}
