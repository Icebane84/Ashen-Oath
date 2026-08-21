// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenCampfireHearthAnchorActor.h"
#include "Components/SphereComponent.h"

AAshenCampfireHearthAnchorActor::AAshenCampfireHearthAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	WarmthRadius = CreateDefaultSubobject<USphereComponent>(TEXT("WarmthRadius"));
	WarmthRadius->SetupAttachment(RootComponent);
	WarmthRadius->SetSphereRadius(800.0f);

	bHearthLit = false;
}

void AAshenCampfireHearthAnchorActor::BeginPlay()
{
	Super::BeginPlay();
	bHearthLit = false;
}

void AAshenCampfireHearthAnchorActor::IgniteHearth()
{
	bHearthLit = true;
}
