// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenSanctifiedHearthBrazierActor.h"
#include "Components/SphereComponent.h"
#include "Components/PointLightComponent.h"

AAshenSanctifiedHearthBrazierActor::AAshenSanctifiedHearthBrazierActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	BrazierMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BrazierMesh"));
	BrazierMesh->SetupAttachment(RootComponent);

	SanctuaryWarmthZone = CreateDefaultSubobject<USphereComponent>(TEXT("SanctuaryWarmthZone"));
	SanctuaryWarmthZone->SetupAttachment(RootComponent);
	SanctuaryWarmthZone->SetSphereRadius(500.0f);
	SanctuaryWarmthZone->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	HearthLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("HearthLight"));
	HearthLight->SetupAttachment(RootComponent);
	HearthLight->SetIntensity(0.0f);
	HearthLight->SetLightColor(FLinearColor(1.0f, 0.55f, 0.2f));

	CurrentIgnitionProgress = 0.0f;
}

void AAshenSanctifiedHearthBrazierActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenSanctifiedHearthBrazierActor::SetIgnitionVisuals(float Progress, EHearthSanctuaryState State)
{
	CurrentIgnitionProgress = FMath::Clamp(Progress, 0.0f, 1.0f);

	if (SanctuaryWarmthZone)
	{
		SanctuaryWarmthZone->SetSphereRadius(500.0f + (CurrentIgnitionProgress * 2000.0f));
	}

	if (HearthLight)
	{
		HearthLight->SetIntensity(CurrentIgnitionProgress * 8000.0f);
	}
}
