// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenPurpleMistVolumeActor.h"
#include "Components/BoxComponent.h"

AAshenPurpleMistVolumeActor::AAshenPurpleMistVolumeActor()
{
	PrimaryActorTick.bCanEverTick = false;

	VolumeBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("VolumeBounds"));
	RootComponent = VolumeBounds;
	VolumeBounds->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	CurrentMistDensity = 0.50f;
}

void AAshenPurpleMistVolumeActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenPurpleMistVolumeActor::SetMistDensity(float NewDensity)
{
	CurrentMistDensity = FMath::Clamp(NewDensity, 0.0f, 1.0f);
}
