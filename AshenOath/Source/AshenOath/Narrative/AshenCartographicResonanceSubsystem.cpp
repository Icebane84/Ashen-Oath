// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenCartographicResonanceSubsystem.h"

void UAshenCartographicResonanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveMapPins.Empty();
	DiscoveredRegions.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenCartographicResonanceSubsystem: Cartographic Resonance Subsystem Initialized."));
}
void UAshenCartographicResonanceSubsystem::Deinitialize() { Super::Deinitialize(); }

bool UAshenCartographicResonanceSubsystem::RegisterMapPin(const FJournalMapPin& NewPin)
{
	ActiveMapPins.Add(NewPin);
	UE_LOG(LogTemp, Warning, TEXT("UAshenCartographicResonanceSubsystem: REGISTERED MAP PIN: %s at %s (Type: %d)!"),
		*NewPin.PinLabel, *NewPin.WorldLocation.ToString(), static_cast<int32>(NewPin.PinType));
	return true;
}

void UAshenCartographicResonanceSubsystem::UpdateRegionInking(FName RegionName, float DeltaExploration)
{
	FCartographicRegionData& Data = DiscoveredRegions.FindOrAdd(RegionName);
	Data.RegionName = RegionName;
	Data.ExplorationPercentage = FMath::Clamp(Data.ExplorationPercentage + DeltaExploration, 0.0f, 1.0f);
	Data.bIsFullyInked = (Data.ExplorationPercentage >= 1.0f);

	UE_LOG(LogTemp, Log, TEXT("UAshenCartographicResonanceSubsystem: Region [%s] Inking Progress: %.1f%% (Fully Inked: %s)"),
		*RegionName.ToString(), Data.ExplorationPercentage * 100.0f, Data.bIsFullyInked ? TEXT("YES") : TEXT("NO"));
}
