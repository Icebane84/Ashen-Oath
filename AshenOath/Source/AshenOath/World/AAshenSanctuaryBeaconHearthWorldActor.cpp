// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenSanctuaryBeaconHearthWorldActor.h"
#include "World/AshenSanctuarySurvivalConvergenceSubsystem.h"
#include "Engine/World.h"

AAshenSanctuaryBeaconHearthWorldActor::AAshenSanctuaryBeaconHearthWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	BeaconId = TEXT("Beacon_Gloomwood_01");
	RegionName = TEXT("Gloomwood Spires");
	bIsIgnited = false;
}

void AAshenSanctuaryBeaconHearthWorldActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenSanctuaryBeaconHearthWorldActor::IgniteBeacon()
{
	if (!bIsIgnited)
	{
		bIsIgnited = true;

		if (UWorld* World = GetWorld())
		{
			if (UAshenSanctuarySurvivalConvergenceSubsystem* Subsystem = World->GetSubsystem<UAshenSanctuarySurvivalConvergenceSubsystem>())
			{
				const FText Inscription = FText::FromString(FString::Printf(
					TEXT("Sanctuary Hearth ignited at %s. The ancient runes dispel the bitter freeze."),
					*RegionName));

				Subsystem->IgniteBeacon(BeaconId, RegionName, Inscription);
			}
		}
	}
}
