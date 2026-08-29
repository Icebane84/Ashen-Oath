// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenMemoryAnomalyCrucibleWorldActor.h"

AAshenMemoryAnomalyCrucibleWorldActor::AAshenMemoryAnomalyCrucibleWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	AssociatedContractId = TEXT("Contract_Anomaly_01");
	AnomalyRadiusUU = 800.0f;
}

void AAshenMemoryAnomalyCrucibleWorldActor::BeginPlay()
{
	Super::BeginPlay();
}
