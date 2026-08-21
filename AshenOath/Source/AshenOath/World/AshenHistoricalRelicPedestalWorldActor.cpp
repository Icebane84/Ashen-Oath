// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenHistoricalRelicPedestalWorldActor.h"
#include "Components/StaticMeshComponent.h"

AAshenHistoricalRelicPedestalWorldActor::AAshenHistoricalRelicPedestalWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	PedestalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PedestalMesh"));
	PedestalMesh->SetupAttachment(RootComponent);
	PedestalMesh->SetCollisionProfileName(TEXT("BlockAll"));

	RelicMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RelicMesh"));
	RelicMesh->SetupAttachment(PedestalMesh);
	RelicMesh->SetCollisionProfileName(TEXT("NoCollision"));

	RelicId = FName(TEXT("Relic_Pyre_Censer"));
	bIsInspected = false;
}

void AAshenHistoricalRelicPedestalWorldActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenHistoricalRelicPedestalWorldActor::InspectRelic()
{
	bIsInspected = true;
}
