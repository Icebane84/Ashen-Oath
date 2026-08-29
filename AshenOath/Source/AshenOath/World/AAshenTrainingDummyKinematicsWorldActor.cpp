// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenTrainingDummyKinematicsWorldActor.h"

AAshenTrainingDummyKinematicsWorldActor::AAshenTrainingDummyKinematicsWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	MaxPoise = 100.0f;
	CurrentPoise = 100.0f;
}

void AAshenTrainingDummyKinematicsWorldActor::BeginPlay()
{
	Super::BeginPlay();
}
