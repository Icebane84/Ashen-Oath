// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenEldrinFallenPaladinActor.h"

AAshenEldrinFallenPaladinActor::AAshenEldrinFallenPaladinActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenEldrinFallenPaladinActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenEldrinFallenPaladinActor: Eldrin Fallen Paladin Actor initialized in Inner World."));
}

bool AAshenEldrinFallenPaladinActor::ManifestEldrinGraceProjection()
{
	UE_LOG(LogTemp, Log, TEXT("AAshenEldrinFallenPaladinActor: Manifested Eldrin's Grace silver rune aura projection."));
	return true;
}
