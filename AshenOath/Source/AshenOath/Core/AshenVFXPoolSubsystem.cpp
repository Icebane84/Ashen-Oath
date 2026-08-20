// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenVFXPoolSubsystem.h"

void UAshenVFXPoolSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Warning, TEXT("UAshenVFXPoolSubsystem: Particle VFX pooling manager initialized."));
}

void UAshenVFXPoolSubsystem::Deinitialize()
{
	ActivePoolCounts.Empty();
	Super::Deinitialize();
}

void UAshenVFXPoolSubsystem::SpawnPooledVFX(FName EffectName, FVector Location, FRotator Rotation)
{
	if (EffectName.IsNone()) return;

	int32& Count = ActivePoolCounts.FindOrAdd(EffectName);
	Count++;

	OnVFXSpawnedFromPool.Broadcast(EffectName, Location, Rotation);
	UE_LOG(LogTemp, Verbose, TEXT("UAshenVFXPoolSubsystem: Spawned pooled effect '%s' at %s (Total spawned: %d)"),
		*EffectName.ToString(), *Location.ToString(), Count);
}
