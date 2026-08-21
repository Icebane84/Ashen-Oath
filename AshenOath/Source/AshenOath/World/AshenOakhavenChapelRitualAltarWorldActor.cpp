// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenOakhavenChapelRitualAltarWorldActor.h"
#include "Components/StaticMeshComponent.h"

AAshenOakhavenChapelRitualAltarWorldActor::AAshenOakhavenChapelRitualAltarWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	AltarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AltarMesh"));
	AltarMesh->SetupAttachment(RootComponent);
	AltarMesh->SetCollisionProfileName(TEXT("BlockAll"));

	AmberBrazierMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AmberBrazierMesh"));
	AmberBrazierMesh->SetupAttachment(AltarMesh);
	AmberBrazierMesh->SetCollisionProfileName(TEXT("NoCollision"));

	bRitualActive = false;
}

void AAshenOakhavenChapelRitualAltarWorldActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenOakhavenChapelRitualAltarWorldActor::InitiateRitual()
{
	bRitualActive = true;
}

void AAshenOakhavenChapelRitualAltarWorldActor::BreakRitual()
{
	bRitualActive = false;
}
