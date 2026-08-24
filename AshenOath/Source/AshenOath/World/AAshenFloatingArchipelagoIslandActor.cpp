// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenFloatingArchipelagoIslandActor.h"
#include "Components/BoxComponent.h"

AAshenFloatingArchipelagoIslandActor::AAshenFloatingArchipelagoIslandActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	IslandBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("IslandBounds"));
	IslandBounds->SetupAttachment(RootComponent);
	IslandBounds->SetBoxExtent(FVector(1200.0f, 1200.0f, 400.0f));

	IslandAltitudeUU = 8500.0f;
}

void AAshenFloatingArchipelagoIslandActor::BeginPlay()
{
	Super::BeginPlay();
}
