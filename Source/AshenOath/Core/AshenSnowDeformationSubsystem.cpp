// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenSnowDeformationSubsystem.h"

void UAshenSnowDeformationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	RegisteredFootprints.Empty();
	UE_LOG(LogTemp, Warning, TEXT("UAshenSnowDeformationSubsystem: Dynamic snow surface deformation subsystem initialized."));
}

void UAshenSnowDeformationSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UAshenSnowDeformationSubsystem::RegisterFootprintDeformation(FVector WorldLocation, float FootprintRadius)
{
	RegisteredFootprints.Add(WorldLocation);

	// Cap buffer size at 256 footprints to maintain performance
	if (RegisteredFootprints.Num() > 256)
	{
		RegisteredFootprints.RemoveAt(0);
	}

	OnFootprintRegistered.Broadcast(WorldLocation, FootprintRadius);
}
