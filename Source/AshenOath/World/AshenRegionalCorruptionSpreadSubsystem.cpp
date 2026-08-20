// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenRegionalCorruptionSpreadSubsystem.h"

void UAshenRegionalCorruptionSpreadSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	SectorCorruptionLevels.Init(0.0f, 64);
	ZoneCorruptionMap.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenRegionalCorruptionSpreadSubsystem: Regional Corruption Subsystem initialized with 64 sectors."));
}

void UAshenRegionalCorruptionSpreadSubsystem::PropagateRegionalCorruption(int32 SourceSector, float Intensity)
{
	if (SectorCorruptionLevels.IsValidIndex(SourceSector))
	{
		SectorCorruptionLevels[SourceSector] = FMath::Clamp(SectorCorruptionLevels[SourceSector] + Intensity, 0.0f, 100.0f);
		if (OnRegionalCorruptionUpdated.IsBound())
		{
			OnRegionalCorruptionUpdated.Broadcast(SourceSector, SectorCorruptionLevels[SourceSector]);
		}
		UE_LOG(LogTemp, Warning, TEXT("UAshenRegionalCorruptionSpreadSubsystem: Sector %d corruption increased to %.1f%%"),
			SourceSector, SectorCorruptionLevels[SourceSector]);
	}
}

float UAshenRegionalCorruptionSpreadSubsystem::GetSectorCorruption(int32 SectorIndex) const
{
	if (SectorCorruptionLevels.IsValidIndex(SectorIndex))
	{
		return SectorCorruptionLevels[SectorIndex];
	}
	return 0.0f;
}

void UAshenRegionalCorruptionSpreadSubsystem::AdvanceZoneCorruption(FName ZoneID, float DeltaAmount)
{
	const float CurrentLevel = ZoneCorruptionMap.FindRef(ZoneID);
	const float NewLevel = FMath::Clamp(CurrentLevel + DeltaAmount, 0.0f, 100.0f);
	ZoneCorruptionMap.Add(ZoneID, NewLevel);

	if (OnZoneCorruptionChanged.IsBound())
	{
		OnZoneCorruptionChanged.Broadcast(ZoneID, NewLevel);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenRegionalCorruptionSpreadSubsystem: Zone %s corruption advanced to %.1f"), *ZoneID.ToString(), NewLevel);
}

float UAshenRegionalCorruptionSpreadSubsystem::GetZoneCorruptionLevel(FName ZoneID) const
{
	return ZoneCorruptionMap.FindRef(ZoneID);
}
