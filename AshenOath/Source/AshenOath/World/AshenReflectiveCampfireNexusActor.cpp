// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenReflectiveCampfireNexusActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"

AAshenReflectiveCampfireNexusActor::AAshenReflectiveCampfireNexusActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	ReflectionPerimeter = CreateDefaultSubobject<USphereComponent>(TEXT("ReflectionPerimeter"));
	ReflectionPerimeter->SetupAttachment(RootComponent);
	ReflectionPerimeter->SetSphereRadius(450.0f);

	CampfireMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CampfireMesh"));
	CampfireMesh->SetupAttachment(RootComponent);

	HearthfireAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("HearthfireAudio"));
	HearthfireAudio->SetupAttachment(RootComponent);
	HearthfireAudio->bAutoActivate = true;

	bReflectionInFlight = false;
}

void AAshenReflectiveCampfireNexusActor::BeginPlay()
{
	Super::BeginPlay();
}

bool AAshenReflectiveCampfireNexusActor::InitiateReflectionPass()
{
	if (bReflectionInFlight)
	{
		return false;
	}
	bReflectionInFlight = true;
	return true;
}
