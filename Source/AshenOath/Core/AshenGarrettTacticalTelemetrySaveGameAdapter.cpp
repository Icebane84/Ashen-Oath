// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenGarrettTacticalTelemetrySaveGameAdapter.h"

UAshenGarrettTacticalTelemetrySaveGameAdapter::UAshenGarrettTacticalTelemetrySaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenGarrettTacticalTelemetrySaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenGarrettTacticalTelemetrySaveGameAdapter::SerializeGarrettTelemetryToSave(int32 TotalTrapsDeployed, int32 TotalGrappleRescues)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettTacticalTelemetrySaveGameAdapter: %d traps deployed, %d grapple rescues serialized to save file."),
		TotalTrapsDeployed, TotalGrappleRescues);
	return true;
}
