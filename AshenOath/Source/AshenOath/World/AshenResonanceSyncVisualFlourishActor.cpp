// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenResonanceSyncVisualFlourishActor.h"

AAshenResonanceSyncVisualFlourishActor::AAshenResonanceSyncVisualFlourishActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenResonanceSyncVisualFlourishActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenResonanceSyncVisualFlourishActor: Visual flourish actor initialized."));
}

void AAshenResonanceSyncVisualFlourishActor::TriggerResonanceSyncFlourish()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenResonanceSyncVisualFlourishActor: ResonanceSync flourish triggered — Oathbringer golden embers active for 15s!"));
}
