// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenShepherdsGambitSaveGameAdapter.h"

UAshenShepherdsGambitSaveGameAdapter::UAshenShepherdsGambitSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenShepherdsGambitSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenShepherdsGambitSaveGameAdapter::SaveContainmentTelemetry(int32 UnchainedCrisisCount, int32 SunPulsesFired, int32 NeedlesDeployed)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenShepherdsGambitSaveGameAdapter: Saved Containment Telemetry -> %d Crises, %d Sun-Pulses, %d Needles"),
		UnchainedCrisisCount, SunPulsesFired, NeedlesDeployed);
	return true;
}
