// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSomaticIdentityEchoVolume.h"

AAshenSomaticIdentityEchoVolume::AAshenSomaticIdentityEchoVolume()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSomaticIdentityEchoVolume::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSomaticIdentityEchoVolume: Somatic Identity Echo Volume initialized (Intensity: %f)."), IdentityEchoIntensity);
}

void AAshenSomaticIdentityEchoVolume::ApplyIdentityEchoToActor(AActor* TargetActor)
{
	if (!TargetActor) return;
	UE_LOG(LogTemp, Log, TEXT("AAshenSomaticIdentityEchoVolume: Applied somatic identity echo to %s"), *TargetActor->GetName());
}
