// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 723: Ashen Sacred Ground Sanctuary Zone Actor

#include "AshenSacredGroundSanctuaryZoneActor.h"

AAshenSacredGroundSanctuaryZoneActor::AAshenSacredGroundSanctuaryZoneActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsZoneActive = true;
}

void AAshenSacredGroundSanctuaryZoneActor::TriggerSanctuaryPulse(float HealAmount)
{
	if (!bIsZoneActive) return;

	OnSanctuaryPulse.Broadcast(GetActorLocation(), HealAmount);

	UE_LOG(LogTemp, Warning, TEXT("AAshenSacredGroundSanctuaryZoneActor: SACRED GROUND PULSE TRIGGERED -> Center: (%s) | Heal Amount: +%.1f HP."),
		*GetActorLocation().ToString(), HealAmount);
}
