// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 811: Ashen Chilling Silence Vacuum Audio Volume

#include "AshenChillingSilenceVacuumAudioVolume.h"

AAshenChillingSilenceVacuumAudioVolume::AAshenChillingSilenceVacuumAudioVolume()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsVacuumActive = false;
}

void AAshenChillingSilenceVacuumAudioVolume::TriggerChillingSilenceVacuum(bool bEnableVacuum)
{
	bIsVacuumActive = bEnableVacuum;
	const float VacVol = bIsVacuumActive ? 0.0f : 1.0f; // Total silence
	const float HeartbeatPitch = bIsVacuumActive ? 0.8f : 1.0f;

	OnVacuumAudioTriggered.Broadcast(VacVol, HeartbeatPitch);

	UE_LOG(LogTemp, Warning, TEXT("AAshenChillingSilenceVacuumAudioVolume: ACOUSTIC VACUUM TRIGGERED -> Active: %s | Ambient Vol: %.1f | Heartbeat Pitch: %.2fx."),
		bIsVacuumActive ? TEXT("TRUE (0dB Ambient)") : TEXT("FALSE"), VacVol, HeartbeatPitch);
}
