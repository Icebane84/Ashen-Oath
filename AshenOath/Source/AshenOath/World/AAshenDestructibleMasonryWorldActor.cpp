// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenDestructibleMasonryWorldActor.h"

AAshenDestructibleMasonryWorldActor::AAshenDestructibleMasonryWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	StructureDurability = 1000.0f;
}

void AAshenDestructibleMasonryWorldActor::BeginPlay()
{
	Super::BeginPlay();
}
