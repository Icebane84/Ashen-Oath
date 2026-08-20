// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenRuptureScarAnchorActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"

AAshenRuptureScarAnchorActor::AAshenRuptureScarAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	PerceptionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("PerceptionSphere"));
	PerceptionSphere->SetupAttachment(RootComponent);
	PerceptionSphere->SetSphereRadius(350.0f);

	ScarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ScarMesh"));
	ScarMesh->SetupAttachment(RootComponent);

	AmbientResonanceAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("AmbientResonanceAudio"));
	AmbientResonanceAudio->SetupAttachment(RootComponent);
	AmbientResonanceAudio->bAutoActivate = true;

	AssociatedCompanion = FName(TEXT("Garrett"));
	CurrentState = ERelationalRuptureState::ActiveRupture;
}

void AAshenRuptureScarAnchorActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenRuptureScarAnchorActor::InitializeScarAnchor(
	FName CompanionName,
	ERelationalRuptureState InitialState,
	const FText& MemorialText)
{
	AssociatedCompanion = CompanionName;
	CurrentState = InitialState;
	HistoricalMemorialText = MemorialText;
	UpdateRuptureState(InitialState);
}

void AAshenRuptureScarAnchorActor::UpdateRuptureState(ERelationalRuptureState NewState)
{
	CurrentState = NewState;
	if (AmbientResonanceAudio)
	{
		if (NewState == ERelationalRuptureState::RememberedReconciliation)
		{
			AmbientResonanceAudio->SetPitchMultiplier(1.20f);
		}
		else if (NewState == ERelationalRuptureState::ActiveRupture)
		{
			AmbientResonanceAudio->SetPitchMultiplier(0.80f);
		}
		else
		{
			AmbientResonanceAudio->SetPitchMultiplier(1.0f);
		}
	}
}
