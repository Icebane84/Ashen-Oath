// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenAshenAbominationBossActor.h"

AAshenAshenAbominationBossActor::AAshenAshenAbominationBossActor()
{
	PrimaryActorTick.bCanEverTick = false;
	MaxStaggerThreshold = 1500.0f;
	bIsDorsalVentExposed = false;
}
void AAshenAshenAbominationBossActor::BeginPlay() { Super::BeginPlay(); }

void AAshenAshenAbominationBossActor::ExposeDorsalVent()
{
	bIsDorsalVentExposed = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenAshenAbominationBossActor: DORSAL VENT EXPOSED! Vulnerable to Cryo-Quench Finisher!"));
}
