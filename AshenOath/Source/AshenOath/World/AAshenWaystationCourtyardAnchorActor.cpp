// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenWaystationCourtyardAnchorActor.h"
#include "Components/BoxComponent.h"

AAshenWaystationCourtyardAnchorActor::AAshenWaystationCourtyardAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	CourtyardBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("CourtyardBounds"));
	RootComponent = CourtyardBounds;
	CourtyardBounds->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	CourtyardRadiusCentimeters = 1500.0f;
}

void AAshenWaystationCourtyardAnchorActor::BeginPlay()
{
	Super::BeginPlay();
}
