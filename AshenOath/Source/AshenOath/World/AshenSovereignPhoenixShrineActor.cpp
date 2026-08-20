// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSovereignPhoenixShrineActor.h"

AAshenSovereignPhoenixShrineActor::AAshenSovereignPhoenixShrineActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSovereignPhoenixShrineActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSovereignPhoenixShrineActor: Sovereign Phoenix Shrine Actor initialized."));
}

bool AAshenSovereignPhoenixShrineActor::InitiateSovereignPhoenixRest(AActor* InstigatorActor)
{
	if (!InstigatorActor || !bShrineActive) return false;
	UE_LOG(LogTemp, Log, TEXT("AAshenSovereignPhoenixShrineActor: Sovereign Phoenix rest initiated for instigator %s"), *InstigatorActor->GetName());
	return true;
}
