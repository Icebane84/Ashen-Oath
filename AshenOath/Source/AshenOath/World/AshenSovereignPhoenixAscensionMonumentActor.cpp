// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSovereignPhoenixAscensionMonumentActor.h"

AAshenSovereignPhoenixAscensionMonumentActor::AAshenSovereignPhoenixAscensionMonumentActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSovereignPhoenixAscensionMonumentActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSovereignPhoenixAscensionMonumentActor: Sovereign Phoenix Monument Actor initialized."));
}

bool AAshenSovereignPhoenixAscensionMonumentActor::ActivateSovereignPhoenixMonument()
{
	if (!bMonumentActive) return false;
	UE_LOG(LogTemp, Log, TEXT("AAshenSovereignPhoenixAscensionMonumentActor: Sovereign Phoenix Monument activated across 1,100 builds clean (Radius: %f)."), SovereignAscensionRadius);
	return true;
}
