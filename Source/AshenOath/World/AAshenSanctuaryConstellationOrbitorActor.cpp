// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AAshenSanctuaryConstellationOrbitorActor.h"

AAshenSanctuaryConstellationOrbitorActor::AAshenSanctuaryConstellationOrbitorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSanctuaryConstellationOrbitorActor::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	OrbiterVelocityMultiplier = 1.0f + (NewState.Resolve * 2.0f);
	UE_LOG(LogTemp, Log, TEXT("AAshenSanctuaryConstellationOrbitorActor: Sanctuary constellation orbiter velocity multiplier set to %.2f"), OrbiterVelocityMultiplier);
}
