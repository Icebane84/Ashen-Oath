// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenPhysicalizedDebrisRubbleActor.h"
#include "Components/BoxComponent.h"

AAshenPhysicalizedDebrisRubbleActor::AAshenPhysicalizedDebrisRubbleActor()
{
	PrimaryActorTick.bCanEverTick = false;

	RubbleBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("RubbleBounds"));
	RootComponent = RubbleBounds;
	RubbleBounds->SetCollisionProfileName(TEXT("BlockAll"));

	RubbleVolumeFootprint = 75000.0f;
}

void AAshenPhysicalizedDebrisRubbleActor::BeginPlay()
{
	Super::BeginPlay();
}
