// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenFinisherImpactVFXAnchorActor.h"

AAshenFinisherImpactVFXAnchorActor::AAshenFinisherImpactVFXAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenFinisherImpactVFXAnchorActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenFinisherImpactVFXAnchorActor: Finisher impact VFX anchor active."));
}

void AAshenFinisherImpactVFXAnchorActor::TriggerFinisherImpactVFX(uint8 StanceEnum)
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenFinisherImpactVFXAnchorActor: Stance-colored impact VFX burst triggered for stance %d!"), StanceEnum);
}
