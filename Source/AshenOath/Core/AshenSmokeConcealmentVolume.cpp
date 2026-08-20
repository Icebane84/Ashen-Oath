// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenSmokeConcealmentVolume.h"
#include "Components/BoxComponent.h"
#include "AshenOath_ThreatPerceptionComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"

AAshenSmokeConcealmentVolume::AAshenSmokeConcealmentVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	SmokeVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SmokeVolume"));
	RootComponent = SmokeVolume;
	SmokeVolume->SetBoxExtent(FVector(300.0f, 300.0f, 150.0f));
	SmokeVolume->SetCollisionProfileName(TEXT("Trigger"));

	Duration = 10.0f;
}

void AAshenSmokeConcealmentVolume::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(ExpirationTimerHandle, this, &AAshenSmokeConcealmentVolume::ExpireVolume, Duration, false);
	}
}

void AAshenSmokeConcealmentVolume::ExpireVolume()
{
	OnVolumeExpired.Broadcast();
	UE_LOG(LogTemp, Log, TEXT("AAshenSmokeConcealmentVolume: Smoke screen expired and cleared."));
	Destroy();
}
