// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSomaticPostureTouchstoneActor.h"

AAshenSomaticPostureTouchstoneActor::AAshenSomaticPostureTouchstoneActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSomaticPostureTouchstoneActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSomaticPostureTouchstoneActor: Somatic Posture Touchstone Actor initialized."));
}

bool AAshenSomaticPostureTouchstoneActor::ActivatePostureTouchstone()
{
	if (!bPostureTouchstoneActive) return false;
	UE_LOG(LogTemp, Log, TEXT("AAshenSomaticPostureTouchstoneActor: Posture touchstone activated (Stabilization radius: %f)."), PostureStabilizationRadius);
	return true;
}
