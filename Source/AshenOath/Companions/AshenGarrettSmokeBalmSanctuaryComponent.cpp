// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 696: Ashen Garrett Smoke Balm Sanctuary Component

#include "AshenGarrettSmokeBalmSanctuaryComponent.h"

UAshenGarrettSmokeBalmSanctuaryComponent::UAshenGarrettSmokeBalmSanctuaryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalSmokeBalmsDeployed = 0;
}

void UAshenGarrettSmokeBalmSanctuaryComponent::DeploySmokeBalmSanctuary(FVector TargetLocation, float CloudRadius)
{
	TotalSmokeBalmsDeployed++;
	OnSmokeBalmDeployed.Broadcast(TargetLocation, CloudRadius);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettSmokeBalmSanctuaryComponent: SMOKE BALM SANCTUARY DEPLOYED -> Location: (%s) | Radius: %.0f (Total Deployed: %d)."),
		*TargetLocation.ToString(), CloudRadius, TotalSmokeBalmsDeployed);
}
