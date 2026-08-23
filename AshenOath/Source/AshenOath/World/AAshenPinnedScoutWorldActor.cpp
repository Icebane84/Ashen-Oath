// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenPinnedScoutWorldActor.h"
#include "Components/SphereComponent.h"

AAshenPinnedScoutWorldActor::AAshenPinnedScoutWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
	InteractionSphere->SetupAttachment(RootComponent);
	InteractionSphere->SetSphereRadius(200.0f);
	InteractionSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	CurrentStatus = EScoutCatalystDecision::HarvestResidualTaint;
}

void AAshenPinnedScoutWorldActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenPinnedScoutWorldActor::ApplyCatalystDecision(EScoutCatalystDecision Decision)
{
	CurrentStatus = Decision;
}
