// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSomaticIdentityTouchstoneActor.h"

AAshenSomaticIdentityTouchstoneActor::AAshenSomaticIdentityTouchstoneActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSomaticIdentityTouchstoneActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSomaticIdentityTouchstoneActor: Somatic Identity Touchstone Actor initialized."));
}

bool AAshenSomaticIdentityTouchstoneActor::ActivateIdentityTouchstone()
{
	if (!bTouchstoneActive) return false;
	UE_LOG(LogTemp, Log, TEXT("AAshenSomaticIdentityTouchstoneActor: Somatic identity touchstone activated (Radius: %f)."), StabilizationRadius);
	return true;
}
