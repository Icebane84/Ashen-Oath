// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenTacticalTargetMarkerWorldActor.h"
#include "Components/StaticMeshComponent.h"

AAshenTacticalTargetMarkerWorldActor::AAshenTacticalTargetMarkerWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	ReticleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReticleMesh"));
	ReticleMesh->SetupAttachment(RootComponent);
	ReticleMesh->SetCollisionProfileName(TEXT("NoCollision"));

	bIsVisible = true;
}

void AAshenTacticalTargetMarkerWorldActor::BeginPlay()
{
	Super::BeginPlay();
	bIsVisible = true;
}

void AAshenTacticalTargetMarkerWorldActor::SetCommandStyle(ETacticalCommandType CommandType)
{
	bIsVisible = (CommandType != ETacticalCommandType::None);
}
