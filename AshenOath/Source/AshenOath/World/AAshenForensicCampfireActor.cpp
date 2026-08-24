// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenForensicCampfireActor.h"
#include "Components/SphereComponent.h"

AAshenForensicCampfireActor::AAshenForensicCampfireActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	WarmthZone = CreateDefaultSubobject<USphereComponent>(TEXT("WarmthZone"));
	WarmthZone->SetupAttachment(RootComponent);
	WarmthZone->SetSphereRadius(600.0f);

	CampfireWarmthRadiusUU = 600.0f;
}

void AAshenForensicCampfireActor::BeginPlay()
{
	Super::BeginPlay();
}
