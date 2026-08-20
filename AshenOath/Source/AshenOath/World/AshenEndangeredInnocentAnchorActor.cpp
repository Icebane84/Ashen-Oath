// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenEndangeredInnocentAnchorActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

AAshenEndangeredInnocentAnchorActor::AAshenEndangeredInnocentAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	DangerRadius = CreateDefaultSubobject<USphereComponent>(TEXT("DangerRadius"));
	DangerRadius->SetupAttachment(RootComponent);
	DangerRadius->SetSphereRadius(500.0f);

	InnocentMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InnocentMesh"));
	InnocentMesh->SetupAttachment(RootComponent);

	bIsActive = true;
}

void AAshenEndangeredInnocentAnchorActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenEndangeredInnocentAnchorActor::TriggerRescueEncounter()
{
	bIsActive = true;
}
