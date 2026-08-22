// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenMireMudSludgeVolumeActor.h"
#include "Components/BoxComponent.h"

AAshenMireMudSludgeVolumeActor::AAshenMireMudSludgeVolumeActor()
{
	PrimaryActorTick.bCanEverTick = false;

	VolumeBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("VolumeBounds"));
	RootComponent = VolumeBounds;
	VolumeBounds->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	MudFrictionCoefficient = 0.50f;
}

void AAshenMireMudSludgeVolumeActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenMireMudSludgeVolumeActor::SetMudFriction(float NewFriction)
{
	MudFrictionCoefficient = FMath::Clamp(NewFriction, 0.10f, 1.0f);
}
