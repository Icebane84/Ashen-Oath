// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenEmpathicResonanceAnchorActor.h"

AAshenEmpathicResonanceAnchorActor::AAshenEmpathicResonanceAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
	StasisRadius = 800.0f;
	bIsStasisLocked = false;
}
void AAshenEmpathicResonanceAnchorActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenEmpathicResonanceAnchorActor::LockEnemiesInStasis(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsStasisLocked = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenEmpathicResonanceAnchorActor: Locked surrounding enemies in Resonant Stasis (Radius: %.1fuu)!"),
		StasisRadius);
	return true;
}
