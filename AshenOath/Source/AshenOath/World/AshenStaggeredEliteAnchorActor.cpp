// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenStaggeredEliteAnchorActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

AAshenStaggeredEliteAnchorActor::AAshenStaggeredEliteAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	InteractionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionRadius"));
	InteractionRadius->SetupAttachment(RootComponent);
	InteractionRadius->SetSphereRadius(300.0f);

	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
	EnemyMesh->SetupAttachment(RootComponent);

	bIsHumanoid = true;
	ThreatRating = 0.75f;
	bAwaitingResolution = true;
}

void AAshenStaggeredEliteAnchorActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenStaggeredEliteAnchorActor::ResolveStagger(EFoeStaggerResolutionChoice Choice)
{
	bAwaitingResolution = false;
}
