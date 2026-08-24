// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenOathbringerBladeWorldActor.h"
#include "Components/StaticMeshComponent.h"

AAshenOathbringerBladeWorldActor::AAshenOathbringerBladeWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	BladeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BladeMesh"));
	BladeMesh->SetupAttachment(RootComponent);

	BladeLengthUU = 180.0f;
}

void AAshenOathbringerBladeWorldActor::BeginPlay()
{
	Super::BeginPlay();
}
