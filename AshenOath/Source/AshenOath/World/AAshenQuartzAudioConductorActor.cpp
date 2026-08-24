// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenQuartzAudioConductorActor.h"

AAshenQuartzAudioConductorActor::AAshenQuartzAudioConductorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	ConductorBPM = 115.0f;
}

void AAshenQuartzAudioConductorActor::BeginPlay()
{
	Super::BeginPlay();
}
