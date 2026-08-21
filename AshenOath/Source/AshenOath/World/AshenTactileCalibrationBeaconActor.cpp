// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenTactileCalibrationBeaconActor.h"
#include "Components/StaticMeshComponent.h"

AAshenTactileCalibrationBeaconActor::AAshenTactileCalibrationBeaconActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	BeaconMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BeaconMesh"));
	BeaconMesh->SetupAttachment(RootComponent);
	BeaconMesh->SetCollisionProfileName(TEXT("BlockAll"));

	bBeaconActive = true;
}

void AAshenTactileCalibrationBeaconActor::BeginPlay()
{
	Super::BeginPlay();
	bBeaconActive = true;
}

void AAshenTactileCalibrationBeaconActor::TriggerCalibrationBurst(bool bTestLeftTrigger)
{
	bBeaconActive = true;
}
