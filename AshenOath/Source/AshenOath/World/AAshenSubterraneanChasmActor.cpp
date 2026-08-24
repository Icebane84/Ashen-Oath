// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenSubterraneanChasmActor.h"
#include "Components/BoxComponent.h"

AAshenSubterraneanChasmActor::AAshenSubterraneanChasmActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	ChasmBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("ChasmBounds"));
	ChasmBounds->SetupAttachment(RootComponent);
	ChasmBounds->SetBoxExtent(FVector(500.0f, 300.0f, 100.0f));

	ChasmDropDepthUU = 2500.0f;
}

void AAshenSubterraneanChasmActor::BeginPlay()
{
	Super::BeginPlay();
}
