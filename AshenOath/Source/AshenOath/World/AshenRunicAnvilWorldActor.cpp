// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenRunicAnvilWorldActor.h"
#include "Components/StaticMeshComponent.h"

AAshenRunicAnvilWorldActor::AAshenRunicAnvilWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	AnvilMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AnvilMesh"));
	AnvilMesh->SetupAttachment(RootComponent);
	AnvilMesh->SetCollisionProfileName(TEXT("BlockAll"));

	bAnvilActive = true;
}

void AAshenRunicAnvilWorldActor::BeginPlay()
{
	Super::BeginPlay();
	bAnvilActive = true;
}

void AAshenRunicAnvilWorldActor::TriggerForgeStrike()
{
	bAnvilActive = true;
}
