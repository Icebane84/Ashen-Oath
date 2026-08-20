// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenMemoryImprintAnchorActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"

AAshenMemoryImprintAnchorActor::AAshenMemoryImprintAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
	InteractionSphere->SetupAttachment(RootComponent);
	InteractionSphere->SetSphereRadius(200.0f);

	AnchorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AnchorMesh"));
	AnchorMesh->SetupAttachment(RootComponent);

	MemoryEchoAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("MemoryEchoAudio"));
	MemoryEchoAudio->SetupAttachment(RootComponent);
	MemoryEchoAudio->bAutoActivate = true;

	bHarvested = false;
}

void AAshenMemoryImprintAnchorActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenMemoryImprintAnchorActor::InitializeMemoryAnchor(const FMemoryImprintPayload& Payload)
{
	AnchoredPayload = Payload;
	bHarvested = false;
}

bool AAshenMemoryImprintAnchorActor::InspectMemoryAnchor(FMemoryImprintPayload& OutImprint)
{
	if (bHarvested)
	{
		return false;
	}

	OutImprint = AnchoredPayload;
	bHarvested = true;

	if (MemoryEchoAudio && MemoryEchoAudio->IsPlaying())
	{
		MemoryEchoAudio->FadeOut(1.0f, 0.0f);
	}

	return true;
}
