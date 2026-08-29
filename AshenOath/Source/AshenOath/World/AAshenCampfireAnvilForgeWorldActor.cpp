// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenCampfireAnvilForgeWorldActor.h"
#include "Combat/AshenRunicForgeConvergenceSubsystem.h"
#include "Engine/World.h"

AAshenCampfireAnvilForgeWorldActor::AAshenCampfireAnvilForgeWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	bAnvilActive = true;
}

void AAshenCampfireAnvilForgeWorldActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenCampfireAnvilForgeWorldActor::InteractWithAnvil()
{
	// Opens Runic Forge UI & notifies companion
}
