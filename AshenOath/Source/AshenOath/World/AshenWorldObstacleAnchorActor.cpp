// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenWorldObstacleAnchorActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

AAshenWorldObstacleAnchorActor::AAshenWorldObstacleAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	InteractionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionRadius"));
	InteractionRadius->SetupAttachment(RootComponent);
	InteractionRadius->SetSphereRadius(250.0f);

	RubbleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RubbleMesh"));
	RubbleMesh->SetupAttachment(RootComponent);

	bTrapsCivilian = true;
	bIsCleared = false;
}

void AAshenWorldObstacleAnchorActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenWorldObstacleAnchorActor::ClearObstacle()
{
	bIsCleared = true;
	if (RubbleMesh)
	{
		RubbleMesh->SetVisibility(false);
		RubbleMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}
