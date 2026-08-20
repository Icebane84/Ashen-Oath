// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenWhiteFlameEyeFlareVFXAnchorActor.h"

AAshenWhiteFlameEyeFlareVFXAnchorActor::AAshenWhiteFlameEyeFlareVFXAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenWhiteFlameEyeFlareVFXAnchorActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenWhiteFlameEyeFlareVFXAnchorActor: Eye flare VFX anchor active."));
}

void AAshenWhiteFlameEyeFlareVFXAnchorActor::TriggerEyeFlareVFX()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenWhiteFlameEyeFlareVFXAnchorActor: White flame eye flare VFX burst triggered!"));
}
