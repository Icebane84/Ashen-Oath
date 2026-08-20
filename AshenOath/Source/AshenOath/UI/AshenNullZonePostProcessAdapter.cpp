// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenNullZonePostProcessAdapter.h"

UAshenNullZonePostProcessAdapter::UAshenNullZonePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNullZonePostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenNullZonePostProcessAdapter::UpdateNullZonePostProcess(float ProximityRatio)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenNullZonePostProcessAdapter: Updated Null Zone MPC_NullZoneProximity to %.2f."), ProximityRatio);
}
