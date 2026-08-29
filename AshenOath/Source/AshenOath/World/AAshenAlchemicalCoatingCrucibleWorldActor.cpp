// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenAlchemicalCoatingCrucibleWorldActor.h"

AAshenAlchemicalCoatingCrucibleWorldActor::AAshenAlchemicalCoatingCrucibleWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	TotalFlasksBrewed = 0;
}

void AAshenAlchemicalCoatingCrucibleWorldActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenAlchemicalCoatingCrucibleWorldActor::BrewFlask(
	EAlchemicalBladeCoating Coating,
	int32 Quantity)
{
	TotalFlasksBrewed += Quantity;
}
