// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenWhiteFlameBurstVFXAnchorActor.h"

AAshenWhiteFlameBurstVFXAnchorActor::AAshenWhiteFlameBurstVFXAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenWhiteFlameBurstVFXAnchorActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenWhiteFlameBurstVFXAnchorActor: Burst VFX anchor active."));
}

void AAshenWhiteFlameBurstVFXAnchorActor::TriggerBurstVFX()
{
	TriggerWhiteFlameBurstVFX(1.0f);
}

void AAshenWhiteFlameBurstVFXAnchorActor::TriggerWhiteFlameBurstVFX(float Intensity)
{
	bIsBurstActive = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenWhiteFlameBurstVFXAnchorActor: Explosive white flame burst VFX executed at intensity %.2f!"), Intensity);
}
