// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenMapCompassLocusActor.h"

AAshenMapCompassLocusActor::AAshenMapCompassLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenMapCompassLocusActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenMapCompassLocusActor: Map Compass Locus Actor initialized."));
}

FVector2D AAshenMapCompassLocusActor::GetNormalizedMapCoordinates() const
{
	FVector Loc = GetActorLocation();
	return FVector2D(Loc.X / 100000.0f, Loc.Y / 100000.0f);
}
