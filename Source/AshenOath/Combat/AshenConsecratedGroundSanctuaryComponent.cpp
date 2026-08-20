// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 594: Ashen Consecrated Ground Sanctuary Component

#include "AshenConsecratedGroundSanctuaryComponent.h"

UAshenConsecratedGroundSanctuaryComponent::UAshenConsecratedGroundSanctuaryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsGroundActive = false;
}

void UAshenConsecratedGroundSanctuaryComponent::SpawnConsecratedGroundPool(FVector GroundCenter, float HealPerSecond)
{
	bIsGroundActive = true;
	OnGroundActive.Broadcast(GroundCenter, HealPerSecond);

	UE_LOG(LogTemp, Warning, TEXT("UAshenConsecratedGroundSanctuaryComponent: CONSECRATED GROUND POOL SPAWNED at (%s) — Heal/s: +%.1f HP."),
		*GroundCenter.ToString(), HealPerSecond);
}
