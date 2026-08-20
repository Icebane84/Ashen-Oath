// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenConsecratedSanctuaryAltarActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"

AAshenConsecratedSanctuaryAltarActor::AAshenConsecratedSanctuaryAltarActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	SanctuaryPerimeter = CreateDefaultSubobject<USphereComponent>(TEXT("SanctuaryPerimeter"));
	SanctuaryPerimeter->SetupAttachment(RootComponent);
	SanctuaryPerimeter->SetSphereRadius(500.0f);

	AltarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AltarMesh"));
	AltarMesh->SetupAttachment(RootComponent);

	HearthfireAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("HearthfireAudio"));
	HearthfireAudio->SetupAttachment(RootComponent);
	HearthfireAudio->bAutoActivate = true;

	FrictionCoolingRate = 0.15f;
	bIsSessionActive = false;
}

void AAshenConsecratedSanctuaryAltarActor::BeginPlay()
{
	Super::BeginPlay();
}

bool AAshenConsecratedSanctuaryAltarActor::InitiateRestSession()
{
	if (bIsSessionActive)
	{
		return false;
	}
	bIsSessionActive = true;
	return true;
}

void AAshenConsecratedSanctuaryAltarActor::ConcludeRestSession()
{
	bIsSessionActive = false;
}
