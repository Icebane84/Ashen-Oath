// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenSanctuaryBeaconWorldActor.h"

AAshenSanctuaryBeaconWorldActor::AAshenSanctuaryBeaconWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	BeaconId = TEXT("Waypoint_Hearth_01");
	BeaconState = EWaypointBeaconState::UndiscoveredShadow;
}

void AAshenSanctuaryBeaconWorldActor::BeginPlay()
{
	Super::BeginPlay();
}
