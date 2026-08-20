// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 336: Ashen Shattered Virtue System Subsystem

#include "AshenShatteredVirtueSystemSubsystem.h"

void UAshenShatteredVirtueSystemSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveFractures.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenShatteredVirtueSystemSubsystem: Initialized — Shattered Virtue System active."));
}

void UAshenShatteredVirtueSystemSubsystem::InflictVirtueFracture(FName FractureID)
{
	if (FractureID.IsNone()) return;

	ActiveFractures.Add(FractureID);
	OnVirtueFractureChanged.Broadcast(FractureID, true);

	UE_LOG(LogTemp, Warning, TEXT("UAshenShatteredVirtueSystemSubsystem: VIRTUE FRACTURE INFLICTED — '%s' (Redemption Quest unlocked)."),
		*FractureID.ToString());
}

void UAshenShatteredVirtueSystemSubsystem::HealVirtueFractureViaRedemption(FName FractureID)
{
	if (ActiveFractures.Contains(FractureID))
	{
		ActiveFractures.Remove(FractureID);
		OnVirtueFractureChanged.Broadcast(FractureID, false);

		UE_LOG(LogTemp, Warning, TEXT("UAshenShatteredVirtueSystemSubsystem: VIRTUE FRACTURE HEALED — '%s' (Redemption Quest Complete)."),
			*FractureID.ToString());
	}
}
