// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenWeatherShelterVolumeWorldActor.h"

AAshenWeatherShelterVolumeWorldActor::AAshenWeatherShelterVolumeWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	ShelterType = EWeatherShelterType::CavernOverhang;
	ShelterRadiusUU = 600.0f;
}

void AAshenWeatherShelterVolumeWorldActor::BeginPlay()
{
	Super::BeginPlay();
}
