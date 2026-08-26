// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenCampfireCookingPotWorldActor.h"

AAshenCampfireCookingPotWorldActor::AAshenCampfireCookingPotWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	PotCapacityLiters = 8.0f;
}

void AAshenCampfireCookingPotWorldActor::BeginPlay()
{
	Super::BeginPlay();
}
