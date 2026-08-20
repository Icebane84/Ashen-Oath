// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 328: Ashen Fugitives Network Hostility Subsystem

#include "AshenFugitivesNetworkHostilitySubsystem.h"

void UAshenFugitivesNetworkHostilitySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	RegionalHostilityLevels.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenFugitivesNetworkHostilitySubsystem: Initialized — Fugitive Network Subsystem active."));
}

void UAshenFugitivesNetworkHostilitySubsystem::ModifyRegionalHostility(FName RegionID, float HostilityDelta)
{
	if (RegionID.IsNone()) return;

	float Current = RegionalHostilityLevels.Contains(RegionID) ? RegionalHostilityLevels[RegionID] : 0.0f;
	Current = FMath::Clamp(Current + HostilityDelta, 0.0f, 100.0f);
	RegionalHostilityLevels.Add(RegionID, Current);

	OnHostilityLevelChanged.Broadcast(RegionID, Current);

	UE_LOG(LogTemp, Warning, TEXT("UAshenFugitivesNetworkHostilitySubsystem: ORDER HOSTILITY IN '%s' MODIFIED (%+.1f) -> Total: %.1f%%."),
		*RegionID.ToString(), HostilityDelta, Current);
}

float UAshenFugitivesNetworkHostilitySubsystem::GetRegionalHostility(FName RegionID) const
{
	return RegionalHostilityLevels.Contains(RegionID) ? RegionalHostilityLevels[RegionID] : 0.0f;
}
