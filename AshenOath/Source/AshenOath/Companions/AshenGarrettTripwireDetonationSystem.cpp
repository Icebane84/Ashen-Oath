// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 697: Ashen Garrett Tripwire Detonation System

#include "AshenGarrettTripwireDetonationSystem.h"

void UAshenGarrettTripwireDetonationSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalTripwiresDetonated = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettTripwireDetonationSystem: Initialized — Garrett Tripwire Detonation System ONLINE."));
}

void UAshenGarrettTripwireDetonationSystem::TriggerTripwireDetonation(FVector Location, float BaseStagger)
{
	TotalTripwiresDetonated++;
	const float ScuffAmount = BaseStagger * 0.15f;
	OnTripwireDetonated.Broadcast(Location, BaseStagger, ScuffAmount);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettTripwireDetonationSystem: TRIPWIRE DETONATED -> Location: (%s) | Stagger: %.1f | Armor Scuff: %.1f (Total: %d)."),
		*Location.ToString(), BaseStagger, ScuffAmount, TotalTripwiresDetonated);
}
