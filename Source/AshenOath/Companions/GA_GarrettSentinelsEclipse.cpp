// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/GA_GarrettSentinelsEclipse.h"

UGA_GarrettSentinelsEclipse::UGA_GarrettSentinelsEclipse()
{
	MaxGrappleRange = 1000.0f;
	WarpLungeSpeed = 1600.0f;
	ThreatGenerationMultiplier = 4.0f;
	FlankingDamageMultiplier = 2.5f;
}

bool UGA_GarrettSentinelsEclipse::ExecuteSentinelVault(AActor* GarrettActor, AActor* TargetEnemy)
{
	if (!GarrettActor || !TargetEnemy) return false;

	UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettSentinelsEclipse: THE SENTINEL'S ECLIPSE! Garrett vaulted behind %s, baiting 4.0x threat and exposing 2.5x Flank Weakspot."),
		*TargetEnemy->GetName());
	return true;
}
