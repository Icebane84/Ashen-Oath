// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenBossArenaChaosPillarActor.h"
#include "Components/StaticMeshComponent.h"

AAshenBossArenaChaosPillarActor::AAshenBossArenaChaosPillarActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	PillarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PillarMesh"));
	PillarMesh->SetupAttachment(RootComponent);
	PillarMesh->SetCollisionProfileName(TEXT("BlockAll"));

	bIsSundered = false;
}

void AAshenBossArenaChaosPillarActor::BeginPlay()
{
	Super::BeginPlay();
	bIsSundered = false;
}

void AAshenBossArenaChaosPillarActor::FracturePillar(const FVector& ImpactPoint)
{
	bIsSundered = true;
	if (PillarMesh)
	{
		PillarMesh->SetSimulatePhysics(true);
	}
}
