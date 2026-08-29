// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenConductiveRubbleHazardWorldActor.h"

AAshenConductiveRubbleHazardWorldActor::AAshenConductiveRubbleHazardWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	SurfaceType = EConductiveSurfaceType::MetallicIronRubble;
	ConductionRadiusUU = 350.0f;
}

void AAshenConductiveRubbleHazardWorldActor::BeginPlay()
{
	Super::BeginPlay();
}
