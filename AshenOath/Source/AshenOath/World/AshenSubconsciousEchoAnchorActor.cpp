// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenSubconsciousEchoAnchorActor.h"
#include "Components/SphereComponent.h"
#include "Components/AudioComponent.h"

AAshenSubconsciousEchoAnchorActor::AAshenSubconsciousEchoAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	TriggerPerimeter = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerPerimeter"));
	TriggerPerimeter->SetupAttachment(RootComponent);
	TriggerPerimeter->SetSphereRadius(300.0f);

	WhisperSpatialAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("WhisperSpatialAudio"));
	WhisperSpatialAudio->SetupAttachment(RootComponent);
	WhisperSpatialAudio->bAutoActivate = false;

	bEchoTriggered = false;
	AssociatedMemoryEchoId = TEXT("mem_echo_001");
	TargetChannel = EVoiceChannel::ShadowSelf;
}

void AAshenSubconsciousEchoAnchorActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenSubconsciousEchoAnchorActor::TriggerSubconsciousEcho()
{
	if (bEchoTriggered)
	{
		return;
	}

	bEchoTriggered = true;
	if (WhisperSpatialAudio)
	{
		WhisperSpatialAudio->Play();
	}
}
