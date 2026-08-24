// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenMagmaVentCrucibleActor.h"
#include "Components/SphereComponent.h"

AAshenMagmaVentCrucibleActor::AAshenMagmaVentCrucibleActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	CrucibleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CrucibleMesh"));
	CrucibleMesh->SetupAttachment(RootComponent);

	TemperingInteractRadius = CreateDefaultSubobject<USphereComponent>(TEXT("TemperingInteractRadius"));
	TemperingInteractRadius->SetupAttachment(RootComponent);
	TemperingInteractRadius->SetSphereRadius(250.0f);

	CurrentPhase = ECalderaSurgePhase::DormantCalm;
}

void AAshenMagmaVentCrucibleActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenMagmaVentCrucibleActor::ChannelWeaponTempering()
{
	// In production, initiates weapon dipping animation and particle flare
}
