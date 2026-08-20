// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 789: Ashen Weapon Forge Spark Visual Locus Actor

#include "AshenWeaponForgeSparkVisualLocusActor.h"

AAshenWeaponForgeSparkVisualLocusActor::AAshenWeaponForgeSparkVisualLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsSparksActive = false;
}

void AAshenWeaponForgeSparkVisualLocusActor::TriggerForgeSparkBurst(float Intensity)
{
	bIsSparksActive = true;
	OnForgeSparksTriggered.Broadcast(GetActorLocation(), Intensity);

	UE_LOG(LogTemp, Warning, TEXT("AAshenWeaponForgeSparkVisualLocusActor: FORGE SPARKS TRIGGERED -> Location: (%s) | Intensity: %.2fx."),
		*GetActorLocation().ToString(), Intensity);
}
