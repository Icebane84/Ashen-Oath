// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenTripartiteSanctuaryAnchorActor.h"
#include "Components/SphereComponent.h"

AAshenTripartiteSanctuaryAnchorActor::AAshenTripartiteSanctuaryAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	SanctuaryBounds = CreateDefaultSubobject<USphereComponent>(TEXT("SanctuaryBounds"));
	SanctuaryBounds->SetupAttachment(RootComponent);
	SanctuaryBounds->SetSphereRadius(1500.0f);
	SanctuaryBounds->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	DesignatedMode = ETripartiteBehaviorMode::ContemplativeSilence;
}

void AAshenTripartiteSanctuaryAnchorActor::BeginPlay()
{
	Super::BeginPlay();
}
