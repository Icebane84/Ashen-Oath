// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenStarStriderAnomalyActor.h"

AAshenStarStriderAnomalyActor::AAshenStarStriderAnomalyActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bPathwayOfLightFormed = false;
}
void AAshenStarStriderAnomalyActor::BeginPlay() { Super::BeginPlay(); }

void AAshenStarStriderAnomalyActor::FormPathwayOfLight()
{
	bPathwayOfLightFormed = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenStarStriderAnomalyActor: STAR-STRIDER MANIFESTED! Luminous Pathway of Light formed over abyss!"));
}
