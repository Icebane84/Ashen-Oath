// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenZenithApexAltarActor.h"
#include "Components/BoxComponent.h"

AAshenZenithApexAltarActor::AAshenZenithApexAltarActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	AltarBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("AltarBounds"));
	AltarBounds->SetupAttachment(RootComponent);
	AltarBounds->SetBoxExtent(FVector(1500.0f, 1500.0f, 200.0f));

	AltarRadiusUU = 1500.0f;
}

void AAshenZenithApexAltarActor::BeginPlay()
{
	Super::BeginPlay();
}
