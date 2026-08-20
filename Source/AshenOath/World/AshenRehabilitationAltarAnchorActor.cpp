// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenRehabilitationAltarAnchorActor.h"

AAshenRehabilitationAltarAnchorActor::AAshenRehabilitationAltarAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenRehabilitationAltarAnchorActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenRehabilitationAltarAnchorActor: Rehabilitation Altar Anchor active."));
}

void AAshenRehabilitationAltarAnchorActor::DockOathbringerBlade()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenRehabilitationAltarAnchorActor: Oathbringer blade docked into rehabilitation altar!"));
}
