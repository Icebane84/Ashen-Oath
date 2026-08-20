// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenCampfireJournalCommunionActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"

AAshenCampfireJournalCommunionActor::AAshenCampfireJournalCommunionActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	InteractionPerimeter = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionPerimeter"));
	InteractionPerimeter->SetupAttachment(RootComponent);
	InteractionPerimeter->SetSphereRadius(350.0f);

	JournalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("JournalMesh"));
	JournalMesh->SetupAttachment(RootComponent);

	AmbientCampfireAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("AmbientCampfireAudio"));
	AmbientCampfireAudio->SetupAttachment(RootComponent);
	AmbientCampfireAudio->bAutoActivate = true;

	bIsCommunionOpen = false;
}

void AAshenCampfireJournalCommunionActor::BeginPlay()
{
	Super::BeginPlay();
}

bool AAshenCampfireJournalCommunionActor::OpenJournalCommunion()
{
	if (bIsCommunionOpen)
	{
		return false;
	}
	bIsCommunionOpen = true;
	return true;
}

void AAshenCampfireJournalCommunionActor::CloseJournalCommunion()
{
	bIsCommunionOpen = false;
}
