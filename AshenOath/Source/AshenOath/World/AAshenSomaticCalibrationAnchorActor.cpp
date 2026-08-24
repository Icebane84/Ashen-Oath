// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenSomaticCalibrationAnchorActor.h"
#include "Components/SphereComponent.h"

AAshenSomaticCalibrationAnchorActor::AAshenSomaticCalibrationAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	ZoneSphere = CreateDefaultSubobject<USphereComponent>(TEXT("ZoneSphere"));
	ZoneSphere->SetupAttachment(RootComponent);
	ZoneSphere->SetSphereRadius(1200.0f);
	ZoneSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	AmbientSootRateMultiplier = 1.5f;
}

void AAshenSomaticCalibrationAnchorActor::BeginPlay()
{
	Super::BeginPlay();
}
