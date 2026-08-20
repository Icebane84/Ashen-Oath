// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 577: Ashen Sanctuary Blessing Registry Subsystem

#include "AshenSanctuaryBlessingRegistrySubsystem.h"

void UAshenSanctuaryBlessingRegistrySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveBlessings.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryBlessingRegistrySubsystem: Initialized — Sanctuary Blessing Registry ONLINE."));
}

void UAshenSanctuaryBlessingRegistrySubsystem::RegisterSanctuaryBlessing(FName BlessingID, float StatBonusPercent)
{
	if (BlessingID.IsNone()) return;

	ActiveBlessings.AddUnique(BlessingID);
	OnBlessingRegistered.Broadcast(BlessingID, StatBonusPercent);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuaryBlessingRegistrySubsystem: SANCTUARY BLESSING REGISTERED -> '%s' (+%.1f%% Stat Bonus | Total: %d)."),
		*BlessingID.ToString(), StatBonusPercent, ActiveBlessings.Num());
}
