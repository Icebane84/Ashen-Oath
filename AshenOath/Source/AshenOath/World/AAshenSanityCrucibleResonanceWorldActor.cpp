// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenSanityCrucibleResonanceWorldActor.h"

AAshenSanityCrucibleResonanceWorldActor::AAshenSanityCrucibleResonanceWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	CrucibleRadiusUU = 500.0f;
	SanityPurgeRatePerSec = 15.0f;
}

void AAshenSanityCrucibleResonanceWorldActor::BeginPlay()
{
	Super::BeginPlay();
}
