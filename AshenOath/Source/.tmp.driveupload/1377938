// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 449: Ashen Sanctuary Crucible Upgrade Subsystem

#include "AshenSanctuaryCrucibleUpgradeSubsystem.h"

void UAshenSanctuaryCrucibleUpgradeSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentCrucibleTier = 1;
	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryCrucibleUpgradeSubsystem: Initialized — Heartstone Crucible Upgrade Engine ONLINE."));
}

bool UAshenSanctuaryCrucibleUpgradeSubsystem::UpgradeCrucibleTier()
{
	if (CurrentCrucibleTier >= 5) return false;

	CurrentCrucibleTier++;
	const float GlobalMult = 1.0f + (CurrentCrucibleTier * 0.10f);

	OnCrucibleTierReached.Broadcast(CurrentCrucibleTier, GlobalMult);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuaryCrucibleUpgradeSubsystem: CRUCIBLE TIER UPGRADED -> Tier %d (Global Multiplier: %.2fx)."),
		CurrentCrucibleTier, GlobalMult);

	return true;
}
