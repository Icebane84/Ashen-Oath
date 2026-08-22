// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenVolatileGasPocketWorldActor.h"
#include "Components/SphereComponent.h"

AAshenVolatileGasPocketWorldActor::AAshenVolatileGasPocketWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	TriggerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerSphere"));
	TriggerSphere->SetupAttachment(RootComponent);
	TriggerSphere->SetSphereRadius(450.0f);
	TriggerSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	BlastDamage = 250.0f;
	BlastRadiusCentimeters = 450.0f;
	bHasDetonated = false;
}

void AAshenVolatileGasPocketWorldActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenVolatileGasPocketWorldActor::DetonateGasPocket(float BlastRadius)
{
	if (bHasDetonated)
	{
		return;
	}

	bHasDetonated = true;
	BlastRadiusCentimeters = BlastRadius;
	SetActorHiddenInGame(true);
}
