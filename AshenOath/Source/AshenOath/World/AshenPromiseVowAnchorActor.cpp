// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenPromiseVowAnchorActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

AAshenPromiseVowAnchorActor::AAshenPromiseVowAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	VowRadius = CreateDefaultSubobject<USphereComponent>(TEXT("VowRadius"));
	VowRadius->SetupAttachment(RootComponent);
	VowRadius->SetSphereRadius(350.0f);

	ShrineMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShrineMesh"));
	ShrineMesh->SetupAttachment(RootComponent);

	AssociatedCompanionName = FName(TEXT("Garrett"));
	bIsHonored = false;
}

void AAshenPromiseVowAnchorActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenPromiseVowAnchorActor::HonorVowAtAnchor()
{
	bIsHonored = true;
}
