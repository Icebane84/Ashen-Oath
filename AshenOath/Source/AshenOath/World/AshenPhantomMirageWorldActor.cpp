// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenPhantomMirageWorldActor.h"
#include "Components/StaticMeshComponent.h"

AAshenPhantomMirageWorldActor::AAshenPhantomMirageWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	MirageMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MirageMesh"));
	MirageMesh->SetupAttachment(RootComponent);
	MirageMesh->SetCollisionProfileName(TEXT("NoCollision"));

	bIsRealPhysicalThreat = false;
	bDispersed = false;
}

void AAshenPhantomMirageWorldActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenPhantomMirageWorldActor::DisperseMirage()
{
	bDispersed = true;
	SetActorHiddenInGame(true);
}
