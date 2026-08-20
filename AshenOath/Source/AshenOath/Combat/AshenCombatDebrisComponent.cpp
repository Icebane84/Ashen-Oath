// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 592: Ashen Combat Debris Component

#include "AshenCombatDebrisComponent.h"

UAshenCombatDebrisComponent::UAshenCombatDebrisComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalDebrisSpawned = 0;
}

void UAshenCombatDebrisComponent::SpawnCombatDebris(FVector ImpactLocation, float Scale)
{
	TotalDebrisSpawned++;
	OnDebrisSpawned.Broadcast(ImpactLocation, Scale);

	UE_LOG(LogTemp, Log, TEXT("UAshenCombatDebrisComponent: COMBAT DEBRIS SPAWNED at (%s) — Scale: %.1f (Total: %d)."),
		*ImpactLocation.ToString(), Scale, TotalDebrisSpawned);
}
