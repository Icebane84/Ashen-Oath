// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenTripartiteFinisherAnchorActor.h"
#include "Components/SphereComponent.h"

AAshenTripartiteFinisherAnchorActor::AAshenTripartiteFinisherAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	FinisherRadius = CreateDefaultSubobject<USphereComponent>(TEXT("FinisherRadius"));
	FinisherRadius->SetupAttachment(RootComponent);
	FinisherRadius->SetSphereRadius(500.0f);

	bStagingActive = false;
}

void AAshenTripartiteFinisherAnchorActor::BeginPlay()
{
	Super::BeginPlay();
	bStagingActive = false;
}

void AAshenTripartiteFinisherAnchorActor::TriggerFinisherStaging(AActor* TargetActor)
{
	bStagingActive = true;
}
