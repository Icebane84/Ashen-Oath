// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenPurificationShrineActor.h"

AAshenPurificationShrineActor::AAshenPurificationShrineActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenPurificationShrineActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenPurificationShrineActor: Purification Shrine initialized."));
}

bool AAshenPurificationShrineActor::PerformPurificationRitual(AActor* InstigatorActor)
{
	if (!InstigatorActor || !bShrineConsecrated) return false;
	UE_LOG(LogTemp, Log, TEXT("AAshenPurificationShrineActor: Purification ritual performed for instigator %s"), *InstigatorActor->GetName());
	return true;
}
