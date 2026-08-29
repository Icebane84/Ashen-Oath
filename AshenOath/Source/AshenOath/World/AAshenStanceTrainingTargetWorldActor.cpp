// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenStanceTrainingTargetWorldActor.h"

AAshenStanceTrainingTargetWorldActor::AAshenStanceTrainingTargetWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	TotalHitsReceived = 0;
}

void AAshenStanceTrainingTargetWorldActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenStanceTrainingTargetWorldActor::RegisterStanceHit(
	EOathbringerMartialStance Stance,
	float Damage,
	float PoiseDamage)
{
	TotalHitsReceived++;
}
