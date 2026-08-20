// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenCampfireRestAreaActor.h"

AAshenCampfireRestAreaActor::AAshenCampfireRestAreaActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenCampfireRestAreaActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenCampfireRestAreaActor: Campfire rest area actor initialized in world."));
}

void AAshenCampfireRestAreaActor::KindleCampfire()
{
	CurrentState = EAshenCampfireRestState::Kindled;
	if (OnCampfireStateChanged.IsBound())
	{
		OnCampfireStateChanged.Broadcast(CurrentState);
	}
	UE_LOG(LogTemp, Warning, TEXT("AAshenCampfireRestAreaActor: Campfire KINDLED! Safe sanctuary active within %.0fuu radius."), RestWarmthRadius);
}

void AAshenCampfireRestAreaActor::TriggerCampfireRest(AActor* InteractingCharacter)
{
	if (CurrentState == EAshenCampfireRestState::Cold)
	{
		KindleCampfire();
	}

	CurrentState = EAshenCampfireRestState::Resonating;
	if (OnCampfireRestTriggered.IsBound())
	{
		OnCampfireRestTriggered.Broadcast(InteractingCharacter, 1.0f);
	}
	UE_LOG(LogTemp, Warning, TEXT("AAshenCampfireRestAreaActor: Rest sequence started for %s! Identity compilation and party dialogue ready."),
		InteractingCharacter ? *InteractingCharacter->GetName() : TEXT("Party"));
}

void AAshenCampfireRestAreaActor::ExtinguishCampfire()
{
	CurrentState = EAshenCampfireRestState::Extinguished;
	if (OnCampfireStateChanged.IsBound())
	{
		OnCampfireStateChanged.Broadcast(CurrentState);
	}
	UE_LOG(LogTemp, Log, TEXT("AAshenCampfireRestAreaActor: Campfire extinguished. Resuming borderland exploration."));
}
